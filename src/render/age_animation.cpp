#include <../include/age_animation.h>
#include <qdebug.h>
namespace AGE2D
{
AAnimation::AAnimation(QString name)
{
	this->name=name;
    //qDebug()<<"the animation name is "<<name;
}

void AAnimation::addFrame(AFrame frame)
{
	this->m_list.push_back (frame);
    //qDebug()<<"new frame is add to "<<name<<"bottom left"<<frame.bottomLeft ()<<"top right"<<frame.topRight ();
}

QString AAnimation::getName()
{
	return name;
}

int AAnimation::totalFrames()
{
	return this->m_list.size ();
}

AFrame AAnimation::getFrame(int index)
{
	return this->m_list[index];
}
}

