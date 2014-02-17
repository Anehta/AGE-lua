#include <../include/AGE2D.h>
#include <QDebug>
#include <iostream>

using namespace std;

AListenerManager::AListenerManager()
{

}

void AListenerManager::addListener(ABaseListener * baseListener)
{
    ABaseListener* p =dynamic_cast<ABaseListener*>(baseListener);
    if(p != NULL)
        listenerList.push_back(p);
    qDebug()<<"addListener";
}

void AListenerManager::run()
{

    for(list<ABaseListener *>::iterator alpha_it = listenerList.begin();
        alpha_it != listenerList.end();
        ++alpha_it)
    {
        ABaseListener * temp = * alpha_it;
        temp->handleListener();
    }
}

void AListenerManager::mouseMoveEvent(QMouseEvent *mouse)
{

    for(list<ABaseListener *>::iterator alpha_it = listenerList.begin();
        alpha_it != listenerList.end();
        ++alpha_it)
    {
        //qDebug()<<"AListenerManager::mouseMoveEvent";
        auto temp = * alpha_it;
        temp->mouseMoveEvent(mouse);
    }
}

void AListenerManager::mousePressEvent(QMouseEvent *mouse)
{
    //qDebug()<<"AListenerManager::mousePressEvent";
    for(list<ABaseListener *>::iterator alpha_it = listenerList.begin();
        alpha_it != listenerList.end();
        ++alpha_it)
    {
        ABaseListener * temp = * alpha_it;
        temp->mousePressEvent(mouse);
    }
}

void AListenerManager::mouseReleaseEvent(QMouseEvent *mouse)
{
    //qDebug()<<"AListenerManager::mouseReleaseEvent";
    for(list<ABaseListener *>::iterator alpha_it = listenerList.begin();
        alpha_it != listenerList.end();
        ++alpha_it)
    {
        ABaseListener * temp = * alpha_it;
        temp->mouseReleaseEvent(mouse);
    }
}

void AListenerManager::keyPressEvent()
{

}

std::list<ABaseListener *> * AListenerManager::getList()
{
    return &listenerList;
}
