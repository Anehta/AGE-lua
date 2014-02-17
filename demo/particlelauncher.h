#ifndef PARTICLELAUNCHER_H
#define PARTICLELAUNCHER_H

#include "../include/age_layer.h"
#include "../include/age_vector2d.h"
#include "../include/age_color.h"
using namespace AGE2D;
class ParticleLauncher
{
public:
    ParticleLauncher(ALayer * layer,ATexture* texture,int count,AVector2D pos,
                     AVector2D begin_size,AVector2D end_size,
                     AColor begin_color ,AColor end_color,float angle_speed,int span,
                     float begin_alpha,float end_alpha,float rotate_speed,
                     AVector2D gravity,int delay);
};

#endif // PARTICLELAUNCHER_H
