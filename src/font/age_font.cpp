#include "../include/age_font.h"
#include <QDir>

using namespace AGE2D;

void repairChar(wchar_t i,AFontSprite* sprite);

AFont::AFont()
{
}

xCharTexture::xCharTexture()
{
    m_texID  = 0;
    m_chaID  = 0;
    m_Width  = 0;
    m_Height = 0;
}

xCharTexture * g_TexID = new xCharTexture[65536];
//AFontSprite * sprite = new AFontSprite[65536];

xFreeTypeLib::xFreeTypeLib()
{
    if (FT_Init_FreeType( &m_FT2Lib) )
        exit(0);
}

void xFreeTypeLib::load(const char* font_file , int _w , int _h)
{
    //加载一个字体,取默认的Face,一般为Regualer
    if (FT_New_Face( m_FT2Lib, font_file, 0, &m_FT_Face ))
    {
        getchar();
        qDebug()<<"error in load font file";
        exit(0);
    }
    FT_Select_Charmap(m_FT_Face, FT_ENCODING_UNICODE);

    m_w = _w ;
    m_h = _h;
    //m_FT_Face->num_fixed_sizes;
    //大小要乘64.这是规定。照做就可以了。
    FT_Set_Char_Size( m_FT_Face , 0 , m_w << 6, 96, 96);
    FT_Set_Pixel_Sizes(m_FT_Face,m_w, m_h);
    qDebug()<<"载入字体成功";
}

GLuint xFreeTypeLib::loadChar(wchar_t ch,int &w,int &h)
{
    if(g_TexID[ch].m_texID)
    {
        w = g_TexID[ch].m_Width;
        h = g_TexID[ch].m_Height;
        return g_TexID[ch].m_texID;
    }

    if(FT_Load_Char(m_FT_Face, ch,FT_LOAD_RENDER|FT_LOAD_FORCE_AUTOHINT|
                    (true ? FT_LOAD_TARGET_NORMAL : FT_LOAD_MONOCHROME | FT_LOAD_TARGET_MONO) )   )
    {
        qDebug()<<ch<<"读取字符出错";
        return 0;
    }


    xCharTexture& charTex = g_TexID[ch];

    //得到字模
    FT_Glyph glyph;
    if(FT_Get_Glyph( m_FT_Face->glyph, &glyph ))
        return 0;

    //转化成位图
    FT_Render_Glyph( m_FT_Face->glyph,   FT_RENDER_MODE_LCD );//FT_RENDER_MODE_NORMAL  );
    FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
    FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;

    //取道位图数据
    FT_Bitmap& bitmap=bitmap_glyph->bitmap;

    //把位图数据拷贝自己定义的数据区里.这样旧可以画到需要的东西上面了。
    int width  =  bitmap.width;
    int height =  bitmap.rows;

    m_FT_Face->size->metrics.y_ppem;
    m_FT_Face->glyph->metrics.horiAdvance;

    charTex.m_Width = width;
    charTex.m_Height = height;
    charTex.m_adv_x = m_FT_Face->glyph->advance.x / 64;
    charTex.m_adv_y = m_FT_Face->size->metrics.y_ppem; //m_FT_Face->glyph->metrics.horiBearingY / 64.0f;
    charTex.m_delta_x = bitmap_glyph->left;
    charTex.m_delta_y = bitmap_glyph->top - height;

    glGenTextures(1,&charTex.m_texID);
    glBindTexture(GL_TEXTURE_2D,charTex.m_texID);

    char* pBuf = new char[width * height * 4];
    for(int j=0; j  < height ; j++)
    {
        for(int i=0; i < width; i++)
        {
            unsigned char _vl =  (i>=bitmap.width || j>=bitmap.rows) ? 0 : bitmap.buffer[i + bitmap.width*j];
            pBuf[(4*i + (height - j - 1) * width * 4)  ] = 0xff;
            pBuf[(4*i + (height - j - 1) * width * 4)+1] = 0xff;
            pBuf[(4*i + (height - j - 1) * width * 4)+2] = 0xff;
            pBuf[(4*i + (height - j - 1) * width * 4)+3] = _vl;
        }
    }
    glTexImage2D( GL_TEXTURE_2D,0,GL_RGBA,width, height,0,GL_RGBA,GL_UNSIGNED_BYTE,pBuf);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

#ifdef GL_ES
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER_NV);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER_NV);
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
#elseif
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
#endif

#ifdef GL_ES
    float color[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR_NV, color);
#elseif
    float color[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
#endif
    w = width;
    h = height;

    delete[]pBuf;
    return charTex.m_chaID;
}

AFont::AFont(int size,int maxw,int maxh,const char* ttfFileName)
{
    init(size,maxw,maxh,ttfFileName);
}

void AFont::print(QString str,int x , int y,ALayer * layer)
{
    int sx = x;
    int sy = y;
    int maxH = m_h;

    wchar_t _strText[wcslen(str.toStdWString().data())+1];
    wcscpy(_strText,str.toStdWString().data());

    if(str == m_strbuffer)
    {
        //m_spriteBuffer.clear();
    }
    else
    {
        m_strbuffer = str;
        for(std::vector<AFontSprite*>::iterator it = m_spriteBuffer.begin();
            it != m_spriteBuffer.end();
            ++it)
        {
            AFontSprite * temp = *it;
            temp->destroy();
            //qDebug()<<"删除字符";
        }

        m_spriteBuffer.clear();
        //qDebug()<<str;
        for(unsigned int i = 0 ; i < wcslen(_strText) ; i++)
        {
            int width = 0,height =0;
            g_FreeTypeLib->loadChar(_strText[i],width,height);
            xCharTexture * pCharTex = &g_TexID[_strText[i]];
            AFontSprite * sprite = new AFontSprite();
            sprite->bindTexture(pCharTex->m_texID,g_TexID[_strText[i]].m_Width,g_TexID[_strText[i]].m_Height);
            sprite->setX(sx);
            sprite->setY(y);
            repairChar(_strText[i],sprite);
            sx+=sprite->width();
            m_spriteBuffer.push_back(sprite);
            sprite = NULL;
        }
        //qDebug()<<m_spriteBuffer.size();
        for(std::vector<AFontSprite*>::iterator it = m_spriteBuffer.begin();
            it != m_spriteBuffer.end();
            ++it)
        {
            AFontSprite * sprite = *it;
            layer->addChild(sprite);
            sprite = NULL;
        }
    }
}

void AFont::draw(QString str, int x, int y)
{
    int sx = x;
    int sy = y;
    int maxH = m_h;

    wchar_t _strText[wcslen(str.toStdWString().data())+1];
    wcscpy(_strText,str.toStdWString().data());

    if(str == m_strbuffer)
    {
        //m_spriteBuffer.clear();
    }
    else
    {
        m_strbuffer = str;
        for(std::vector<AFontSprite*>::iterator it = m_spriteBuffer.begin();
            it != m_spriteBuffer.end();
            ++it)
        {
            AFontSprite * temp = *it;
            temp->destroy();
        }
        m_spriteBuffer.clear();
        //qDebug()<<str;
        for(unsigned int i = 0 ; i < wcslen(_strText) ; i++)
        {
            int width = 0,height =0;
            g_FreeTypeLib->loadChar(_strText[i],width,height);
            xCharTexture * pCharTex = &g_TexID[_strText[i]];
            AFontSprite * sprite = new AFontSprite();
            sprite->bindTexture(pCharTex->m_texID,g_TexID[_strText[i]].m_Width,g_TexID[_strText[i]].m_Height);
            sprite->setX(sx);
            sprite->setY(y);
            repairChar(_strText[i],sprite);
            sx+=sprite->width();
            m_spriteBuffer.push_back(sprite);
            sprite = NULL;
        }
        //qDebug()<<m_spriteBuffer.size();

    }
    for(std::vector<AFontSprite*>::iterator it = m_spriteBuffer.begin();
        it != m_spriteBuffer.end();
        ++it)
    {
        AFontSprite * sprite = *it;
        sprite->render();
        sprite = NULL;
    }
}

void AFont::init(int size,int maxw,int maxh,const char* ttfFileName)
{
    g_FreeTypeLib = new xFreeTypeLib;
    m_w = maxw;
    m_h = maxh;
    m_size = size;
    m_ttfFileName = ttfFileName;
    g_FreeTypeLib->load(m_ttfFileName,m_w,m_h);
}

AFont::~AFont()
{
    //delete g_TexID;
}

AFontSprite::AFontSprite()
{

}

void AFontSprite::release()
{
    glDeleteBuffers(2,m_geometric.getVboId()); //1
    free(m_geometric.getVboId()); //2
}

void repairChar(wchar_t i,AFontSprite* sprite)
{
    switch (i) {
    case '+':
        sprite->setY(sprite->getY());
        break;
    case '-':
        sprite->setY(sprite->height()*3+sprite->getY());
        break;
    case '*':
        sprite->setY(sprite->height()+sprite->getY());
        break;
    case '`':
        sprite->setY(sprite->height()/2+sprite->getY());
        break;
    case '\"':
        sprite->setY(sprite->height()*3+sprite->getY());
        break;
    default:
        break;
    }
}
