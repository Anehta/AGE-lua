#include <../include/age_mouseinfo.h>

namespace AGE2D
{
AMouseInfo::AMouseInfo()
{
    m_mouseX = 0;
    m_mouseY = 0;
}

int AMouseInfo::getMouseX()
{
    return m_mouseX;
}

int AMouseInfo::getMouseY()
{
    return m_mouseY;
}

void AMouseInfo::setMouseX(int mouseX)
{
    m_mouseX = mouseX;
}

void AMouseInfo::setMouseY(int mouseY)
{
    m_mouseY = mouseY;
}
}


