#ifndef ASCENE_H
#define ASCENE_H

#include <list>
#include <map>
#include <string>
#include "age_baseentity.h"
#include "age_baselistener.h"
#include "age_layer.h"
#include "age_widget.h"
#include "age_eventmgr.h"
namespace AGE2D
{
class ALayer;
class AEventMgr;
class ABaseEntity;
class AScene
{
public:
    AScene();
    void activate(); //set it to currentscene
    int addLayer(AGE2D::ALayer *pointer);
    int addLayer();
    ABaseEntity * getBaseEntity(std::string name);
    void insertBaseEntity(ABaseEntity * entity);
    void updateBaseEntity(std::string old_name,std::string new_name);
    ALayer * layer(int handle);
    void setListenerManager(AEventMgr * listenerManager);
    AEventMgr * eventMgr();
    friend class AWidget;

protected:
    virtual void action();
private:
    std::list<ALayer *> m_layerList;
    std::map <std::string,ABaseEntity *> m_name_pool;
    AEventMgr * m_listenerManager;
    void renderScene(bool is_release, bool is_press,AVector2D mousePos);
};
}


#endif // ASCENE_H
