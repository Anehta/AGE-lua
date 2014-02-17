#include "enemy.h"

#include "game.h"
using namespace AGE2D;
Enemy::Enemy(AVector2D pos, int enemy_type)
{
	enemy_texture = new ATexture(":/enemy.png");

	this->bindTexture (enemy_texture);
	this->setPos (pos);
	this->enemy_type=enemy_type;
	enemy_speed=0.05;
	//将敌人添加到场景中
	Game::single ()->getGameScene ()->layer (2)->addChild (this);
	qDebug()<<"the position is "<<this->getX ()<<" , "<<this->getY ();
}

void Enemy::action()
{
	if(out_of_the_boundary (this->getX (),this->getY ()))
	{
		this->destroy ();
		return;
	}


	switch(enemy_type)
	{
	case ENEMY_CHARGE:
		handleCharge ();
		break;
	case ENEMY_LEFT_SLIDE:
		handleLeftSlide();
		break;
	case ENEMY_RIGHT_SLIDE:
		handleRightSlide ();
		break;
	default :
		qDebug()<<"wrong enemy type";
		break;
	}
}

bool Enemy::out_of_the_boundary(double x,double y)
{

    if(x + this->width ()<0 ||
       y + this->height ()<=0 ||
       x>ASystem::GetWidth () ||
	  y>ASystem::GetHeight ()
	   )
	{
		return true;
	}
	else
	{
		return false;
	}
}




void Enemy::handleCharge()
{
	//持续向正下方移动
	AVector2D velocity(0,-1*this->enemy_speed*ASystem::TimeStep ());
	this->setX (this->getX ()+velocity.x ());
	this->setY(this->getY()+velocity.y ());
}

void Enemy::handleLeftSlide()
{

	//持续向左下方移动
	AVector2D velocity(-1*this->enemy_speed*ASystem::TimeStep (),
			 -1*this->enemy_speed*ASystem::TimeStep ());
	this->setX (this->getX ()+velocity.x ());
	this->setY(this->getY()+velocity.y ());;
}

void Enemy::handleRightSlide()
{

	//持续向右下方移动
	AVector2D velocity(1*this->enemy_speed*ASystem::TimeStep (),
			 -1*this->enemy_speed*ASystem::TimeStep ());
	this->setX (this->getX ()+velocity.x ());
	this->setY(this->getY()+velocity.y ());
}
