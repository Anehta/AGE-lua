#ifndef ALAYER_H
#define ALAYER_H
#include <list>
#include "age_scene.h"
#include "age_sprite.h"
#include "age_baseentity.h"
#include <qglfunctions.h>

namespace AGE2D {

class ASprite;
class AScene;
class ALayer : public QGLFunctions ,public ABaseEntity
{
public:
    ALayer();

    ALayer(ASprite * spritePointer);
    void addChild(ASprite * spritePointer);
    virtual void setName(std::string new_name);
    friend class AScene;
    AScene * parent();
    void checkPress(AVector2D pos);
    void checkRelease(AVector2D pos);
protected:
    virtual void action();
    AScene * m_parent;
private:
    std::list<ASprite *> m_spriteList;
    void renderLayer();
};
}


#endif // ALAYER_H
