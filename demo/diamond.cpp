#include "diamond.h"
#include "game.h"
#include "../include/age_application.h"
#include <stdio.h>

int p2ps(int x1,int y1,int x2,int y2);

Diamond::Diamond()
{
}

Diamond::Diamond(ATexture *tex)
{
    bindTexture(tex);
}


void Diamond::action()
{
    this->setY(this->getY()-r);
    int hx = Game::single()->getHero()->middleX();
    int hy = Game::single()->getHero()->middleY();

    if(p2ps(this->middleX(),this->middleY(),
            hx,hy)<=10)
    {
        static int a = 0;
        a++;
        qDebug()<<"你撞到了"<<a<<"次";
        this->destroy();
    }
    if(out_of_the_boundary(this->getX(),this->getY()))
    {
        this->destroy();
    }
}

bool Diamond::out_of_the_boundary(double x,double y)
{

    if(x + this->width ()<0 ||
       y + this->height ()<=0 ||
       x>ASystem::GetWidth ()
       )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int p2ps(int x1,int y1,int x2,int y2)
{
    int x = (x1-x2)*(x1-x2);
    int y = (y1-y2)*(y1-y2);
    return sqrt(x+y);
}
