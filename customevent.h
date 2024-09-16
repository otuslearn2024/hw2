#ifndef CUSTOMEVENT_H
#define CUSTOMEVENT_H

#include <QEvent>
#include <QString>

class CustomEvent : public QEvent
{
public:
    CustomEvent();
    QString info();
};

#endif // CUSTOMEVENT_H
