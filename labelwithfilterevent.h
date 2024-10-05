#ifndef LABELWITHFILTEREVENT_H
#define LABELWITHFILTEREVENT_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class LabelWithFilterEvent : public QLabel
{
public:
    LabelWithFilterEvent(QWidget *parent = nullptr) : QLabel(parent) {
        setMouseTracking(true);
    }
protected:
    void mousePressEvent(QMouseEvent *ev) override {
        qDebug() << "mousePressEvent from LabelWithFilterEvent triggered";
        setText("mouse button pressed");
        QLabel::mouseMoveEvent(ev);
    }
    void mouseMoveEvent(QMouseEvent *ev) override {
        //qDebug() << ev->pos();
        c++;
        this->setText(QString::number(c));
        QLabel::mouseMoveEvent(ev);
    }
private:
    int c = 0;
};

#endif // LABELWITHFILTEREVENT_H
