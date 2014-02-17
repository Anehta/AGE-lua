#include "menuscene.h"
#include "particle.h"
#include "particlelauncher.h"
#include "game.h"
MenuScene::MenuScene()
{
    initData();
    initResource();
    initActor();
}


void MenuScene::initResource()
{
    menuCircle_texture = new ATexture(":/image/menu_choose.png");
    menuFrame_texture = new ATexture(":/image/menu_frame.png");
    menuBackGround_texture = new ATexture(":/image/menu_earth.png");
    background_music = new AAudio(":/music/earth.mp3");
    touch_effect_texture = new ATexture(":/effect/effect2.png");
}

void MenuScene::initActor()
{

    /*effect sprite init*/
    menuBackGround_sprite = new ASprite(menuBackGround_texture);
    menuFrame_sprite = new ASprite(menuFrame_texture);
    /*button sprite init*/
    menu_game_button_sprite = new ASprite(menuCircle_texture);
    menu_achievement_button_sprite = new ASprite(menuCircle_texture);
    menu_set_button_sprite = new ASprite(menuCircle_texture);

    /*set Sprite name*/
    menuBackGround_sprite->setName("菜单背景");
    menuFrame_sprite->setName("菜单框架");
    menu_game_button_sprite->setName("菜单游戏按钮");
    menu_game_button_sprite->setIsTouchable(true);
    menu_achievement_button_sprite->setName("菜单成就按钮");
    menu_set_button_sprite->setName("菜单设置按钮");


    /*add Sprite order*/
    this->layer(1)->addChild(menuBackGround_sprite);
    this->layer(1)->addChild(menuFrame_sprite);
    this->layer(1)->addChild(menu_game_button_sprite);
    this->layer(1)->addChild(menu_achievement_button_sprite);
    this->layer(1)->addChild(menu_set_button_sprite);

    /*set actor location*/
    menuBackGround_sprite->setPos(AVector2D(-menuBackGround_sprite->width()/3,
                                            -menuBackGround_sprite->height()/2));

    menu_game_button_sprite->setPos(AVector2D(ASystem::GetWidth()/2-menu_game_button_sprite->width()/2,
                                              menu_game_button_sprite->height()*4));

    menu_achievement_button_sprite->setPos(AVector2D(ASystem::GetWidth()/2-menu_game_button_sprite->width()/2,
                                              menu_game_button_sprite->height()*3-100));

    menu_set_button_sprite->setPos(AVector2D(ASystem::GetWidth()/2-menu_game_button_sprite->width()/2,
                                              menu_game_button_sprite->height()*2-200));

    /*set sprite PivotOffset*/
    menuBackGround_sprite->setPivotOffset(menuBackGround_sprite->width()/2,
                                          menuBackGround_sprite->height()/2);
    menu_game_button_sprite->setPivotOffset(menu_game_button_sprite->width()/2,
                                            menu_game_button_sprite->height()/2);
    menu_achievement_button_sprite->setPivotOffset(menu_game_button_sprite->width()/2,
                                            menu_game_button_sprite->height()/2);
    menu_set_button_sprite->setPivotOffset(menu_game_button_sprite->width()/2,
                                            menu_game_button_sprite->height()/2);

    background_music->play();
    this->setListenerManager(new AEventMgr);
    this->eventMgr()->addMouseListener(this);
}

void MenuScene::initData()
{
    background_rotate = 0;
    botton_rotate = 0;
    isPress = false;
    mouseX = 0;
    mouseY = 0;
}

void MenuScene::action()
{
    background_rotate += 0.1;
    botton_rotate += 0.3;
    menuBackGround_sprite->rotate(background_rotate);
    menu_game_button_sprite->rotate(-botton_rotate);
    menu_achievement_button_sprite->rotate(-botton_rotate-0.1);
    menu_set_button_sprite->rotate(-botton_rotate-0.3);
    ParticleLauncher(this->layer(1),touch_effect_texture,2,AVector2D(mouseX,mouseY),
                     AVector2D(100,100),AVector2D(0,0),AColor(1,1,1),
                     AColor(0,1,1),0,300,1,0,4,AVector2D(0,-1),10);

    //menu_game_button_sprite->setPos(AVector2D(mouseX,mouseY));
}

void MenuScene::onMouseMove(AMouseInfo info)
{
    mouseX = info.getMouseX();
    mouseY = info.getMouseY();

}

void MenuScene::onMousePress(AMouseInfo info)
{

    this->background_music->stop();
    Game::single()->getGame_scene()->activate();
    Game::single()->getGame_scene_music()->play();
}

void MenuScene::onMouseRelease(AMouseInfo info)
{

}
