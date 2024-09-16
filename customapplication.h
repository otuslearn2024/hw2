#ifndef CUSTOMAPPLICATION_H
#define CUSTOMAPPLICATION_H

#include <QObject>
#include <QEvent>
#include <QApplication>
#include <QDebug>


class CustomApplication : public QApplication
{
    Q_OBJECT

public:
  bool isMouseMoveAllowed = true;
  explicit CustomApplication(int& argc, char** argv);

protected:
    bool notify(QObject *receiver, QEvent *event) override {
        if (event->type() == QEvent::MouseMove)
        {
          qDebug() << "CustomApplication: Notify";
          if(isMouseMoveAllowed) {
            return QApplication::notify(receiver, event);
          }
          else {
              return true;
          }
        }
        return QApplication::notify(receiver, event);
    }
};

#endif // CUSTOMAPPLICATION_H
