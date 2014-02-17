#ifndef AKEYLISTENER_H
#define AKEYLISTENER_H

#include <QKeyEvent>
namespace AGE2D{
class AKeyListener
{
public:
	AKeyListener();
	virtual void onKeyRelease(QKeyEvent * event);
	virtual void onKeyPress (QKeyEvent *event);
};
}


#endif // AKEYLISTENER_H
