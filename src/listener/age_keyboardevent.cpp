#include <../include/age_keyboardevent.h>

namespace AGE2D{
AKeyBoardEvent::AKeyBoardEvent()
{
    m_KeyBoardEvent = 0;
}

void AKeyBoardEvent::setKeyBoardType(int valueType)
{
    m_KeyBoardEvent = valueType;
}

int AKeyBoardEvent::getKeyBoardEvent()
{
    return m_KeyBoardEvent;
}

}
