#ifndef APOINTF_H
#define APOINTF_H

#include <QPointF>

namespace AGE2D{
class APoint;

class APointF : public QPointF
{
public:
    APointF();
    APointF(float x,float y);
    APointF(const APoint point);
};

}

#endif // APOINTF_H
