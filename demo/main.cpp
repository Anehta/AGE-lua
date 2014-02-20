#include "../include/age_system.h"
#include <../include/age_scene.h>
#include <../include/age_eventmgr.h>
#include <../include/age_sprite.h>
#include <age_interface.h>
#include <age_lua.h>
#include "game.h"
#include <QDir>

lua_State *L;


int main(int argc, char *argv[])
{
    ASystem::Init (argc,argv);
    ALua::init();
    ARegisterToLua();
    if(argc==2)
        {
        ALua::execute(argv[1]);
    }
    else
    {
        ALua::execute("AGE2D/entry.lua");
    }
    return ASystem::Go();
}
