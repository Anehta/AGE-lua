#ifndef AI_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_keylistener.h"
#include "../include/age_accumulator.h"
#include "../include/age_audio.h"
#include "particle.h"
#include "particlelauncher.h"
#include <ctime>
#include <time.h>
#include <stdlib.h>
#define AI_H
//1080*1920
namespace AGE2D{
class Ai :public ABaseEntity,public ASprite
{
protected:
     QString name;
     ATexture* ai_texture;
     AAccumulator *fire_cd;
     bool is_firing;
     int from;
     int inX;
     int inY;
     int outX;
     int outY;
     int stayX;
     int stayY;
public:
    Ai(QString AiSrc);
    int get_Rand(int s);
    void aciton();
    void AiIn();
    void AiStay();
    void AiOut();
    ATexture *getBullet_texture() const;
    void setBullet_texture(ATexture *value);
    ATexture *getAi_texture() const;
    void setAi_texture(ATexture *value);
};
}

#endif // AI_H
