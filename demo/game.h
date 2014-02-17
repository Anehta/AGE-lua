#ifndef GAME_H
#define GAME_H
#include "../include/age_texture.h"
#include "../include/age_scene.h"
#include "../include/age_spriteactor.h"
#include "../include/age_eventmgr.h"
#include "../include/age_audio.h"
#include <QGLShaderProgram>
#include <menu/menuscene.h>
#include <hero/hero.h>
#include <back_ground.h>

using namespace AGE2D;
//管理整个游戏的资源
class Game : public QGLFunctions
{
public:
	static Game * single();
	static void Init();

    AScene *getGame_scene() const;
    void setGame_scene(AScene *value);
    ATexture *getBullet_texture() const;
    void setBullet_texture(ATexture *value);

    AAudio *getGame_scene_music() const;
    void setGame_scene_music(AAudio *value);

private:
    Game();
    static Game *game;
    MenuScene * menu;
    AEventMgr * event_mgr;
    Hero *hero;
    BackGroud *back_ground_texture;
    AScene *game_scene;
    ATexture * bullet_texture;
    AAudio * game_scene_music;
};

#endif // GAME_H
