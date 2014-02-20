#ifndef AAPPLICATION_H
#define AAPPLICATION_H
#include <QApplication>
#include <../include/age_widget.h>
#include <../include/age_luawidget.h>

namespace AGE2D
{
class ASystem
{
public:
	static void Init(int argc, char *argv[]);
	static int Go();
	static void SetSize(int width, int height);

	static int Random(int min,int max);
    static QTextEdit * GetLuaEdit();
	static int GetWidth();
	static int GetHeight();
	static int GetWidthOffset();
	static int GetHeightOffset();
	static AWidget * GetWidget();
	static int IsEngineInitialized();
	static int TimeStep();
	static double FrameRate();
    static void ShowLuaEdit();
    static void HideLuaEdit();
    static void AddDebugInfo(QString str);
    static void SetLuaEditSize(int x,int y);
	friend class AWidget;

private:
	ASystem();
	static int m_width;
	static int m_height;
	static int m_widthOffset;
	static int m_heightOffset;
	static bool is_init;
	static QApplication * m_application;
	static AWidget * m_widget;
    static QTextEdit * m_lua_textEdit;
    static QString m_debug_string;
};
}
#endif // AAPPLICATION_H





