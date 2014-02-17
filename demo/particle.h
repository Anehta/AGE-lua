#ifndef PARTICLE_H
#define PARTICLE_H

#include "../include/age_sprite.h"
#include "../include/age_vector2d.h"
#include "../include/age_texture.h"
#include "../include/age_color.h"
#include "../include/age_accumulator.h"
using namespace AGE2D;
class Particle :public ASprite
{
public:
    Particle(ATexture * texture , double begin_angle, AVector2D pos,
             AVector2D begin_size , AVector2D end_size,
             AColor begin_color, AColor end_color,
             double escape_speed, double angle_speed,
             int span, float begin_alpha, float end_alpha, double rotate_speed, AVector2D gravity,int delay);
   protected:
    virtual void action();
private:
    int m_delay;
    double angle;
    double rotate_speed;
    AAccumulator * acc;
    int span;
    double width_change_rate;
    double height_change_rate;
    double red_change_rate;
    double green_change_rate;
    double blue_change_rate;
    double begin_angle;
    double escape_speed;
    double angle_speed;
    float alpha_change_rate;
    AVector2D init_pos;
    AVector2D gravity;
};

#endif // PARTICLE_H
