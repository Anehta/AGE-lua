#ifndef AKEYBOARDEVENT_H
#define AKEYBOARDEVENT_H

namespace AGE2D {
class AKeyBoardEvent
{
public:
    AKeyBoardEvent();
    int getKeyBoardEvent();
    void setKeyBoardType(int valueType);
private:
    int m_KeyBoardEvent;
};
}


#endif // AEVENT_H
