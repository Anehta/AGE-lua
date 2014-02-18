#ifndef AGE_INTERFACE_H
#define AGE_INTERFACE_H
namespace AGE2D {

    void ARegisterToLua();
    void * ATextureCreate(const char * string);

    void * ASpriteCreate();
    void ASpriteRender(void * sprite_handle);
    void ASpriteSetSize(void * sprite_handle,int width,int height);
    void ASpriteSetPos(void * sprite_handle,int x,int y);
    void ASpriteRotate(void * sprite_handle,double angle);
    void ASpriteColor(void * sprite_handle,double r,double g,double b,double a);
    void ASpriteBindTexture(void * sprite_handle,void * texture_handle);
    void ASpriteDestory(void * sprite_handle);
}






#endif // AGE_INTERFACE_H
