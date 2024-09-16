#ifndef LABELCENTRALEVENT_H
#define LABELCENTRALEVENT_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class LabelCentralEvent : public QLabel
{
    Q_OBJECT
public:
    LabelCentralEvent(QWidget *parent = nullptr);
    ~LabelCentralEvent();
    void setPhotos(QStringList *photos);
    bool event(QEvent *e) override;

private:
    QStringList *photos;
    QList<QPixmap> *pixMaps;
    int currentSector = 0;
    int countFotos;
    int sectorSize;
    int photoWidth;

signals:

};

#endif // LABELCENTRALEVENT_H
