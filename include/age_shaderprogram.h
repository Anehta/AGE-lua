#ifndef ASHADERPROGRAM_H
#define ASHADERPROGRAM_H

#include <QGLShaderProgram>
#include <QString>
#include <../include/age_shader.h>
namespace AGE2D{
class AShaderProgram : public QGLShaderProgram
{
public:
    AShaderProgram();
    AShaderProgram(QString vshaderFilename,QString fshaderFilename);
    bool addVertexShader(QString vshaderFilename);
    bool addFragmentShader(QString fshaderFilename);
    void initShaderEffect(int value);
};
}


#endif // ASHADERPROGRAM_H
