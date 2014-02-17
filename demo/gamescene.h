#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../include/AGE2D.h"
#include "../include/age_font.h"

using namespace AGE2D;
class Gamescene : public AScene
{
public:
    Gamescene();
    void init();

protected:
    void action();

private:
    int value = 0;
    AFont *font;
};

#endif // GAMESCENE_H
