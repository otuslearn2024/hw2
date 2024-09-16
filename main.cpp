#include "mainwindow.h"
#include "eventfilterapp.h"
#include <QApplication>
#include "customapplication.h"

int main(int argc, char *argv[])
{
    CustomApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
