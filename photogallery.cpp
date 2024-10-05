#include "photogallery.h"
#include <QDebug>
#include <QPixmap>
#include <QList>


PhotoGallery::PhotoGallery(QWidget *parent) : QLabel(parent)
{
    //qDebug() << "PhotoGallery constructor called";
    setMouseTracking(true);
    setScaledContents(false);

    this->pixMaps = new QList<QPixmap>();
}

PhotoGallery::~PhotoGallery()
{
    delete(pixMaps);
    delete(photos);
}

void PhotoGallery::setPhotos(QStringList *photos)
{
    //qDebug() << "PhotoFallery: setPhotos called";

    this->photos = photos;

    for(int i = 0; i < photos->count(); i++) {
        QPixmap * pm = new QPixmap(photos->at(i));
        this->pixMaps->append(*pm);
    }

    photoWidth = pixMaps->at(0).width();
    countFotos = photos->count();
    sectorSize = photoWidth / (countFotos);

    //qDebug() << "PhotoFallery: photoWidth: " << photoWidth;
    //qDebug() << "PhotoFallery: countFotos: " << countFotos;
    //qDebug() << "PhotoFallery: sectorSize: " << sectorSize;

    this->setPixmap(pixMaps->at(0));
}

void PhotoGallery::mouseMoveEvent(QMouseEvent *ev)
{
    int tmpCurrentSector = ev->x() / sectorSize;
    //qDebug() << currentSector << " " << tmpCurrentSector << " " << ev->x();

    if (currentSector != tmpCurrentSector)
    {
        currentSector = tmpCurrentSector;
        this->setPixmap(pixMaps->at(currentSector));

        //qDebug() << "PhotoFallery: current sector: " << currentSector << " tmpCurrentSector = " << tmpCurrentSector;
        //qDebug() << "PhotoFallery: switch photo, pos = " << ev->pos();

    }
    QLabel::mouseMoveEvent(ev);
}
