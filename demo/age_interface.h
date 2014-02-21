#ifndef AGE_INTERFACE_H
#define AGE_INTERFACE_H
namespace AGE2D {

    void ARegisterToLua();
    void * ATextureCreate(const char * string);
    void * ASpriteCreate();
    void ASpriteRender(void * sprite_handle);
    void ASpriteSetSize(void * sprite_handle,int width,int height);
    void ASpriteSetPos(void * sprite_handle,double x,double y);
    void ASpriteRotate(void * sprite_handle,double angle);
    void ASpriteColor(void * sprite_handle,double r,double g,double b,double a);
    void ASpriteBindTexture(void * sprite_handle,void * texture_handle);
    void ASpriteDestory(void * sprite_handle);
    double ASpriteGetX();
    double ASpriteGetY();
    void * ATextCreate(int size,int maxw,int maxh,const char* ttfFileName);
    void ATextDraw(void * text_handle,int pos_x,int pos_y,const char * string);
    void * AAudioCreate(const char * string);
    void  AAudioPlay(void * audio_handle);
    void AAudioPause(void * audio_handle);
    void AAudioStop(void *audio_handle);
    void AAudioSetVolume(void *audio_handle,int volume);
    void AAudioLoop(void *audio_handle,int is_loop);
    void AGame(const char * str);
    void ASetSize(int w,int h);
    int ATimeStep();
    void* APolygon2DCreate();
    void APolygon2DAdd(void* polygon_handle,int x,int y);
    int APolygonIn(void* polygon_handle,int x,int y);
}






#endif // AGE_INTERFACE_H
