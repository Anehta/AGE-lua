#include "../include/age_layer.h"
#include <stdlib.h>
#include <qdebug.h>
using namespace std;
namespace AGE2D{
ALayer::ALayer()
{
	this->m_type=LAYER_ENTITY;
	this->m_parent=NULL;
}

ALayer::ALayer(ASprite *spritePointer)
{
	this->m_type=LAYER_ENTITY;
	this->m_parent=NULL;
    addChild(spritePointer);
}

void ALayer::addChild(ASprite *spritePointer)
{
	AScene *scene =m_parent;
    if(m_parent)
	{
		scene->insertBaseEntity (spritePointer);
		spritePointer->m_parent=this;
        m_spriteList.push_back(spritePointer);
	}
}

void ALayer::setName(string new_name)
{
	if(m_parent)
	{
		AScene *scene=m_parent;
		scene->updateBaseEntity (this->name (),new_name);
	}
    this->identity_name=new_name;
}

AScene *ALayer::parent()
{
    return m_parent;
}

void ALayer::checkPress(AVector2D pos)
{
    for(list<ASprite*>::reverse_iterator i = m_spriteList.rbegin();i!=m_spriteList.rend();i++)
    {
        ASprite * tmp=(*i);
        if(tmp->isTouchable())
        {
            APolygon polygon=tmp->getPolygon();
            if(polygon.pointInPolygon(pos)==1)
            {

                tmp->OnTouchedPress(pos);
                return;
            }
        }
    }
}

void ALayer::checkRelease(AVector2D pos)
{
    for(list<ASprite*>::reverse_iterator i = m_spriteList.rbegin();i!=m_spriteList.rend();i++)
    {
        ASprite * tmp=(*i);
        if(tmp->isTouchable())
        {
            APolygon polygon=tmp->getPolygon();
            if(polygon.pointInPolygon(pos)==1)
            {
                tmp->OnTouchedrelease(pos);
                return;
            }
        }
    }
}

void ALayer::renderLayer()
{
    for(list<ASprite*>::iterator alpha_it = m_spriteList.begin();
	alpha_it != m_spriteList.end();)
    {
	if((*alpha_it)->isDeath == true)
	{
        ASprite *temp = *alpha_it;
        temp->release();
        delete temp;
	    alpha_it = m_spriteList.erase(alpha_it);
	}
	else
	{
	    ASprite * temp = *alpha_it;
	    temp->action();
	    temp->render();
	    alpha_it++;
	}
    }

    //qDebug()<<m_spriteList.size();
}

void ALayer::action()
{

}

}
