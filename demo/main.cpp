#include "../include/age_system.h"
#include <../include/age_scene.h>
#include <../include/age_eventmgr.h>
#include <../include/age_sprite.h>
#include <age_interface.h>
#include <age_lua.h>
#include "game.h"

lua_State *L;

int DebugPrint(lua_State *L)
{
    int iStringCount=lua_gettop(L);
    int i;
    for(i=1 ; i<=iStringCount ; i++){

        if(lua_isstring(L,i)){
            qDebug()<<lua_tostring(L,i);
        }else
            if(lua_isnumber(L,i))
        {
                qDebug()<<lua_tonumber(L,i);
        }
        else if(lua_isboolean(L,i))
            {
                int boolean=lua_toboolean(L,i);
                if(boolean)
                {
                    qDebug()<<"true";
                }else
                {
                    qDebug()<<"false";
                }
            }
        else if(lua_isnoneornil(L,i))
            {
                qDebug()<<"NULL";
            }
    }
    return 0;
}

int main(int argc, char *argv[])
{

   // ALua::close();
    ASystem::Init (argc,argv);
    ALua::init();
    lua_register(ALua::getLua(),"tzw",DebugPrint);
    ARegisterToLua();
    ALua::execute(":/fuck.lua");
    Game::Init ();
    return ASystem::Go();
}
