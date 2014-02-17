#include <../include/age_frame.h>
namespace AGE2D
{
AFrame::AFrame(AVector2D bl,AVector2D tr)
{
	this->bl=bl;
	this->tr=tr;
}

AVector2D AFrame::bottomLeft()
{
	return bl;
}

AVector2D AFrame::topRight()
{
	return tr;
}

}
