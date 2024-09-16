#include "customdestinationlabel.h"
#include <QDebug>
#include <QMouseEvent>
#include "customevent.h"
#include <QEvent>

CustomDestinationLabel::CustomDestinationLabel(QWidget *parent): QLabel(parent)
{
    qDebug() << "CustomDestinationLabel called";
}


bool CustomDestinationLabel::event(QEvent *ev)
{
    if(ev->type() == QEvent::User+111) {
        this->setText("custom event accepted");
        qDebug() << "custom event accepted";
        QEvent *myEvent = static_cast<QEvent *>(ev);
        CustomEvent *cMyEvent = static_cast<CustomEvent *>(myEvent);
        cMyEvent->info();
        emit customEventAccepted();
    }
    if(ev->type() == QEvent::MouseButtonPress) {
         qDebug() << "CustomDestinationLabel MouseButtonPress event";
     }
    return true;
}
