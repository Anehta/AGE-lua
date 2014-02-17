#include <../include/age_vector4d.h>

namespace AGE2D
{
AVector4D::AVector4D()
{

}

AVector4D::AVector4D(const QVector4D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(vector.z());
    setW(vector.w());
}

AVector4D::AVector4D(float xpos, float ypos, float zpos, float wpos)
{
    setX(xpos);
    setY(ypos);
    setZ(zpos);
    setW(wpos);
}

AVector4D::AVector4D(const APoint &point)
{
    setX(point.x());
    setY(point.y());
    setZ(0);
    setW(0);
}

AVector4D::AVector4D(const APointF &point)
{
    setX(point.x());
    setY(point.y());
    setZ(0);
    setW(0);
}

AVector4D::AVector4D(const AVector2D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(0);
    setW(0);
}

AVector4D::AVector4D(const AVector2D &vector,float zpos,float wpos)
{
    setX(vector.x());
    setY(vector.y());
    setZ(zpos);
    setW(wpos);
}

AVector4D::AVector4D(const AVector3D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(vector.z());
    setW(0);
}

AVector4D::AVector4D(const AVector3D &vector,float wpos)
{
    setX(vector.x());
    setY(vector.y());
    setZ(vector.z());
    setW(wpos);
}
}

