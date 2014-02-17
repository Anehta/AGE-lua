#include <../include/age_pointf.h>
#include <../include/age_point.h>

namespace AGE2D
{
APointF::APointF()
{
}

APointF::APointF(float x,float y)
{
    setX(x);
    setY(y);
}

APointF::APointF(const APoint point)
{
    setX(point.x());
    setY(point.y());
}

}
