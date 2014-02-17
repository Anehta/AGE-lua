#include "../include/age_scene.h"
#include "../include/age_staticattribute.h"
#include <utility>
#include <stdlib.h>
using namespace std;

namespace AGE2D{
AScene::AScene()
{
    m_listenerManager = NULL;
    addLayer(new ALayer()); //default layer,the id is 1
}

void AScene::activate()
{
    setCurrentScene(this);
}

//add a default layer & return the handle ID
int AScene::addLayer()
{
	ALayer *layerPointer =new ALayer();
	layerPointer->m_parent=this;
    m_layerList.push_back(layerPointer);
    insertBaseEntity(layerPointer);
    return m_layerList.size ();
}

ABaseEntity *AScene::getBaseEntity(string name)
{
	std::map<std::string,ABaseEntity *>::iterator i= this->m_name_pool.find (name);
	if(i!=this->m_name_pool.end ())
	{
		std::pair<std::string,ABaseEntity *> result_pair =(*i);
		return result_pair.second;
	}else
	{
		return NULL;
	}

}

void AScene::insertBaseEntity(ABaseEntity *entity)
{
	std::pair<std::string,ABaseEntity *> handle(entity->name (),entity);
	this->m_name_pool.insert (handle);
}

void AScene::updateBaseEntity(string old_name, string new_name)
{
	std::map<std::string,ABaseEntity *>::iterator i;
	i=this->m_name_pool.find (old_name);
	ABaseEntity * e=i->second;
	this->m_name_pool.erase (i);
	std::pair<std::string,ABaseEntity *> handle(new_name,e);
	this->m_name_pool.insert (handle);
}


int AScene::addLayer (ALayer * pointer)
{
	pointer->m_parent=this;
	m_layerList.push_back(pointer);
	insertBaseEntity(pointer);
	return m_layerList.size ();
}

ALayer *AScene::layer(int handle)
{
	list<ALayer *> :: iterator i=m_layerList.begin ();
    int count=1;
	for(;count!=handle;++i,++count);
	return (*i);
}

void AScene::renderScene(bool is_release, bool is_press, AVector2D mousePos)
{
        if(eventMgr())
        {
    this->eventMgr ()->beforeFrameEvent ();
        }

        for(list<ALayer *>::iterator alpha_it = m_layerList.begin();
        alpha_it != m_layerList.end();
        ++alpha_it)
        {
        ALayer * temp = *alpha_it;
        temp->renderLayer();
        temp->action();
        }
        if(is_release)
        {
            for(list<ALayer *>::reverse_iterator i=m_layerList.rbegin();i!=m_layerList.rend();i++)
            {
                ALayer * tmp= (*i);
                tmp->checkRelease(mousePos);
            }
        }
        if(is_press)
        {
            for(list<ALayer *>::reverse_iterator i=m_layerList.rbegin();i!=m_layerList.rend();i++)
            {
                ALayer * tmp= (*i);
                tmp->checkPress(mousePos);
            }
        }

        if(eventMgr())
        {
    this->eventMgr ()->afterFrameEvent ();
        }
    action();
}

void AScene::action()
{

}

void AScene::setListenerManager(AEventMgr * listenerManager)
{
	m_listenerManager = listenerManager;
}

AEventMgr *AScene::eventMgr()
{
	return m_listenerManager;
}

}
