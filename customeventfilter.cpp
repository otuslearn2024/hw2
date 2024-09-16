#include "customeventfilter.h"
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include "customevent.h"

CustomEventFilter::CustomEventFilter(QObject *parent) : QObject(parent)
{

}

void CustomEventFilter::setDestination(QLabel *dest)
{
    this->destination = dest;
}

bool CustomEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
      qDebug() << "CustomEventFilter::eventFilter MouseButtonPress";
      qApp->sendEvent(destination, event);
      return true;
    }
    if (event->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "CustomEventFilter::eventFilter MouseButtonDblClick";
        CustomEvent *customEvent = new CustomEvent();
        qApp->sendEvent(destination, customEvent);
        return true;
    }

    // Обработка фильтром базового класса.
    return QObject::eventFilter(watched, event);
}
