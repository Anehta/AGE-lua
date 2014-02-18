#include "age_lua.h"
#include <QDebug>
#include <QDir>
#include <QString>

namespace AGE2D {
lua_State *ALua::L;
static bool m_isExecute = false;

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
    QString str(string);
    QFile file(string);

    if(file.exists())
    {
        qDebug()<<str<<"存在";
    }
    else
    {
        qDebug()<<str<<"不存在";
    }

    QString path(QDir::currentPath()+"/"+str.remove(":/"));
    qDebug()<<QDir::currentPath();
    file.copy(path);

    QFile text(path);
    if(text.exists())
    {
        qDebug()<<str<<"拷贝成功";
    }
    else
    {
        qDebug()<<str<<"拷贝失败";
    }

    qDebug()<<str.remove(":/").toStdString().data();
    luaL_dofile(L,str.remove(":/").toStdString().data());
    m_isExecute = true;
}

void ALua::close()
{
    lua_close(L);
}

lua_State *ALua::getLua()
{
    return L;
}

ALua::ALua()
{


}

}
