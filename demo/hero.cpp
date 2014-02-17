#include "hero.h"
#include "qdebug.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "bullet.h"
#include "../include/age_scene.h"
#include "game.h"
#include "../include/age_layer.h"
const double speed=0.3;
Hero::Hero()
{
    m_texture=new ATexture(":/hero.png");
    this->setPos(AVector2D(200,200));
	this->bindTexture (m_texture);
	 turn_left=false;
	 turn_right=false;
	 fore_ward=false;
	 back_ward=false;
	 sneak=false;
	 is_firing=false;
	 fire_cd=new AAccumulator(0,3,0.01,false);

     bullet_music = new AAudio(":/Menu_Click24.wav");
     bullet_music->setVolume(30);
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
		is_firing=false;
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

void Hero::action()
{   
	AVector2D velocity(0,0);
	if(turn_left==true)
	{
        velocity.setX (velocity.x ()-speed*ASystem::TimeStep ());
	}
	if(turn_right==true)
	{
        velocity.setX (velocity.x ()+speed*ASystem::TimeStep ());
	}
	if(fore_ward==true)
	{
        velocity.setY (velocity.y ()+speed*ASystem::TimeStep ());
	}
	if(back_ward==true)
	{
        velocity.setY (velocity.y ()-speed*ASystem::TimeStep ());
	}
	if(sneak)
	{
		velocity*=0.2;
	}
	if(is_in_the_boundary (this->getX ()+velocity.x (),this->getY ()+velocity.y ()))
	{
		this->setX (this->getX ()+velocity.x ());
		this->setY (this->getY ()+velocity.y ());
	}


    fire_cd->step (ASystem::TimeStep ());

    if(fire_cd->isTouched ())
    {
        fire_cd->rewind ();
        if(is_firing)
        {
            bullet_music->play();
            AScene * game_scene=Game::single ()->getGameScene ();
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),1,0.1,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15-50,this->middleY()-15-50),1,0.1,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15+50,this->middleY()-15-50),1,0.1,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15-25,this->middleY()-15-75),1,0.1,true));
            game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15+25,this->middleY()-15-75),1,0.1,true));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.5,0.1,true));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.3,0.1,true));
           // game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.5,0.1,false));
            //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),0.3,0.1,false));
        }

     }

}

bool Hero::is_in_the_boundary(double x,double y)
{
	if(x >=0 &&
	   y>=0 &&
	   x<=ASystem::GetWidth ()-this->width () &&
	  y<=ASystem::GetHeight ()-this->height ()
	   )
	{
		return true;
	}
	else
	{
		return false;
	}
}
