#ifndef WAVECONTROLER_H
#define WAVECONTROLER_H
#include "../include/age_framelistener.h"
#include "../include/age_accumulator.h"
class WaveControler : public AGE2D::AFrameListener
{
public:
	WaveControler();
	virtual void beforeFrameRender();
	virtual void afterFrameRender();
protected:
	AGE2D::AAccumulator * rush_time;
};

#endif // WAVECONTROLER_H
