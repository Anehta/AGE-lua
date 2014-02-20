#include "age_lua.h"
#include <QDebug>
#include <QDir>
#include <QString>
#include <../include/age_system.h>

namespace AGE2D {
lua_State *ALua::L;
static bool m_isExecute = false;
static SystemID system_id;

void ALua::init()
{
    L = luaL_newstate();
    luaL_openlibs(L);
}

bool ALua::is_execute()
{
    return m_isExecute;
}

void ALua::execute(const char *string)
{
    QString second(string);

    if(QDir("C:/Windows").exists())
    {
        qDebug()<<"windows system";
        QString temp = "./" + second;
        system_id = WINDOWS;
        AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
    }
    else
        if(QDir("/storage/emulated/0").exists())
        {
            qDebug()<<"android system | build-in  storage";
            QString temp = "/storage/emulated/0/" + second;
            system_id = ANDROID_BUILT_IN ;
            AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
        }
        else
            if(QDir("/sdcard").exists())
            {
                qDebug()<<"android system | External storage";
                QString temp = "/sdcard/" + second;
                system_id = ANDROID_EXTERNAL_STORAGE;
                AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));

            }
        else if(QDir("/mnt/sdcard").exists())
            {
                qDebug()<<"android system | mount disk";
                QString temp = "/mnt/sdcard/" + second;
                system_id = ANDROID_EXTERNAL_STORAGE;
                AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
            }
    else
            {
            AGE_LUA_DEBUG_2(luaL_dofile(L,string));
            }
    m_isExecute = true;
}

void ALua::printDebugError(lua_State* L,int sErr)
{
    if(sErr == 0)
    {
        return;
    }

    const char* error;
      switch(sErr)
      {
      case LUA_ERRSYNTAX://编译时错误
          /*const char *buf = "mylib.myfun()2222";类似这行语句可以引起编译时错误*/
          qDebug()<<"------syntax error during pre-compilation------";
          addDebugInfo(QString("------syntax error during pre-compilation------"));
          break;
      case LUA_ERRMEM://内存错误
          qDebug()<<"------memory allocation error------";
          addDebugInfo(QString("------memory allocation error------"));
          break;
      case LUA_ERRRUN://运行时错误
          qDebug()<<"------a runtime error------";
          addDebugInfo(QString("------a runtime error------"));
          break;
      case LUA_YIELD://线程被挂起错误
          qDebug()<<"------Thread has Suspended------";
          addDebugInfo(QString("------Thread has Suspended------"));
          break;
      case LUA_ERRERR://在进行错误处理时发生错误
          qDebug()<<"------error while running the error handler function-------";
          addDebugInfo(QString("------error while running the error handler function-------"));
          break;
      default:
          break;
      }
      error = lua_tostring(L, -1);//打印错误结果
      qDebug()<<error;
      addDebugInfo(QString(error));
      qDebug()<<"--------End--------";
      addDebugInfo(QString("--------End--------"));
}

void ALua::close()
{
    lua_close(L);
}

void ALua::addDebugInfo(QString str)
{
    ASystem::AddDebugInfo(str);
}

SystemID ALua::getSystemID()
{
    return system_id;
}

lua_State *ALua::getLua()
{
    return L;
}

ALua::ALua()
{


}
}
