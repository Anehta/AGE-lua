#include <../include/age_shaderprogram.h>
#include <qdebug.h>

namespace AGE2D
{
AShaderProgram::AShaderProgram()
{

}

AShaderProgram::AShaderProgram(QString vshaderFilename, QString fshaderFilename)
{
    addVertexShader(vshaderFilename);
    addVertexShader(fshaderFilename);

    if(!link())
    {
	qDebug()<<"error in shader link";
    }

}
bool AShaderProgram::addVertexShader(QString vshaderFilename)
{
    if(!addShaderFromSourceFile(QGLShader::Vertex,vshaderFilename))
    {
	qDebug()<<"error in addShaderFromSourceFile():QGLShader::Vertex";
	return false;
    }
    return true;
}


bool AShaderProgram::addFragmentShader(QString fshaderFilename)
{
    if(!addShaderFromSourceFile(QGLShader::Fragment,fshaderFilename))
    {
	qDebug()<<"error in addShaderFromSourceFile()::QGLShader::Fragment";
	return false;
    }
    return true;

}

void AShaderProgram::initShaderEffect(int)
{

}
}

