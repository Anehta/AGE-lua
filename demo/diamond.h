#ifndef DIAMOND_H
#define DIAMOND_H
#include "../include/AGE2D.h"
using namespace AGE2D;
class Diamond : public ASprite
{
public:
    Diamond();
    Diamond(ATexture * tex);
    bool out_of_the_boundary(double x,double y);
protected:
    virtual void action();

private:
    int r = rand()%5;
};

#endif // DIAMOND_H
