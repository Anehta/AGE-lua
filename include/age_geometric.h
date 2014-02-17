#ifndef AGEOMETRIC_H
#define AGEOMETRIC_H

#include <QGLFunctions>

namespace AGE2D
{
class AGeometric : public QGLFunctions
{
public:
    AGeometric();
    ~AGeometric();
    void initRectGeometric();
    GLuint * getVboId();
    int width();
    int height();
    void setWidth(int w);
    void setHeight(int h);
    void setShowRect(int x1,int y1,int x2,int y2);
    void setImageWidth(int w);
    void setImageHeight(int h);
    void initParameter(int width,int height,int imageWidth,int imageHeight,int x1,int y1,int x2,int y2);
private:
    GLuint * m_vboId;
    int m_width;
    int m_height;
    int m_leftTopX;
    int m_leftTopY;
    int m_rightBottonX;
    int m_rightBottonY;
    int m_imageWidth;
    int m_imageHeight;
    void initializeAll();
};
}


#endif // AGEOMETRIC_H
