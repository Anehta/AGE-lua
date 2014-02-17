#include "../include/age_system.h"
#include "../include/age_staticattribute.h"
#include "../include/age_widget.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
namespace AGE2D{
QApplication * ASystem::m_application;
AWidget * ASystem::m_widget;
int ASystem::m_width;
int ASystem::m_height;
int ASystem::m_widthOffset;
int ASystem::m_heightOffset;
bool ASystem::is_init=false;

ASystem::ASystem()
{
}

int ASystem::Go()
{
	if(!is_init)
	{
		return -1;
	}
	return m_application->exec ();
}

void ASystem::SetSize(int width, int height )
{

	m_width=width;
	m_height=height;
	if(!is_init)
	{
		return ;
	}
    m_widget->resize(width,height);
    m_widget->updateWindow(width,height);
    qDebug()<<"dingdong"<<width<<"   "<<height;
}

int ASystem::Random(int min, int max)
{
 return (min + rand()% (max-min+1));
}

int ASystem::GetWidth()
{
	return m_width;
}

int ASystem::GetHeight()
{
	return m_height;
}

int ASystem::GetWidthOffset()
{
    return m_widthOffset;
}

int ASystem::GetHeightOffset()
{
    return m_heightOffset;
}

int ASystem::IsEngineInitialized()
{
	return is_init;
}

void ASystem::Init(int argc, char *argv[])
{
	m_application=new QApplication(argc,argv);
    is_init=true;
	m_widget=new AWidget();
	SetSize(640,480);
	m_widget->show();

}

int ASystem::TimeStep()
{
	return getTimeStep();
}

double ASystem::FrameRate()
{
	return 1000.0/getTimeStep ();
}

AWidget * ASystem::GetWidget()
{
    return m_widget;
}
}



