#include "warmswitcher.h"
#include <QDebug>
#include <QMouseEvent>

WarmSwitcher::WarmSwitcher(QWidget *parent)
{
    Q_UNUSED(parent);
    is_on = false;
    setSize();
    setMinimumSize(150, 150);
}

void WarmSwitcher::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    int middle_w = this->width / 2;
    int middle_h = this->height / 2;

    QPainter *painter = new QPainter(this);

    if(is_on) {
        painter->setPen(QColor(255,0,0));
        painter->drawText(QPoint(middle_w - 55, middle_h - 50), "Выключен");
    }
    else {
        painter->setPen(QColor(0,255,0));
        painter->drawText(QPoint(middle_w - 50, middle_h - 50), "Включен");
    }

    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(QBrush(QColor(200,200,200)));
    //painter->drawRect(middle_w - 50, middle_h - 20, 100, 40);
    painter->drawRoundedRect(middle_w - 50, middle_h - 20, 100, 40, 5, 5);

    painter->setBrush(QBrush(QColor(0,0,0)));
    if(is_on) {
        painter->drawRect(middle_w - 40, middle_h - 20, 20, 40);
    }
    else {
        painter->drawRect(middle_w + 20, middle_h - 20, 20, 40);
    }
    painter->end();
}

void WarmSwitcher::mousePressEvent(QMouseEvent *event)
{
    //надо чтобы клик срабатывал только над переключателем а не на всём виджете
    int pos_x = event->x();
    int pos_y = event->y();

    int middle_w = this->width / 2;
    int middle_h = this->height / 2;

    if((pos_x > middle_w - 50) &&
            (pos_x < middle_w + 50) &&
            (pos_y > middle_h - 20) &&
            (pos_y < middle_h + 20)) {
        if(is_on) {
            is_on = false;
            emit became_on();
        }
        else {
            is_on = true;
            emit became_off();
        }
        repaint();
    }
}

void WarmSwitcher::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    setSize();
    repaint();
}

bool WarmSwitcher::getStatus()
{
    return is_on == true ? true : false;
}

void WarmSwitcher::setSize()
{
    QSize sz = size();
    int w_w = sz.width();
    int w_h = sz.height();
    this->width = w_w;
    this->height = w_h;

    qDebug() << "w = " << w_w << " h = " << w_h;
}

