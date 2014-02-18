#ifndef AGE_LUA_H
#define AGE_LUA_H


extern "C" {
#include <../lua_src/lua.h>
#include <../lua_src/lualib.h>
#include <../lua_src/lauxlib.h>
}

namespace AGE2D {


class ALua
{
public:
  static void init();
  static void execute(const char * string);
  static void close();
  static lua_State * getLua();
  static bool is_execute();
private:
    ALua();
   static lua_State *L;
};
}


#endif // AGE_LUA_H
