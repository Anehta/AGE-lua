#ifndef AGE_LUA_H
#define AGE_LUA_H

#include <QString>

extern "C" {
#include <../lua_src/lua.h>
#include <../lua_src/lualib.h>
#include <../lua_src/lauxlib.h>
}

#define AGE_LUA_DEBUG(a) if(a){const char* error = lua_tostring(ALua::getLua(), -1);qDebug()<<"error:"<<error;qDebug()<<"debug-complate";}
#define AGE_LUA_DEBUG_2(a) ALua::printDebugError(ALua::getLua(),a);
namespace AGE2D {

enum SystemID
{
    WINDOWS = 1,
    ANDROID_BUILT_IN = 2,
    ANDROID_EXTERNAL_STORAGE = 3,
    ANDROID_MOUNT_DISK=4,
    IOS = 5,
    MAC = 6,
    LINUX = 7
};

class ALua
{
public:
  static void init();
  static void execute(const char * string);
  static void close();
  static lua_State * getLua();
  static bool is_execute();
  static SystemID getSystemID();
  static void printDebugError(lua_State* L,int sErr);
  static void addDebugInfo(QString str);
private:
    ALua();
   static lua_State *L;
};


}


#endif // AGE_LUA_H
