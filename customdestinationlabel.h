#ifndef CUSTOMDESTINATIONLABEL_H
#define CUSTOMDESTINATIONLABEL_H

#include <QObject>
#include <QLabel>

class CustomDestinationLabel : public QLabel
{
    Q_OBJECT
public:
    CustomDestinationLabel(QWidget *parent = nullptr);
protected:
    bool event(QEvent *e) override;
signals:
    void customEventAccepted();
};

#endif // CUSTOMDESTINATIONLABEL_H
