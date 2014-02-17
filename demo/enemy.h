#ifndef ENEMY_H
#define ENEMY_H
#include "../include/age_spriteactor.h"
#include "../include/age_vector2d.h"


#define ENEMY_CHARGE 1
#define ENEMY_LEFT_SLIDE 2
#define ENEMY_RIGHT_SLIDE 3

class Enemy :public AGE2D::ASpriteActor
{
public:
	Enemy(AGE2D::AVector2D pos,int enemy_type);
protected:
	AGE2D::ATexture * enemy_texture;
	int enemy_type;
	virtual void action();
	void handleCharge();
	void handleLeftSlide();
	void handleRightSlide();
	bool out_of_the_boundary(double x,double y);
	double enemy_speed;
};

#endif // ENEMY_H
