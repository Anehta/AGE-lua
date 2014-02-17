#include "wavecontroler.h"

#include "../include/age_system.h"
#include "wave.h"
#include "qdebug.h"
using namespace AGE2D;
WaveControler::WaveControler()
{
	rush_time=new AAccumulator(0,100,0.01,false);

}

void WaveControler::beforeFrameRender()
{

}

void WaveControler::afterFrameRender()
{
	rush_time->step (ASystem::TimeStep ());
	if(rush_time->isTouched ())
	{

		qDebug()<<"rock & roll!!!";
		Wave();
		rush_time->rewind ();
	}
}
