#ifndef EVENTFILTERAPP_H
#define EVENTFILTERAPP_H

#include <QObject>
#include <QEvent>
#include <QDebug>

class EventFilterApp : public QObject
{
    Q_OBJECT
public:
    explicit EventFilterApp(QObject *parent = nullptr);
protected:
    bool eventFilter(QObject* dest, QEvent* event) {
        if(event->type() == QEvent::MouseButtonDblClick) {
            qDebug() << "MouseButtonDblClick from app filter";
            qDebug() << "dest: " << dest->objectName();
        }
        if(event->type() == QEvent::MouseMove) {
            qDebug() << "MouseMove from app filter";
        }
    }
};



#endif // EVENTFILTERAPP_H
