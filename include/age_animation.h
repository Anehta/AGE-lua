#ifndef AANIMATION_H
#define AANIMATION_H
#include <qt>
#include <vector>
#include <../include/age_frame.h>
#include <qstring.h>
using namespace std;
namespace AGE2D {
class AAnimation
{
public:
	AAnimation(QString name);
	void addFrame(AFrame frame);
	QString getName();
	int totalFrames();
	AFrame getFrame(int index);
protected:
	QString name;
	vector<AFrame> m_list;
};
}


#endif // AANIMATION_H
