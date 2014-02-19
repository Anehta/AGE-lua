#ifndef AGE_LUA_H
#define AGE_LUA_H


extern "C" {
#include <../lua_src/lua.h>
#include <../lua_src/lualib.h>
#include <../lua_src/lauxlib.h>
}

namespace AGE2D {

enum SystemID
{
    WINDOWS = 1,
    ANDROID_EXTERNAL_STORAGE = 2,
    ANDROID_BUILT_IN = 3,
    IOS = 4,
    MAC = 5,
    LINUX = 6
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
private:
    ALua();
   static lua_State *L;
};


}


#endif // AGE_LUA_H
