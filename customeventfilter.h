#ifndef CUSTOMEVENTFILTER_H
#define CUSTOMEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QDebug>
#include <QLabel>

class CustomEventFilter : public QObject
{
    Q_OBJECT
public:
    CustomEventFilter(QObject *parent = nullptr);
    void setDestination(QLabel * dest);
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    QLabel *destination;
};

#endif // CUSTOMEVENTFILTER_H
