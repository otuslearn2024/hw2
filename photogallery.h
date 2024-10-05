#ifndef PHOTOGALLERY_H
#define PHOTOGALLERY_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QStringList>

class PhotoGallery : public QLabel
{
    Q_OBJECT
public:
    PhotoGallery(QWidget * parent = 0);
    ~PhotoGallery();
    void setPhotos(QStringList *photos);

protected:
    void mouseMoveEvent(QMouseEvent *ev) override;

private:
    QStringList *photos;
    QList<QPixmap> *pixMaps;
    int currentSector = 0;
    int countFotos;
    int sectorSize;
    int photoWidth;

};

#endif // PHOTOGALLERY_H
