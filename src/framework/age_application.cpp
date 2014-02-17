#include <../include/age_widget.h>
#include "../include/age_application.h"

#include <QApplication>
namespace AGE2D
{
QApplication * AApplication::m_application;
AWidget * AApplication::m_widiget;
int AApplication::m_width;
int AApplication::m_height;
bool AApplication::is_init=false;
AApplication::AApplication()
{
}

int AApplication::Go()
{
    if(!is_init)
    {
	return -1;
    }
    return m_application->exec ();
}

void AApplication::SetSize(int width, int height )
{
    if(!is_init)
    {
	return ;
    }
    m_width=width;
    m_height=height;
    m_widiget->setFixedSize (width,height);
}

int AApplication::IsEngineInitialized()
{
    return is_init;
}

void AApplication::Init(int argc, char *argv[])
{
    m_application=new QApplication(argc,argv);
    m_widiget=new AWidget();
    m_widiget->show();
    is_init=true;
}
}

