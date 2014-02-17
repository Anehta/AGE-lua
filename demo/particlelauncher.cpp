#include "particlelauncher.h"

#include "particle.h"
#include "stdlib.h"
ParticleLauncher::ParticleLauncher(ALayer * layer,ATexture* texture,int count,AVector2D pos,
                                   AVector2D begin_size,AVector2D end_size,
                                   AColor begin_color ,AColor end_color,float angle_speed,int span,
                                   float begin_alpha,float end_alpha,float rotate_speed,
                                   AVector2D gravity,int delay)
{
for(int i=0;i<count;i++)
{

    layer->addChild(new Particle(texture,rand()%360,
                                          pos,begin_size,end_size,
                                          begin_color,end_color,0.3+0.05*(rand()%4),angle_speed,span,begin_alpha,end_alpha,rotate_speed,gravity,delay));
}
}
