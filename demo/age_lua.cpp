#include "age_lua.h"
#include <QDebug>
#include <QDir>
#include <QString>

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
        luaL_dofile(L,temp.toStdString().data());      
    }
    else
    {
        if(QDir("/storage/emulated/0").exists())
        {
            qDebug()<<"android system | External storage";
            QString temp = "/storage/emulated/0/" + second;
            system_id = ANDROID_EXTERNAL_STORAGE;
            luaL_dofile(L,temp.toStdString().data());
        }
        else
        {
            if(QDir("/sdcard").exists())
            {
                qDebug()<<"android system | Built-in storage";
                QString temp = "/sdcard/" + second;
                system_id = ANDROID_BUILT_IN;
                luaL_dofile(L,temp.toStdString().data());

            }
        }
    }

    luaL_dofile(L,string);
    m_isExecute = true;
}

void ALua::close()
{
    lua_close(L);
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
