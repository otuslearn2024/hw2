#ifndef WARMSWITCHER_H
#define WARMSWITCHER_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPen>

class WarmSwitcher : public QWidget
{
    Q_OBJECT
public:
    WarmSwitcher(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    bool getStatus();
private:
    bool is_on; //статус
    int width; //текущая ширина
    int height; //текущая высота
    void setSize(); //выставить текущие размеры
signals:
    void became_on();
    void became_off();
};

#endif // WARMSWITCHER_H
