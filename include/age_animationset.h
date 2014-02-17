#ifndef AANIMATIONSET_H
#define AANIMATIONSET_H
#include <list>
#include <../include/age_animation.h>
#include <QDomDocument>
#include <qstring.h>
using namespace std;
namespace AGE2D {
class AAnimation;
class AAnimationSet
{
public:
	AAnimationSet(QString fileName);
	AAnimation * findAnimation(QString animationName);
protected:
void addAnimationFromFile(AAnimation * animation,QDomElement node);
    list <AAnimation> m_animationlist;
};
}


#endif // AANIMATIONSET_H
