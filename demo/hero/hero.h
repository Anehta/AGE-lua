#ifndef HERO_H
#define HERO_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_keylistener.h"
#include "../include/age_accumulator.h"
#include "../include/age_audio.h"
#include "../include/age_mouselistener.h"
#include "../include/age_mouseinfo.h"
#include <bullet.h>

using namespace AGE2D;
class Hero :public ASprite,public AKeyListener,public AMouseListener
{
protected:
    bool is_in_the_boundary_x(double x);
    bool is_in_the_boundary_y(double y);
    ATexture* hero_texture;
    AAudio *bullet_music;
    bool turn_left;
    bool turn_right;
    bool fore_ward;
    bool back_ward;
    bool sneak;
    bool is_firing;
    bool put_mouse;
    AAccumulator *fire_cd;
    AMouseInfo old;
    float mouse_increase_x;
    float mouse_increase_y;
public:
    Hero();
    virtual void onKeyRelease(QKeyEvent * event);
    virtual void onKeyPress (QKeyEvent *event);
    virtual void onMouseMove(AMouseInfo info);
    virtual void onMouseRelease(AMouseInfo info);
    virtual void onMousePress(AMouseInfo info);
    virtual void action();
    ATexture *getBullet_texture() const;
    void setBullet_texture(ATexture *value);
    ATexture *getHero_texture() const;
    void setHero_texture(ATexture *value);
};

#endif // HERO_H
