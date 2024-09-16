#include "photogallery.h"
#include <QDebug>
#include <QPixmap>
#include <QList>


PhotoGallery::PhotoGallery(QWidget *parent) : QLabel(parent)
{
    qDebug() << "PhotoGallery constructor called";
    setMouseTracking(true);
    setScaledContents(true);
    this->pixMaps = new QList<QPixmap>();
}

PhotoGallery::~PhotoGallery()
{
    delete(pixMaps);
    delete(photos);
}

void PhotoGallery::setPhotos(QStringList *photos)
{
    qDebug() << "setPhotos called";

    this->photos = photos;

    for(int i = 0; i<photos->count(); i++) {
        QPixmap * pm = new QPixmap(photos->at(i));
        this->pixMaps->append(pm->scaled(500,500,Qt::KeepAspectRatio));
    }

    photoWidth = pixMaps->at(0).width();

    countFotos = sizeof(photos->count());
    sectorSize = photoWidth / (countFotos - 1);

    qDebug() << "photoWidth: " << photoWidth;
    qDebug() << "countFotos: " << countFotos;
    qDebug() << "sectorSize: " << sectorSize;

    this->setPixmap(pixMaps->at(0));
}

void PhotoGallery::mouseMoveEvent(QMouseEvent *ev)
{
    int tmpCurrentSector = ev->x() / sectorSize;

    if (currentSector != tmpCurrentSector)
    {
      qDebug() << "current sector: " << currentSector << " tmpCurrentSector = " << tmpCurrentSector;
      qDebug() << "switch photo, pos = " << ev->pos();
      this->setPixmap(pixMaps->at(currentSector));
      currentSector = tmpCurrentSector;
    }

    QLabel::mouseMoveEvent(ev);
}

void PhotoGallery::mousePressEvent(QMouseEvent *ev)
{
    //qDebug() << "mousePressEvent";
    QLabel::mouseMoveEvent(ev);
}
