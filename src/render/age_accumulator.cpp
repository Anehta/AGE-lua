#include <../include/age_accumulator.h>

namespace AGE2D {
AAccumulator::AAccumulator(double init_value, double end_value, double speed, bool is_cycled)
{
	this->init_value=init_value;
	this->end_value=end_value;
	this->value=this->init_value;
	this->speed=speed;
	this->is_cycled=is_cycled;
	is_touched=false;
}

void AAccumulator::step(double factor)
{

	value+=factor*speed;
	if(value>=end_value)
	{
		if(is_cycled)
		{
			value=init_value;
		}
		else
		{
			value=end_value;
			is_touched=true;
		}
	}
}

double AAccumulator::currentValue()
{
	return value;
}

void AAccumulator::setInitValue(double init_value)
{
	this->init_value=init_value;
}

void AAccumulator::setEndValue(double end_value)
{
	this->end_value=end_value;
}

void AAccumulator::setSpeed(double speed)
{
	this->speed=speed;
}

void AAccumulator::setIsCycled(bool new_bool)
{
	this->is_cycled=new_bool;
}

double AAccumulator::getInitValue()
{
	return this->init_value;
}

double AAccumulator::getEndValue()
{
	return this->end_value;
}

double AAccumulator::getSpeed()
{
	return this->speed;
}

bool AAccumulator::isCycled()
{
	return this->is_cycled;
}

bool AAccumulator::isTouched()
{
	return is_touched;
}

void AAccumulator::rewind()
{
	is_touched=false;
	value=init_value;
}

}
