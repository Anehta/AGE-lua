#ifndef AVECTOR4D_H
#define AVECTOR4D_H

#include <QVector4D>
#include "age_vector2d.h"
#include "age_vector3d.h"
#include "age_point.h"
#include "age_pointf.h"
namespace AGE2D
{
class APoint;
class APointF;
class AVector2D;
class AVector3D;
class AVector4D : public QVector4D
{
public:
    AVector4D();
    AVector4D(const QVector4D & vector);
    AVector4D(float xpos,float ypos,float zpos,float wpos);
    AVector4D(const APoint & point);
    AVector4D(const APointF & point);
    AVector4D(const AVector2D & vector);
    AVector4D(const AVector2D &vector,float zpos,float wpos);
    AVector4D(const AVector3D &vector);
    AVector4D(const AVector3D &vector,float wpos);
};
}


#endif // AVECTOR4D_H
