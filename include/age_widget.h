#ifndef AGEWIDGET_H
#define AGEWIDGET_H

#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShaderProgram>
#include <QBasicTimer>
#include <QMatrix4x4>
#include <QQuaternion>
#include <../include/age_geometric.h>
#include <../include/age_texture.h>
#include <../include/age_keyboardevent.h>
#include <../include/age_mouseinfo.h>
#include <../include/age_baselistener.h>
#include <../include/age_vector2d.h>
#include "age_keyboardevent.h"
#include "age_mouseinfo.h"
#include "age_luawidget.h"

extern void * sprite;
extern void * texture;
namespace AGE2D
{

class AWidget : public QGLWidget ,QGLFunctions
{
    Q_OBJECT
public:
    AWidget(QWidget *parent = 0);
    ~AWidget();

    double getScaleFactor() const;
    void setScaleFactor(double value);

    int getScreenOffsetX() const;
    void setScreenOffsetX(int value);

    int getScreenOffsetY() const;
    void setScreenOffsetY(int value);

    int getReal_width() const;
    void setReal_width(int value);

    int getReal_height() const;
    void setReal_height(int value);
    void updateWindow(int w,int h);
protected:
    virtual void display();
    virtual void initResources();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void keyPressEvent (QKeyEvent *event);
private:
    QBasicTimer m_timer;
    QMatrix4x4 projection;
    AKeyBoardEvent m_keyBoardEvent;
    AVector2D mouse_pos;

    double scale_factor;
    int screen_offset_x;
    int screen_offset_y;
    int real_width;
    int real_height;
    bool is_release;
    bool is_press;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void timerEvent(QTimerEvent *);
};
}


#endif // AGEWIDGET_H
