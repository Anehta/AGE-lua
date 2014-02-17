#ifndef AAPPLICATION2_H
#define AAPPLICATION2_H

#include <QApplication>
#include "AGE2D.h"
#include "age_widget.h"
namespace AGE2D {
class AWdiget;

class AApplication
{
public:
	static void Init(int argc, char *argv[]);
	static int Go();
	static void SetSize(int width, int height);
	static int IsEngineInitialized();
private:
	AApplication();
	static int m_width;
	static int m_height;
	static bool is_init;
	static QApplication * m_application;
    static AWidget * m_widiget;
};

}

#endif // AAPPLICATION_H

