#include <../include/age_widget.h>
#include <../include/age_staticattribute.h>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QKeyEvent>
#include <list>
#include <../include/age_mouseinfo.h>
//#include <iostream>
#include <QElapsedTimer>
#include <QFont>
#include <QDebug>

using namespace std;

namespace AGE2D
{
AWidget::AWidget(QWidget *)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer))
{
    //setFixedSize(640,480);
    scale_factor=1;
    screen_offset_x=0;
    screen_offset_y=0;
}

AWidget::~AWidget()
{

}

void AWidget::initializeGL()
{
    setCurrentScene(NULL);
    initializeGLFunctions();

    qglClearColor(Qt::black);

    //glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initDefalutShaderProgram();
    initResources();
    m_timer.start(15, this);
}

void AWidget::resizeGL(int w, int h)
{
    updateWindow(w,h);
}

void AWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //setViewPortMatrix(projection);
    display();

}

void AWidget::timerEvent(QTimerEvent *)
{
    QElapsedTimer timer;
    timer.start();
    updateGL();
    setTimeStep(timer.elapsed()+15);
}

void AWidget::display()
{
    AScene * temp = getCurrentScene();

    if(temp != NULL)
    {
    temp->renderScene(is_release,is_press,mouse_pos);
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->run();
	}
    }
    is_release=false;
    is_press=false;

}

void AWidget::initResources()
{

}

void AWidget::mouseMoveEvent(QMouseEvent * mouse)
{
    this->setMouseTracking(true);
    AScene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
        AMouseInfo a=temp->m_listenerManager->mouseMoveEvent(mouse);
        mouse_pos.setX(a.getMouseX());
        mouse_pos.setY(a.getMouseY());
	}
    }

}

void AWidget::mousePressEvent(QMouseEvent *mouse)
{
    is_press=true;
    AScene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
        AMouseInfo a=temp->m_listenerManager->mousePressEvent(mouse);

        mouse_pos.setX(a.getMouseX());
        mouse_pos.setY(a.getMouseY());
	}

    }
}

void AWidget::mouseReleaseEvent(QMouseEvent *mouse)
{
    is_release=true;
    AScene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
        AMouseInfo a=temp->m_listenerManager->mouseReleaseEvent(mouse);
        mouse_pos.setX(a.getMouseX());
        mouse_pos.setY(a.getMouseY());
	}

    }
}





void AWidget::mouseDoubleClickEvent(QMouseEvent *mouse)
{
    setCurrentMouseEvent(mouse);

}

void AWidget::keyReleaseEvent(QKeyEvent *event)
{
	AScene * temp = getCurrentScene();
	if(temp != NULL)
	{
	    if(temp->m_listenerManager != NULL)
	    {
		temp->m_listenerManager->keyReleaseEvent (event);
	    }

	}
}

void AWidget::keyPressEvent(QKeyEvent *event)
{
	AScene * temp = getCurrentScene();
	if(temp != NULL)
	{
	    if(temp->m_listenerManager != NULL)
	    {
		temp->m_listenerManager->keyPressEvent (event);
	    }
	}
}
int AWidget::getReal_height() const
{
    return real_height;
}

void AWidget::setReal_height(int value)
{
    real_height = value;
}

void AWidget::updateWindow(int w, int h)
{

     screen_offset_x=0;
     screen_offset_y=0;
    scale_factor=w*1.0/ASystem::GetWidth();
    if(ASystem::GetHeight()*scale_factor>h)
    {
        scale_factor=h*1.0/ASystem::GetHeight();
    }
    screen_offset_x=(w-ASystem::GetWidth()*scale_factor)/2;
    screen_offset_y=(h-ASystem::GetHeight()*scale_factor)/2;
     int wi = ASystem::GetWidth()*scale_factor, he = ASystem::GetHeight()*scale_factor;
     qDebug()<<"weight:"<<wi<<"height:"<<he<<"offset_x"<<screen_offset_x<<"offset_y"<<screen_offset_y;
    glViewport(screen_offset_x,screen_offset_y,wi,he);
    real_width=w;
    real_height=h;
    projection.setToIdentity();


    projection.frustum (0,ASystem::GetWidth(),0,ASystem::GetHeight(),0.01,50);

    ASystem::m_widthOffset = w-wi;
    ASystem::m_heightOffset = h-he;
    setViewPortMatrix(projection);
}

int AWidget::getReal_width() const
{
    return real_width;
}

void AWidget::setReal_width(int value)
{
    real_width = value;
}

int AWidget::getScreenOffsetY() const
{
    return screen_offset_y;
}

void AWidget::setScreenOffsetY(int value)
{
    screen_offset_y = value;
}

int AWidget::getScreenOffsetX() const
{
    return screen_offset_x;
}

void AWidget::setScreenOffsetX(int value)
{
    screen_offset_x = value;
}

double AWidget::getScaleFactor() const
{
    return scale_factor;
}

void AWidget::setScaleFactor(double value)
{
    scale_factor = value;
}

}

