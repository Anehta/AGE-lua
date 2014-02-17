#ifndef ASPRITEACTOR_H
#define ASPRITEACTOR_H
#include <../include/age_sprite.h>
#include <set>
#include <QString>
#include <list>
#include <../include/age_animation.h>
#include <QDomDocument>
#include <../include/age_animationset.h>
using namespace std;
namespace AGE2D
{
class ASpriteActor : public ASprite
{
public:
    ASpriteActor();
    ASpriteActor(ATexture *);
    ~ASpriteActor();
    void animate(QString actionName,int frames,bool isCycle); //执行动作
    void addAnimation(AAnimation);
    void loadAnimationsFromFile(QString fileName);
    void bindAnimationSet(AAnimationSet * animation_set);
protected:
    void addAnimationFromFile(AAnimation * animation,QDomElement node);
    void action();
     AAnimationSet * m_animation_set;
    list <AAnimation> m_animationlist;
};
}


#endif // ASPRITEACTOR_H
