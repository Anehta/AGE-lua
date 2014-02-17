#ifndef AGE_FONT_H
#define AGE_FONT_H

#include "age_sprite.h"
#include <list>
#include <map>

#include "ft2build.h"
#include FT_FREETYPE_H
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>

namespace AGE2D {

struct xCharTexture : public QGLFunctions
{
    GLuint  m_texID;
    wchar_t m_chaID;
    int     m_Width;
    int     m_Height;

    int     m_adv_x;
    int     m_adv_y;
    int     m_delta_x;
    int     m_delta_y;
public:
    xCharTexture();
};

class xFreeTypeLib
{
    FT_Library m_FT2Lib;
    FT_Face    m_FT_Face;

    int   m_w;
    int   m_h;
public:
    xFreeTypeLib();

    void load(const char* font_file , int _w , int _h);
    GLuint loadChar(wchar_t ch,int &w,int &h);
};

class AFontSprite : public ASprite
{
public:
    AFontSprite();
protected:
    void release();
};

class AFont
{
public:
    AFont();
    AFont(int size,int maxw,int maxh,const char* ttfFileName);
    ~AFont();
    void init(int size,int maxw,int maxh,const char* ttfFileName);
    void print(QString str,int x , int y,ALayer * layer);
private:
    xFreeTypeLib *g_FreeTypeLib;
    int m_w;
    int m_h;
    int m_size;
    QString m_strbuffer;
    const char * m_ttfFileName;
    std::vector<AFontSprite*> m_spriteBuffer;
};



}
#endif // AGE_FONT_H
