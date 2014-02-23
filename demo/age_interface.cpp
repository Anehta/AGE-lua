#include "age_interface.h"
#include <QGLShader>

#include <../include/age_texture.h>
#include <../include/age_sprite.h>
#include <../include/age_vector2d.h>
#include <../include/age_font.h>
#include <../include/age_audio.h>
#include <../include/age_system.h>
#include <../include/age_polygon.h>
#include <age_lua.h>
#include <qdebug.h>
#include <string.h>

namespace AGE2D {


static char mod_string[1000];
static  void * error_font;

void *ATextureCreate(const char *string)
{
    ATexture * texture =new ATexture(QString(string));
    return texture;
}

static int ATextureCreate_bind(lua_State *L)
{
    if(lua_isstring(L,1))
    {
     const char * str=lua_tostring(L,1);
    lua_pushlightuserdata(L,ATextureCreate(str));
    }
    else
    {
         AGE_LUA_ADD_DEBUGEDIT("void *ATextureCreate(const char *string)");
         lua_pushlightuserdata(L,ATextureCreate("hehe"));
    }
    return 1;
}

void *ASpriteCreate()
{
    ASprite * sprite =new ASprite();
    return sprite;
}

static int ASpriteCreate_bind(lua_State *L)
{
    lua_pushlightuserdata(L,ASpriteCreate());
    return 1;
}

void ASpriteSetSize(void *sprite_handle, int width, int height)
{
    ASprite * sprite= (ASprite* )sprite_handle;
       sprite->setWidth(width);
       sprite->setHeight(height);
}

static int ASpriteSetSize_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1) && lua_isnumber(L,2) && lua_isnumber(L,3))
    {
    ASpriteSetSize(lua_touserdata(L,1),lua_tointeger(L,2),lua_tointeger(L,3));
    }
    return 0;
}

void ASpriteSetPos(void *sprite_handle, double x, double y)
{
    ASprite * sprite= (ASprite* )sprite_handle;
    sprite->setPos(AVector2D(x,y));
}

static int ASpriteSetPos_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1) && lua_isnumber(L,2) && lua_isnumber(L,3))
    {
    ASpriteSetPos(lua_touserdata(L,1),lua_tonumber(L,2),lua_tonumber(L,3));
    }
    return 0;
}

double ASpriteGetX(void *sprite_handle)
{
    ASprite * sprite = (ASprite*)sprite_handle;
    return sprite->getX();

}

static int ASpriteGetX_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
        double x = ASpriteGetX(lua_touserdata(L,1));
        lua_pushnumber(L,x);
    }
    return 1;
}

double ASpriteGetY(void *sprite_handle)
{
    ASprite * sprite = (ASprite*)sprite_handle;
    return sprite->getY();
}

double ASpriteGetWidth(void *sprite_handle)
{
    ASprite * sprite = (ASprite*)sprite_handle;
    return sprite->width();
}

double ASpriteGetHeight(void *sprite_handle)
{
    ASprite * sprite = (ASprite*)sprite_handle;
    return sprite->height();
}

static int ASpriteGetWidth_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
        double y = ASpriteGetWidth(lua_touserdata(L,1));
        lua_pushnumber(L,y);
    }
    else
    {
         AGE_LUA_ADD_DEBUGEDIT("ASPriteGetWidth(void *sprite)");
    }
    return 1;
}

static int ASpriteGetHeight_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
        double y = ASpriteGetHeight(lua_touserdata(L,1));
        lua_pushnumber(L,y);
    }
    else
    {
         AGE_LUA_ADD_DEBUGEDIT("ASPriteGetHeight(void *sprite)");
    }
    return 1;
}

static int ASpriteGetY_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
        double y = ASpriteGetY(lua_touserdata(L,1));
        lua_pushnumber(L,y);
    }
    else
    {
         AGE_LUA_ADD_DEBUGEDIT("ASPriteGetY(void *sprite)");
    }
    return 1;
}

void ASpriteRotate(void *sprite_handle, double angle)
{
    ASprite * sprite= (ASprite* )sprite_handle;
    sprite->rotate(angle);
}


static int ASpriteRotate_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1) && lua_isnumber(L,2))
    {
    ASpriteRotate(lua_touserdata(L,1),lua_tonumber(L,2));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("ASpriteRotate_bind(void* sprite,int rotate)");
    }
    return 0;
}


void ASpriteColor(void *sprite_handle, double r, double g, double b, double a)
{
    ASprite * sprite= (ASprite* )sprite_handle;
    sprite->setColor(r,g,b);
    sprite->setAlpha(a);
}

static int ASpriteColor_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1) && lua_isnumber(L,2)
            &&lua_isnumber(L,3)&& lua_isnumber(L,4)&&lua_isnumber(L,5))
    {
    ASpriteColor(lua_touserdata(L,1),lua_tonumber(L,2),lua_tonumber(L,3),lua_tonumber(L,4),lua_tonumber(L,5));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("ASpriteRotate(void* sprite,float r,float g,float b,float a)");
    }
    return 0;
}



void ASpriteBindTexture(void *sprite_handle, void *texture_handle)
{
    ASprite * sprite= (ASprite* )sprite_handle;
    ATexture * texture= (ATexture * )texture_handle;
    sprite->bindTexture(texture);
}

static int ASpriteBindTexture_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1) && lua_islightuserdata(L,2))
    {
    ASpriteBindTexture(lua_touserdata(L,1),lua_touserdata(L,2));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("ASpriteBindTexture(void* sprite,void *texture)");


    }
    return 0;
}

void ASpriteDestory(void *sprite_handle)
{
    ASprite * sprite= (ASprite* )sprite_handle;
    delete sprite;
}

static int ASpriteDestory_bind(lua_State *L)
{

    if(lua_islightuserdata(L,1))
    {
    ASpriteDestory(lua_touserdata(L,1));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("ASpriteDestory(void* sprite,void *texture)");
    }
    return 0;
}

void ASpriteRender(void *sprite_handle)
{

    ASprite * sprite= (ASprite* )sprite_handle;
    sprite->render();
}

static int ASpriteRender_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
    ASpriteRender(lua_touserdata(L,1));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("ASpriteDestroy(void* sprite)");
    }
    return 0;
}



void *ATextCreate(int size, int maxw, int maxh, const char *ttfFileName)
{
        AFont * font=new AFont(size,maxw,maxh,ttfFileName);
        return (void * )font;
}

static int ATextCreate_bind(lua_State *L)
{
    if(lua_isnumber(L,1)&&lua_isnumber(L,2)&&lua_isnumber(L,3)&&lua_isstring(L,4))
    {
    void * font=ATextCreate(lua_tointeger(L,1),lua_tointeger(L,2),lua_tointeger(L,3),
                            lua_tostring(L,4));
    error_font = font;
    lua_pushlightuserdata(L,font);
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("ATextCreate(int size,int maxw.int maxh,const char*ttfFileName)");
        //错误恢复
        QString fontPath;
        switch(ALua::getSystemID())
        {
        case ANDROID_EXTERNAL_STORAGE:
            fontPath = "/system/fonts/DroidSansFallback.ttf";
            break;
        case ANDROID_BUILT_IN:
            fontPath = "/system/fonts/DroidSansFallback.ttf";
        case WINDOWS:
            fontPath = "C:/Windows/fonts/simhei.ttf";
        }
        void * font=ATextCreate(24,50,50,
                                fontPath.toStdString().data());
        error_font = font;
        lua_pushlightuserdata(L,font);
    }
    return 1;
}

void ATextDraw(void *text_handle, int pos_x, int pos_y, const char *string)
{
        AFont * font=(AFont*) text_handle;
        font->draw(string,pos_x,pos_y);
}
static int ATextDraw_bind(lua_State *L)
{
    static int count = 0;
    if(lua_islightuserdata(L,1)&&lua_isnumber(L,2)&&lua_isnumber(L,3)&&lua_isstring(L,4))
    {
        ATextDraw(lua_touserdata(L,1),lua_tointeger(L,2),lua_tointeger(L,3),lua_tostring(L,4));
    }
    else
    {
        if(count<1)
        {
            AGE_LUA_ADD_DEBUGEDIT("ATextDraw(void *text_handle,int pos_x,int pos_y, const char *string");
        }
        ATextDraw(error_font,0,0,"error");
    }
    count++;
    return 0;
}



void *AAudioCreate(const char *string)
{
    AAudio * audio=new AAudio(string);
    return (void *)audio;
}

static int AAudioCreate_bind(lua_State *L)
{
    if(lua_isstring(L,1))
    {
     void *handle= AAudioCreate(lua_tostring(L,1));
     lua_pushlightuserdata(L,handle);
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("AAudioCreate(const char* string)");
    }
    return 1;
}


void AAudioPlay(void *audio_handle)
{
    AAudio * audio=(AAudio *)audio_handle;
    audio->play();
}

static int AAudioPlay_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
     AAudioPlay(lua_touserdata(L,1));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("AAudioPlay(void *audio_handle)");
    }
    return 0;
}



void AAudioPause(void *audio_handle)
{
    AAudio * audio=(AAudio *)audio_handle;
    audio->pause();
}

static int AAudioPause_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
     AAudioPause(lua_touserdata(L,1));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("AAudioPause(void *audio_handle)");
    }
    return 0;
}

void AAudioStop(void *audio_handle)
{
    AAudio * audio=(AAudio *)audio_handle;
    audio->stop();
}

static int AAudioStop_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1))
    {
     AAudioStop(lua_touserdata(L,1));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("AAudioStop(void *audio_handle)");
    }
    return 0;
}

void AAudioSetVolume(void *audio_handle,int volume)
{
    AAudio * audio=(AAudio *)audio_handle;
    audio->setVolume(volume);
}


static int AAudioSetVolume_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1)&&lua_isnumber(L,2))
    {
     AAudioSetVolume(lua_touserdata(L,1),lua_tointeger(L,2));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("AAudioSetVolume(void *audio_handle,int volume)");
    }
    return 0;
}


void AAudioLoop(void *audio_handle, int is_loop)
{
        AAudio * audio=(AAudio *)audio_handle;
        audio->setLoopORnot((bool)is_loop);
}


static int AAudioLoop_bind(lua_State *L)
{
    if(lua_islightuserdata(L,1)&&lua_isnumber(L,2))
    {
     AAudioSetVolume(lua_touserdata(L,1),lua_tointeger(L,2));
    }
    else
    {
        AGE_LUA_ADD_DEBUGEDIT("void AAudioLoop(void *audio_handle, int is_loop)");
    }
    return 0;
}


static int AGetSystemId(lua_State *L)
{
    qDebug()<<ALua::getSystemID();
    lua_pushnumber(ALua::getLua(),ALua::getSystemID());
    return 1;
}

static const char * APath_native()
{
        QString modstr(mod_string);
        qDebug()<<ALua::getSystemID();
        QString temp ;
        switch(ALua::getSystemID())
        {
        case 1:
        {
             temp = "./AGE2D/mods/"+modstr+"/";
            qDebug()<<"windows:"<<temp;
            break;
        }
        case 2:
        {
         temp = "/storage/emulated/0/AGE2D/mods/"+modstr+"/";
        qDebug()<<temp;
        break;
        }
        case 3:
        {
         temp = "/sdcard/AGE2D/mods/"+modstr+"/";
        qDebug()<<temp;
        break;
        }

        }
    return temp.toStdString().c_str();
}
void AGame(const char *str)
{
    strcpy(mod_string,str);
    char temp[10000];
    strcpy(temp,APath_native());
    strcat(temp,"main.lua");
    AGE_LUA_DEBUG_2(luaL_dofile(ALua::getLua(),temp));
}

int AGame_bind(lua_State *L)
{
    if(lua_isstring(L,1))
    {
        AGame(lua_tostring(L,1));
    }
    return 0;
}

static int Aprint(lua_State *L)
{
        int iStringCount=lua_gettop(L);
        int i;
        for(i=1 ; i<=iStringCount ; i++){
            if(lua_isstring(L,i)){
                const char * temp = lua_tostring(L,i);
                ALua::addDebugInfo(QString(temp));
            }else
                if(lua_isnumber(L,i))
            {
                    float temp = lua_tonumber(L,i);
                    ALua::addDebugInfo(QString("%f").arg(temp));
            }
            else if(lua_isboolean(L,i))
                {
                    int boolean=lua_toboolean(L,i);
                    if(boolean)
                    {
                        ALua::addDebugInfo("true");
                    }else
                    {
                        ALua::addDebugInfo("false");
                    }
                }
            else if(lua_isnoneornil(L,i))
                {
                    ALua::addDebugInfo("NULL");
                }
        }

        return 0;
}

static int APath(lua_State *L)
{

    if(lua_isstring(L,1))
    {
        const char * str = lua_tostring(L,1);
        qDebug()<<str;
        QString qstr(str);
        QString modstr(mod_string);
        qDebug()<<ALua::getSystemID();
        switch(ALua::getSystemID())
        {
        case 1:
        {
            QString temp = "./AGE2D/mods/"+modstr+"/"+ qstr;
            qDebug()<<"windows:"<<temp;
            lua_pushstring(ALua::getLua(),temp.toStdString().data());
            break;
        }
        case 2:
        {
        QString temp = "/storage/emulated/0/AGE2D/mods/"+modstr+"/"+qstr;
        qDebug()<<temp;
        lua_pushstring(ALua::getLua(),temp.toStdString().data());
        break;
        }
        case 3:
        {
        QString temp = "/sdcard/AGE2D/mods/"+modstr+"/"+ qstr;
        qDebug()<<temp;
        lua_pushstring(ALua::getLua(),temp.toStdString().data());
        break;
        }

        }
    }
    else
    {
        //qDebug()<<"输入的不是字符串";
        ALua::addDebugInfo(QString("error:")+"输入的不是字符串");
        return 0;
    }
    return 1;
}
void ASetSize(int w, int h)
{
    ASystem::SetSize(w,h);
}


static int ASetSize_bind(lua_State *L)
{
    if(lua_isnumber(L,1)&&lua_isnumber(L,2))
    {
        ASetSize(lua_tointeger(L,1),lua_tointeger(L,2));
    }
    return 0;
}


int ATimeStep()
{
    return ASystem::TimeStep();
}

static int ATimeStep_bind(lua_State * L)
{

    lua_pushinteger(L,ATimeStep());
    return 1;
}

void *APolygon2DCreate()
{
    APolygon * polygon=new APolygon();
    return (void *) polygon;
}

static int APolygon2DCreate_bind(lua_State * L)
{
    lua_pushlightuserdata(L,APolygon2DCreate());
    return 1;
}

void APolygon2DAdd(void *polygon_handle, int x, int y)
{
    APolygon * polygon=(APolygon*)polygon_handle;
    polygon->addPoint(AVector2D(x,y));
}

static int APolygon2DAdd_bind(lua_State * L)
{
    if(lua_isuserdata(L,1)&&lua_isnumber(L,2)&&lua_isnumber(L,3))
    {
            APolygon2DAdd(lua_touserdata(L,1),lua_tointeger(L,2),lua_tointeger(L,3));
    }
    return 0;
}

int APolygonIn(void *polygon_handle, int x, int y)
{
   APolygon * polygon=(APolygon*)polygon_handle;
   return polygon->pointInPolygon(AVector2D(x,y));
}
static int APolygonIn_bind(lua_State * L)
{
    if(lua_isuserdata(L,1)&&lua_isnumber(L,2)&&lua_isnumber(L,3))
    {
            lua_pushinteger(L,APolygonIn(lua_touserdata(L,1),lua_tointeger(L,2),lua_tointeger(L,3)));
    }
    return 1;
}

static int Version(lua_State *L)
{
    qDebug()<<"AGE Version alpha-v0.1";
    qDebug()<<"QQ::anehta@mengcode.com";
    qDebug()<<"http://www.mengcode.com/AGE/annotated.html";
    return 0;
}

static int ASetWidgetSize(lua_State *L)
{
    int count = lua_gettop(ALua::getLua());
    if(lua_isnumber(L,1) && lua_isnumber(L,2))
    {
        int x,y;
        x = lua_tonumber(L,1);
        y = lua_tonumber(L,2);
        ASystem::SetSize(x,y);
        qDebug()<<"set window "<<x<<":"<<y;
    }
    else
    {
        qDebug()<<"参数错误ASetWidgetSize(x,y)";
    }
    return 0;
}

static int AShowDebugEdit(lua_State *)
{
    ASystem::ShowLuaEdit();
    return 0;
}

static int AHideDebugEdit(lua_State *)
{
    ASystem::HideLuaEdit();
    return 0;
}

static int ASetDebugEditSize(lua_State * L)
{
    int count = lua_gettop(ALua::getLua());
    if(lua_isnumber(L,1) && lua_isnumber(L,2))
    {
        int x,y;
        x = lua_tonumber(L,1);
        y = lua_tonumber(L,2);
        ASystem::SetLuaEditSize(x,y);
        qDebug()<<"set Debug window "<<x<<":"<<y;
    }
    else
    {
        qDebug()<<"参数错误ASetDebugEditSize(x,y)";
        ALua::addDebugInfo(QString("参数错误ASetDebugEditSize(x,y)"));
    }
    return 0;
}

void ARegisterToLua()
{

    lua_register(ALua::getLua(),"version",Version);
    lua_register(ALua::getLua(),"tzw",Aprint);
    lua_register(ALua::getLua(),"MiaoPaSi",Aprint);
    lua_register(ALua::getLua(),"Anehta",Aprint);
    lua_register(ALua::getLua(),"APrint",Aprint);
    lua_register(ALua::getLua(),"APath",APath);
    lua_register(ALua::getLua(),"ASetDebugEditSize",ASetDebugEditSize);
    lua_register(ALua::getLua(),"AShowDebugEdit",AShowDebugEdit);
    lua_register(ALua::getLua(),"AHideDebugEdit",AHideDebugEdit);
    lua_register(ALua::getLua(),"ASetWidgetSize",ASetWidgetSize);
    lua_register(ALua::getLua(),"AGetSystemId",AGetSystemId);

    lua_register(ALua::getLua(),"ATextureCreate",ATextureCreate_bind);
    lua_register(ALua::getLua(),"ASpriteCreate",ASpriteCreate_bind);
    lua_register(ALua::getLua(),"ASpriteSetSize",ASpriteSetSize_bind);
    lua_register(ALua::getLua(),"ASpriteSetPos",ASpriteSetPos_bind);
    lua_register(ALua::getLua(),"ASpriteRotate",ASpriteRotate_bind);
    lua_register(ALua::getLua(),"ASpriteColor",ASpriteColor_bind);
    lua_register(ALua::getLua(),"ASpriteBindTexture",ASpriteBindTexture_bind);
    lua_register(ALua::getLua(),"ASpriteDestory",ASpriteDestory_bind);
    lua_register(ALua::getLua(),"ASpriteRender",ASpriteRender_bind);
    lua_register(ALua::getLua(),"ASpriteGetX",ASpriteGetX_bind);
    lua_register(ALua::getLua(),"ASpriteGetY",ASpriteGetY_bind);
    lua_register(ALua::getLua(),"ASpriteGetWidth",ASpriteGetWidth_bind);
    lua_register(ALua::getLua(),"ASpriteGetHeight",ASpriteGetWidth_bind);

    lua_register(ALua::getLua(),"ATextCreate",ATextCreate_bind);
    lua_register(ALua::getLua(),"ATextDraw",ATextDraw_bind);
    lua_register(ALua::getLua(),"AAudioCreate",AAudioCreate_bind);
    lua_register(ALua::getLua(),"AAudioPlay",AAudioPlay_bind);
    lua_register(ALua::getLua(),"AAudioPause",AAudioPause_bind);
    lua_register(ALua::getLua(),"AAudioStop",AAudioStop_bind);
    lua_register(ALua::getLua(),"AAudioSetVolume",AAudioSetVolume_bind);
    lua_register(ALua::getLua(),"AAudioLoop",AAudioLoop_bind);
    lua_register(ALua::getLua(),"AGame",AGame_bind);
    lua_register(ALua::getLua(),"ASetSize",ASetSize_bind);
    lua_register(ALua::getLua(),"ATimeStep",ATimeStep_bind);
    lua_register(ALua::getLua(),"APolygon2DCreate",APolygon2DCreate_bind);
    lua_register(ALua::getLua(),"APolygon2DAdd",APolygon2DAdd_bind);
    lua_register(ALua::getLua(),"APolygonIn",APolygonIn_bind);
}











}
