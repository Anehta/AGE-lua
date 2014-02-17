#include <../include/AGE2D.h>
#include <../include/age_texture.h>

#include <QDebug>

ATexture2D::ATexture2D()
{
}

ATexture2D::ATexture2D(QString filename)
{
    loadFile(filename);
}

void ATexture2D::loadFile(QString filename)
{
    initializeGLFunctions();
    m_fileName = filename;
    bindTexture();
}

GLuint ATexture2D::getTextureId()
{
    return m_texID;
}

void ATexture2D::bindTexture()
{
    QImage timage,buf;
    if(!buf.load(m_fileName))
    {
        qWarning("Could not read image file,using single-color instead");
        QImage dummy(128,128,QImage::Format_RGB32);
        buf = dummy;
    }

    timage = QGLWidget::convertToGLFormat(buf);
    m_width = timage.width();
    m_height = timage.height();

    glGenTextures(1, &m_texID);
    //qDebug()<<"m_texID="<<m_texID;
    glBindTexture(GL_TEXTURE_2D, m_texID);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,timage.width(),timage.height(),0,
            GL_RGBA,GL_UNSIGNED_BYTE,timage.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

#ifdef GL_ES
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER_NV);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER_NV);
#elseif
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
#endif
    float color[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
#ifdef GL_ES
    glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR_NV, color);
#elseif
    glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
#endif

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    //delete(&timage);
    //delete(&buf);
}

int ATexture2D::width()
{
    return m_width;
}

int ATexture2D::height()
{
    return m_height;
}
