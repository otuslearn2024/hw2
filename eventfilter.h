#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QDebug>

class EventFilter : public QObject
{
    Q_OBJECT
public:
    explicit EventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject* dest, QEvent* event);
};

#endif // EVENTFILTER_H
