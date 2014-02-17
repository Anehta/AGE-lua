#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <../include/age_spriteactor.h>
#include <../include/age_keylistener.h>
using namespace AGE2D;
class BackGround : public ASprite,public AKeyListener
{
public:
    BackGround();
    BackGround(ATexture *);
protected:
    void shaderAction();
    virtual void onKeyPress(QKeyEvent *event);
    virtual void onKeyRelease(QKeyEvent *event);
private:
    float t = 0;
    float ts = 0;
    float a = 0.07416/2;
    float as = 0;
    bool z = false;
    bool x = false;
    bool up = false;
    bool down = false;
};

#endif // BACKGROUND_H
