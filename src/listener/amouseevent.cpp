#include <../include/AGE2D.h>

AMouseEvent::AMouseEvent()
{
    m_mouseEvent = 0;
    m_mouseX = 0;
    m_mouseY = 0;
}

int AMouseEvent::getMouseEventType()
{
    return m_mouseEvent;
}

int AMouseEvent::getMouseX()
{
    return m_mouseX;
}

int AMouseEvent::getMouseY()
{
    return m_mouseY;
}

void AMouseEvent::setMouseEventType(int mouseEvent)
{
    m_mouseEvent = mouseEvent;
}

void AMouseEvent::setMouseX(int mouseX)
{
    m_mouseEvent = mouseX;
}

void AMouseEvent::setMouseY(int mouseY)
{
    m_mouseY = mouseY;
}

