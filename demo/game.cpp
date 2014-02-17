#include "game.h"
#include "../include/age_layer.h"
#include <QGLFunctions>
#include "../include/age_baseentity.h"
Game * Game::game;

Game *Game::single()
{
	return game;
}

void Game::Init()
{
    game= new Game();
}

Game::Game()
{
    ASystem::SetSize(1080,1920);
    ASystem::GetWidget()->setWindowTitle("AGE");
    menu = new MenuScene();
    menu->activate();
    game_scene = new AScene;
    hero = new Hero();
    back_ground_texture = new BackGroud();
    bullet_texture=new ATexture (":/effect/effect2.png");

    game_scene_music= new AAudio(":/music/001.mp3");
    game_scene_music->setVolume(70);
    game_scene_music->setLoopORnot(true);

    game_scene->setListenerManager(new AEventMgr());
    game_scene->eventMgr()->addMouseListener(hero);
    game_scene->eventMgr()->addKeyListener(hero);
    game_scene->layer(1)->addChild(back_ground_texture);
    game_scene->addLayer();
    game_scene->layer(2)->addChild(hero);
    //game_scene->activate();
}
AAudio *Game::getGame_scene_music() const
{
    return game_scene_music;
}

void Game::setGame_scene_music(AAudio *value)
{
    game_scene_music = value;
}

ATexture *Game::getBullet_texture() const
{
    return bullet_texture;
}

void Game::setBullet_texture(ATexture *value)
{
    bullet_texture = value;
}


AScene *Game::getGame_scene() const
{
    return game_scene;
}

void Game::setGame_scene(AScene *value)
{
    game_scene = value;
}

