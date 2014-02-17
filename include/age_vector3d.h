#ifndef AVECTOR3D_H
#define AVECTOR3D_H

#include <QVector3D>
namespace AGE2D{

class AVector2D;
class AVector4D;
class APointF;
class APoint;

class AVector3D : public QVector3D
{
public:
    AVector3D();
    AVector3D(float,float,float);
    AVector3D(const APoint &point);
    AVector3D(const APointF &point);
    AVector3D(const AVector2D & vector);
    AVector3D(const AVector2D & vector,float zpos);
    AVector3D(const AVector4D & vector);
};
}


#endif // AVECTOR3D_H
