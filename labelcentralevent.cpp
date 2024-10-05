#include "labelcentralevent.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

LabelCentralEvent::LabelCentralEvent(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
    setScaledContents(true);
    this->pixMaps = new QList<QPixmap>();
}

LabelCentralEvent::~LabelCentralEvent()
{
    delete(pixMaps);
    delete(photos);
}

void LabelCentralEvent::setPhotos(QStringList *photos)
{
    //qDebug() << "setPhotos called";

    this->photos = photos;

    for(int i = 0; i<photos->count(); i++) {
        QPixmap * pm = new QPixmap(photos->at(i));
        this->pixMaps->append(*pm);
    }

    photoWidth = pixMaps->at(0).width();
    countFotos = photos->count();
    sectorSize = photoWidth / countFotos;

    //qDebug() << "photoWidth: " << photoWidth;
    //qDebug() << "countFotos: " << countFotos;
    //qDebug() << "sectorSize: " << sectorSize;

    this->setPixmap(pixMaps->at(0));
}

bool LabelCentralEvent::event(QEvent *e)
{
    //qDebug() << e->type();
    if(e->type() == QEvent::MouseButtonPress) {
            currentSector++;
            if (currentSector > (countFotos - 1))
              currentSector = 0;
            this->setPixmap(pixMaps->at(currentSector));
            return true;
    }
    return QLabel::event(e);
}
