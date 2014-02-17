#ifndef APOLYGON_H
#define APOLYGON_H

#include <list>
#include <vector>
#include "age_vector2d.h"

namespace AGE2D
{
class AVector2D;
class APolygon
{
public:
    APolygon();
    int pointInPolygon(AVector2D);
    int pointInPolygon2(AVector2D);
    void addPoint(double x,double y);
    void addPoint(AVector2D vec);
private:
    std::vector<AVector2D> m_pointList;
    int IsIntersectAnt(double x,double y,double X1,double Y1,double X2,double Y2);
};

}

#endif // APOLYGON_H
