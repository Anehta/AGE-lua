#include <../include/age_vector2d.h>

namespace AGE2D
{
AVector2D::AVector2D()
{
}

AVector2D::AVector2D(const APoint &point)
{
    setX(point.x());
    setY(point.y());
}

AVector2D::AVector2D(const AVector3D &vector)
{
    setX(vector.x());
    setY(vector.y());
}

AVector2D::AVector2D(const AVector4D &vector)
{
    setX(vector.x());
    setY(vector.y());
}

AVector2D::AVector2D(float xpos, float ypos)
{
    setX(xpos);
    setY(ypos);
}
}

