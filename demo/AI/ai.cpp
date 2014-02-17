#include "../AI/ai.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "../include/age_layer.h"
#include "../include/age_scene.h"
#include "game.h"
#define MAX_X 1080
#define MAX_Y 1920

namespace AGE2D{
Ai::Ai(QString AiSrc)
{
    this->ai_texture= new ATexture(AiSrc);
    this->bindTexture(ai_texture);
    this->setWidth(150);
    this->setHeight(150);
    this->from = 0;
    this->inX = -1;
    this->inY = -1;
    this->outX = -1;
    this->outY = -1;
    this->stayX = -1;
    this->stayY = -1;
    this->is_firing = false;
}

int Ai::get_Rand(int s)//得到随机数
{
    srand((unsigned) time(NULL));
    return rand() % s;
}

void Ai::AiIn()
{
    this->from = get_Rand(3);
    switch(from)
    {
    case 0 :this->inY = get_Rand(MAX_Y);this->inX = MAX_X;break;
    case 1 :this->inY = -width();this->inX = get_Rand(MAX_X);break;
    case 2 :this->inY = MAX_Y;inX = get_Rand(MAX_X);break;
    }
    this->setX(inX);
    this->setY(inY);
}

void Ai::AiOut()
{
    this->is_firing = false;
    from = get_Rand(3);
    switch(from)
    {
    case 0 :outY = get_Rand(MAX_Y)+ height();outX = MAX_X;break;
    case 1 :outY = 0;outX = get_Rand(MAX_X);break;
    case 2 :outY = MAX_Y;outX = get_Rand(MAX_X) + width();break;
    }
    this->setX(outX);
    this->setY(outY);
}

void Ai::AiStay()
{
    stayX = get_Rand(MAX_X);
    stayY = get_Rand(MAX_Y);
    this->setX(stayX);
    this->setY(stayY);
    this->is_firing = true;
}

void Ai::aciton()
{
    fire_cd->step (ASystem::TimeStep () * 2);
    AScene * game_scene=Game::single ()->getGame_scene();
    ParticleLauncher(game_scene->layer(2),Game::single()->getBullet_texture(),5,AVector2D(this->getX(),this->getY()),
                     AVector2D(100,100),AVector2D(0,0),AColor(1,1,1),
                     AColor(0,1,1),0,300,1,0,4,AVector2D(0,-2),10);
    if(fire_cd->isTouched ())
    {
        fire_cd->rewind ();
        if(is_firing)
        {
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),1,0.5,true));
        }
     }
}

ATexture *Ai::getAi_texture() const
{
    return ai_texture;
}

void Ai::setAi_texture(ATexture *value)
{
    ai_texture = value;
}

}
