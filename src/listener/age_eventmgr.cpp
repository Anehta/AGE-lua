#include "../include/age_eventmgr.h"
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
using namespace std;

namespace  AGE2D {
AEventMgr::AEventMgr()
{

}

void AEventMgr::addListener(ABaseListener * baseListener)
{
    ABaseListener* p =dynamic_cast<ABaseListener*>(baseListener);
    if(p != NULL)
	listenerList.push_back(p);
    qDebug()<<"addListener";
}

void AEventMgr::addFrameListener(AFrameListener *a)
{
	AFrameListener* p =dynamic_cast<AFrameListener*>(a);
	if(p != NULL)
		m_frame_listener_list.push_back(p);
}

void AEventMgr::addMouseListener(AMouseListener *a)
{
	AMouseListener* p =dynamic_cast<AMouseListener*>(a);
	if(p != NULL)
		m_mouse_listener_list.push_back(p);


}

void AEventMgr::addKeyListener(AKeyListener *a)
{
	AKeyListener* p =dynamic_cast<AKeyListener*>(a);
	if(p != NULL)
		m_key_listener_list.push_back(p);
}



void AEventMgr::run()
{
    for(list<ABaseListener *>::iterator alpha_it = listenerList.begin();
	alpha_it != listenerList.end();
	++alpha_it)
    {
	ABaseListener * temp = * alpha_it;
	temp->handleListener();
    }
}

AMouseInfo AEventMgr::mouseMoveEvent(QMouseEvent *mouse)
{

    AMouseInfo info;
    info.setMouseX ((mouse->x()-ASystem::GetWidget()->getScreenOffsetX())/ASystem::GetWidget()->getScaleFactor());
    info.setMouseY (((ASystem::GetWidget()->getReal_height()-mouse->y())-ASystem::GetWidget()->getScreenOffsetY())/ASystem::GetWidget()->getScaleFactor());
    if(info.getMouseX()<0 || info.getMouseX()>ASystem::GetWidth() || info.getMouseY()<0 || info.getMouseY()>ASystem::GetHeight())
    {
        return info;
    }
        for(list<AMouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
        alpha_it != m_mouse_listener_list.end();
        ++alpha_it)
        {
        AMouseListener *  temp = * alpha_it;
        temp->onMouseMove(info);
        }
    return info;
}

AMouseInfo AEventMgr::mousePressEvent(QMouseEvent *mouse)
{
    AMouseInfo info;
    info.setMouseX ((mouse->x()-ASystem::GetWidget()->getScreenOffsetX())/ASystem::GetWidget()->getScaleFactor());
    info.setMouseY (((ASystem::GetWidget()->getReal_height()-mouse->y())-ASystem::GetWidget()->getScreenOffsetY())/ASystem::GetWidget()->getScaleFactor());

    if(info.getMouseX()<0 || info.getMouseX()>ASystem::GetWidth() || info.getMouseY()<0 || info.getMouseY()>ASystem::GetHeight())
    {
        qDebug()<<"invalid";
        return info;
    }
    qDebug()<<"the mouse postion ("<<info.getMouseX()<<" , "<<info.getMouseY()<<")"<<ASystem::GetWidth()<<ASystem::GetHeight();
	for(list<AMouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	    alpha_it != m_mouse_listener_list.end();
	    ++alpha_it)
	{
	    AMouseListener *  temp = * alpha_it;
	    temp->onMousePress(info);
	}
    return info;
}

AMouseInfo AEventMgr::mouseReleaseEvent(QMouseEvent *mouse)
{
    AMouseInfo info;
    info.setMouseX ((mouse->x()-ASystem::GetWidget()->getScreenOffsetX())/ASystem::GetWidget()->getScaleFactor());
    info.setMouseY (((ASystem::GetWidget()->getReal_height()-mouse->y())-ASystem::GetWidget()->getScreenOffsetY())/ASystem::GetWidget()->getScaleFactor());
    if(info.getMouseX()<0 || info.getMouseX()>ASystem::GetWidth() || info.getMouseY()<0 || info.getMouseY()>ASystem::GetHeight())
    {
        return info;
    }
	for(list<AMouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	    alpha_it != m_mouse_listener_list.end();
	    ++alpha_it)
	{
	    AMouseListener *  temp = * alpha_it;
	    temp->onMouseRelease(info);
	}
    return info;
}

void AEventMgr::keyReleaseEvent(QKeyEvent *a)
{
	for(list<AKeyListener *>::iterator alpha_it = m_key_listener_list.begin();
	    alpha_it != m_key_listener_list.end();
	    ++alpha_it)
	{
	    AKeyListener *  temp = * alpha_it;
	    temp->onKeyRelease (a);
	}
}


void AEventMgr::keyPressEvent(QKeyEvent * a)
{
	for(list<AKeyListener *>::iterator alpha_it = m_key_listener_list.begin();
	    alpha_it != m_key_listener_list.end();
	    ++alpha_it)
	{
		AKeyListener *  temp = * alpha_it;
		temp->onKeyPress (a);
	}
}

void AEventMgr::beforeFrameEvent()
{
	for(list<AFrameListener *>::iterator alpha_it = m_frame_listener_list.begin();
	    alpha_it != m_frame_listener_list.end();
	    ++alpha_it)
	{
		AFrameListener *  temp = * alpha_it;
		temp->beforeFrameRender ();
	}
}

void AEventMgr::afterFrameEvent()
{
	for(list<AFrameListener *>::iterator alpha_it = m_frame_listener_list.begin();
	    alpha_it != m_frame_listener_list.end();
	    ++alpha_it)
	{
		AFrameListener *  temp = * alpha_it;
		temp->afterFrameRender ();
	}
}

std::list<ABaseListener *> * AEventMgr::getList()
{
    return &listenerList;
}

}
