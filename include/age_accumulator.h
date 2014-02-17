#ifndef AACCUMULATOR_H
#define AACCUMULATOR_H

namespace AGE2D
{
//累加器
class AAccumulator
{
public:
	AAccumulator(double init_value=0,double end_value=100,double speed=0.01,bool is_cycled=true);
	void step(double factor=1);
	double currentValue();
	void setInitValue(double init_value);
	void setEndValue(double end_value);
	void setSpeed(double speed);
	void setIsCycled(bool new_bool);
	double getInitValue();
	double getEndValue();
	double getSpeed();
	bool isCycled();
	bool isTouched();
	void rewind();

protected:
	double value;
	double init_value;
	double end_value;
	double speed;
	bool is_cycled;
	bool is_touched;
};
}


#endif // AACCUMULATOR_H
