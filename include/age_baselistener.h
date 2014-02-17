#ifndef ABASELISTENER_H
#define ABASELISTENER_H
#include <QMouseEvent>
namespace AGE2D {
class ABaseListener
{
public:
    ABaseListener();
    friend class AEventMgr;
    friend class AWidget;
protected:
    void handleListener();
    virtual void onMouseMove(QMouseEvent *);
    virtual void onMousePress(QMouseEvent *);
    virtual void onMouseRelease(QMouseEvent *);
    virtual void onKeyPress();
private:
};
}


#endif // ABASELISTENER_H
