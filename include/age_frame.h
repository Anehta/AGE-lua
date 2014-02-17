#ifndef AFRAME_H
#define AFRAME_H
#include <../include/age_vector2d.h>

namespace AGE2D {
class AFrame
{
public:
	AFrame(AVector2D bl,AVector2D tr);
	AVector2D bottomLeft();
	AVector2D topRight();
protected:
	AVector2D bl;
	AVector2D tr;
};
}

#endif // AFRAME_H




