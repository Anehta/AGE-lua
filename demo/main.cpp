#include "../include/age_system.h"
#include <../include/age_scene.h>
#include <../include/age_eventmgr.h>
#include <../include/age_sprite.h>

extern "C" {
#include <../lua_src/lua.h>
#include <../lua_src/lualib.h>
#include <../lua_src/lauxlib.h>
}

#include "game.h"

lua_State *L;

int PrintStringList(lua_State *)
{
    qDebug()<<"C++函数输出";
    int iStringCount=lua_gettop(L);
    int i;
    for(i=1 ; i<=iStringCount ; i++){
        if(!lua_isstring(L,1)){
            qDebug()<<"Invalid string.";
        }else{
            qDebug()<<lua_tostring(L,i);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    qDebug()<<"你麻痹";
    QFile file(":/fuck.lua");
    file.copy(QDir::currentPath()+"/"+"fuck.lua");
    qDebug()<<QDir::currentPath()+"/"+"fuck.lua";
    L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L,"PrintStringList",PrintStringList);
    qDebug()<<"导出";
    luaL_dofile(L,"fuck.lua");
    lua_close(L);
    ASystem::Init (argc,argv);
	Game::Init ();
    return ASystem::Go();
}
