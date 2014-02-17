#ifndef BACK_GROUND_H
#define BACK_GROUND_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_system.h"

using namespace AGE2D;

class BackGroud:public ASprite
{
protected:
    ATexture *backgroudtexture;
public:
    BackGroud();
};


#endif // BACK_GROUND_H
