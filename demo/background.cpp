#include "background.h"
#include "game.h"

BackGround::BackGround()
{
}

BackGround::BackGround(ATexture * tex)
{
    bindTexture(tex);
}

void BackGround::shaderAction()
{

    t+=0.07416/2+ts;

    if(up)
    {
        ts+=0.01;
    }
    if(down)
    {
        ts-=0.01;
    }

    if(z)
    {
        as += 0.005;
    }
    if(x)
    {
        as -= 0.005;
    }
    float dividerValue = 1,frequency = 11.0,qtOpacity=1.0;
    this->getShaderProgram()->setUniformValue("dividerValue",dividerValue);
    this->getShaderProgram()->setUniformValue("frequency",frequency);
    this->getShaderProgram()->setUniformValue("qt_Opacity",qtOpacity);
    this->getShaderProgram()->setUniformValue("time",t);
    this->getShaderProgram()->setUniformValue("amplitude",a+as);
}

void BackGround::onKeyPress(QKeyEvent *event)
{
    switch(event->key ())
    {
    case Qt::Key_A:
         up=true;
         break;
    case Qt::Key_S:
         down=true;
         break;
    case Qt::Key_Q:
         z = true;
         break;
    case Qt::Key_W:
         x = true;
         break;
    }
}

void BackGround::onKeyRelease(QKeyEvent *event)
{

    switch(event->key ())
    {
    case Qt::Key_A:
         up=false;
         break;
    case Qt::Key_S:
         down=false;
         break;
    case Qt::Key_Q:
         z = false;
         break;
    case Qt::Key_W:
         x = false;
         break;
    }
}
