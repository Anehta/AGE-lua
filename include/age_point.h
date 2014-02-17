#ifndef APOINT_H
#define APOINT_H

#include <QPoint>

namespace AGE2D{
class APoint : public QPoint
{
public:
    APoint();
    APoint(int x,int y);
};
}


#endif // APOINT_H
