#include "customevent.h"

CustomEvent::CustomEvent() : QEvent((Type)(QEvent::User + 111))
{

}

QString CustomEvent::info()
{
    return "CustomEvent";
}
