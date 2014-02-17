#include <../include/age_vector3d.h>
#include <../include/age_point.h>
#include <../include/age_pointf.h>
#include <../include/age_vector2d.h>
#include <../include/age_vector3d.h>
#include <../include/age_vector4d.h>
namespace AGE2D
{
AVector3D::AVector3D()
{
}

AVector3D::AVector3D(float x, float y, float z)
{
    setX(x);
    setY(y);
    setZ(z);
}

AVector3D::AVector3D(const APoint &point)
{
    setX(point.x());
    setY(point.y());
}

AVector3D::AVector3D(const APointF &point)
{
    setX(point.x());
    setY(point.y());
    setZ(0);
}

AVector3D::AVector3D(const AVector2D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(0);
}

AVector3D::AVector3D(const AVector2D &vector, float zpos)
{
    setX(vector.x());
    setY(vector.y());
    setZ(zpos);

}

AVector3D::AVector3D(const AVector4D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(0);
}

}
