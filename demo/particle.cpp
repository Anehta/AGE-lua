#include "particle.h"



Particle::Particle(ATexture * texture, double begin_angle,AVector2D pos, AVector2D begin_size,
                   AVector2D end_size, AColor begin_color, AColor end_color,
                   double escape_speed,double angle_speed, int span,float begin_alpha,float end_alpha,double rotate_speed
                   ,AVector2D gravity,int delay)


{
    this->bindTexture(texture);
    this->setPos(pos);
    this->setWidth(begin_size.x());
    this->setHeight(begin_size.y());
    this->setColor(begin_color.red,begin_color.green,begin_color.blue);
    this->span=span;
    //宽度变化率
    if((end_size.x()-begin_size.x())!=0)
    {
        width_change_rate=(end_size.x()-begin_size.x())/span;
    }
    else
    {
        width_change_rate=0;
    }

    //高度变化率
    if((end_size.y()-begin_size.y())!=0)
    {
        height_change_rate=(end_size.y()-begin_size.y())/span;
    }
    else
    {
        height_change_rate=0;
    }
    //红色分量变化率
    if((end_color.red-begin_color.red)!=0)
    {
        red_change_rate=(end_color.red-begin_color.red)/span;
    }else
    {
       red_change_rate=0;
    }
    //绿色分量变化率
    if((end_color.green-begin_color.green)!=0)
    {
        green_change_rate=(end_color.green-begin_color.green)/span;
    }else
    {
        green_change_rate=0;
    }
    //蓝色分量变化率
    if((end_color.blue-begin_color.blue)!=0)
    {
        blue_change_rate=(end_color.blue-begin_color.blue)/span;
    }
    else
    {
        blue_change_rate=0;
    }
    this->setAlpha(begin_alpha);
    if((end_alpha-begin_alpha)!=0)
    {
        alpha_change_rate=(end_alpha-begin_alpha)/span;
    }
    else
    {
        alpha_change_rate=0;
    }
    this->angle=0;
    this->escape_speed=escape_speed;
    this->angle_speed=angle_speed;
    this->begin_angle=begin_angle;
    acc=new AAccumulator(0,this->span,1,false);
    this->init_pos=pos;
    this->rotate_speed=rotate_speed;
     this->gravity=gravity;
    this->m_delay = delay;
}

/*
物体做阿基米德螺线运动
r=v1*t+r0
x=r*cos(v2*t+θ)+x0
y=r*sin(v2*t+θ)+y0

*/
void Particle::action()
{
    if(m_delay==0)
    {
        m_delay = 1;
    }
    acc->step(ASystem::TimeStep()/m_delay);
    //运动
    double r= escape_speed*acc->currentValue();
    double x=r*cos(angle_speed*acc->currentValue() +this->begin_angle*PI/180)+this->init_pos.x();
    double y=r*sin(angle_speed*acc->currentValue() +this->begin_angle*PI/180)+this->init_pos.y();
    x+=gravity.x()*acc->currentValue();
    y+=gravity.y()*acc->currentValue();
    this->setPos(AVector2D(x,y));

    //尺寸变化
    if(this->width() >= 0 && this->height() >= 0)
    {
        this->setWidth(this->width()+width_change_rate*ASystem::TimeStep()/m_delay);
        this->setHeight(this->height()+height_change_rate*ASystem::TimeStep()/m_delay);
    }


    //颜色变化
    AColor current_color=this->getColor();
    this->setColor(current_color.red+red_change_rate*ASystem::TimeStep()/m_delay,
                   current_color.green+green_change_rate*ASystem::TimeStep()/m_delay,
                   current_color.blue+blue_change_rate*ASystem::TimeStep()/m_delay
                   );

    //不透明度变化
    this->setAlpha(this->getAlpha()+alpha_change_rate*ASystem::TimeStep()/m_delay);
    this->setPivotOffset(this->width()/2,this->height()/2);
    angle+=rotate_speed*ASystem::TimeStep()/m_delay;
    this->rotate(angle);

    //销毁
    if(acc->isTouched())
    {
        this->destroy();
        delete acc;
    }
}
