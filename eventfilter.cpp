#include "eventfilter.h"

EventFilter::EventFilter(QObject *parent) : QObject(parent)
{

}

bool EventFilter::eventFilter(QObject *dest, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
      qDebug() << "Event filter MouseButtonPress";
      return true;
    }

    return QObject::eventFilter(dest, event);
}
