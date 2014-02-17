#include "../hero/hero.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "../include/age_layer.h"
#include "../include/age_scene.h"
#include "game.h"
#include <QDebug>
#include "particle.h"
#include "particlelauncher.h"
#define speed 1
#define speed_android 1.5

Hero::Hero()
{
    this->hero_texture= new ATexture(":/image/hero.png");
    this->setPos(AVector2D(200,200));
    this->bindTexture(hero_texture);
    this->setWidth(150);
    this->setHeight(150);
    this->turn_left=false;
    this->turn_right=false;
    this->fore_ward=false;
    this->back_ward=false;
    this->is_firing=true;
    this->put_mouse=false;
    this->sneak=false;
    this->mouse_increase_x=0.0;
    this->mouse_increase_y=0.0;
    this->old.setMouseX(this->getX());
    this->old.setMouseY(this->getY());
    this->fire_cd= new AAccumulator(0,3,0.05,false);
    this->bullet_music = new AAudio(":/music/bullet.wav");
    this->bullet_music->setVolume(30);
    //this->bullet_music->setObjectName("bullet_music");
    this->bullet_music->setLoopORnot(true);

}



void Hero::onKeyRelease(QKeyEvent *event)
{
    switch(event->key ())
    {
    case Qt::Key_Left:
        turn_left=false;
        break;
    case Qt::Key_Right:
        turn_right=false;
        break;
    case Qt::Key_Up:
        fore_ward=false;
        break;
    case Qt::Key_Down:
        back_ward=false;
        break;
    case Qt::Key_Z:
        is_firing=true;
        break;

    }
    if(event->nativeVirtualKey() == 16)
    {
        sneak=false;
    }
}

void Hero::onKeyPress(QKeyEvent *event)
{
    switch(event->key ())
    {
    case Qt::Key_Left:
        turn_left=true;
        break;
    case Qt::Key_Right:
        turn_right=true;
        break;
    case Qt::Key_Up:
        fore_ward=true;
        break;
    case Qt::Key_Down:
        back_ward=true;
        break;
    case Qt::Key_Z:
        is_firing=true;
        break;

    }
    if(event->modifiers ()==Qt::ShiftModifier)
    {
        sneak=true;
    }
}

void Hero::onMouseMove(AMouseInfo info)
{
    this->mouse_increase_x=info.getMouseX()-this->old.getMouseX();
    this->mouse_increase_y=info.getMouseY()-this->old.getMouseY();
    this->old.setMouseX(info.getMouseX());
    this->old.setMouseY(info.getMouseY());
}

void Hero::onMouseRelease(AMouseInfo info)
{

    this->put_mouse=false;
    this->mouse_increase_x=0;
    this->mouse_increase_y=0;

}

void Hero::onMousePress(AMouseInfo info)
{
    this->put_mouse=true;
    this->old.setMouseX(info.getMouseX());
    this->old.setMouseY(info.getMouseY());

}

void Hero::action()
{
    AVector2D velocity(0,0);
    if(!put_mouse)
    {
        if(turn_left==true)
        {
            velocity.setX (-1*speed*ASystem::TimeStep ());
        }
        if(turn_right==true)
        {
            velocity.setX (speed*ASystem::TimeStep ());
        }
        if(fore_ward==true)
        {
            velocity.setY (speed*ASystem::TimeStep ());
        }
        if(back_ward==true)
        {
            velocity.setY (-1*speed*ASystem::TimeStep ());
        }
    }
    else
    {
        velocity.setX(this->mouse_increase_x*speed_android);
        velocity.setY(this->mouse_increase_y*speed_android);
    }

    if(sneak)
    {
        velocity*=0.1;
    }
    if(is_in_the_boundary_x (this->getX ()+velocity.x ()))
    {
        //qDebug()<<this->mouse_increase_x<<" "<<this->mouse_increase_y<<endl;
        this->setX (this->getX ()+velocity.x ());
        this->mouse_increase_x=0;
    }

    if(is_in_the_boundary_y(this->getY()+velocity.y()))
    {
       this->setY(this->getY()+velocity.y());
       this->mouse_increase_y=0;
    }

    fire_cd->step (ASystem::TimeStep ());

    AScene * game_scene=Game::single ()->getGame_scene();
    ParticleLauncher(game_scene->layer(1),Game::single()->getBullet_texture(),2,AVector2D(this->getX(),this->getY()),
                     AVector2D(100,100),AVector2D(0,0),AColor(1,1,1),
                     AColor(0,1,1),0,300,1,0,4,AVector2D(0,-2),10);
    //bullet_music->play();
    if(fire_cd->isTouched ())
    {
        fire_cd->rewind ();
        if(is_firing)
        {
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),1,2,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15-50,this->middleY()-15-50),1,2,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15+50,this->middleY()-15-50),1,2,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15-25,this->middleY()-15-75),1,2,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15+25,this->middleY()-15-75),1,2,true));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.5,0.1,true));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.3,0.1,true));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.5,0.1,false));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.3,0.1,false));
        }

     }

}

bool Hero::is_in_the_boundary_x(double x)
{
    if(x >=0 && x<=ASystem::GetWidth ()-this->width ())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Hero::is_in_the_boundary_y(double y)
{
    if(y>=0&&y<=ASystem::GetHeight()-this->height())
    {
       return true;
    }
    else
    {
       return false;
    }
}
ATexture *Hero::getHero_texture() const
{
    return hero_texture;
}

void Hero::setHero_texture(ATexture *value)
{
    hero_texture = value;
}


