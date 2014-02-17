#include "back_ground.h"

BackGroud::BackGroud()
{
    this->backgroudtexture=new ATexture (":/image/menu_earth.png");
    this->bindTexture(this->backgroudtexture);
    //this->setWidth(1080);
    //this->setHeight(1920);

}
