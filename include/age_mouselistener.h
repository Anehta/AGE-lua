#ifndef AMOUSELISTENER_H
#define AMOUSELISTENER_H

#include "age_mouseinfo.h"

namespace AGE2D {
class AMouseListener
{
	friend class AEventMgr;
public:
	AMouseListener();
protected:

	virtual void onMouseRelease(AMouseInfo info);
	virtual void onMousePress(AMouseInfo info);
	virtual void onMouseMove(AMouseInfo info);
};
}


#endif // AMOUSELISTENER_H
