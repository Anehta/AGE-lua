#include "wave.h"
#include "stdlib.h"
#include "../include/age_system.h"
#include "../include/age_vector2d.h"
#include "enemy.h"
using namespace AGE2D;
double lunch_point_x[]={140,220,300,380,460,540};
Wave::Wave()
{
	int type=ASystem::Random (1,3);

	switch(type)
	{


	case WAVE_STRAGHIT:





		break;
	case WAVE_CHARGE_FROM_LEFT:


		break;
	case WAVE_CHARGE_FROM_RIGHT:

		break;
	}


}
