#include "gamescene.h"
#include "diamond.h"
#include "game.h"
#include "../include/age_baseentity.h"
Gamescene::Gamescene()
{
    font = new AFont(10,30,0,":/fzjzjt.ttf");
}

void Gamescene::init()
{

}

void Gamescene::action()
{
    static int str_num = 0;
    str_num++;
    QString strtemp;
    strtemp = QString::number(str_num);
    font->print("\"呵呵(nimabi)\""+strtemp,100,100,Game::single()->getGameScene()->layer(2));
    static float value = 0;
    static bool fuck = true;

    if(fuck)
    {
        value += 0.005;
        if(value >1)
        {
            fuck = false;
        }
    }
    else
    {
        value -= 0.005;
        if(value <=0.005)
        {
            fuck = true;
        }
    }
    //ASystem::GetWidget()->setWindowOpacity(value);
    /*if(value%2 == 1)
    {
        Diamond * fucker = new Diamond(Game::single()->getDiamond_texture());
        fucker->setX(rand()%ASystem::GetWidth());
        fucker->setY(ASystem::GetHeight()+10);
        Game::single()->getGameScene()->layer(1)->addChild(fucker);
    }*/
}
