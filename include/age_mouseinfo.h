#ifndef AMOUSEEVENT_H
#define AMOUSEEVENT_H

namespace AGE2D{
class AMouseInfo
{
public:
    AMouseInfo();
    void setMouseX(int mouseX);
    void setMouseY(int mouseY);
    int getMouseX();
    int getMouseY();
private:
    int m_mouseX;
    int m_mouseY;
};

}

#endif // AMOUSEEVENT_H
