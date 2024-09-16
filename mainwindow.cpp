#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QDebug>
#include "eventfilter.h"
#include "eventfilterapp.h"
#include <QApplication>
#include "customapplication.h"
#include "customeventfilter.h"
#include "warmswitcher.h"

QStringList *photos = new QStringList();
bool isAppFilterActive = false;
EventFilterApp *filterApp;
CustomEventFilter *customEventFilter;
QLabel *controlLabel;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    *photos << ":/images/DSC_1033.JPG";
    *photos << ":/images/DSC_1035.JPG";
    *photos << ":/images/DSC_1047.JPG";
    *photos << ":/images/DSC_1049.JPG";

    ui->setupUi(this);



    ui->label->setPhotos(photos);
    ui->label_2->setPhotos(photos);

    EventFilter* filter = new EventFilter();
    ui->label_3->installEventFilter(filter);

    filterApp = new EventFilterApp();

    //включить-выключить фильтр на уровне объекта
    connect(ui->actionAppFilter, &QAction::triggered, [&]() {
        if(ui->actionAppFilter->isChecked()) {
            qDebug() << "checked";
            QApplication::instance()->installEventFilter(filterApp);
        }
        else {
            qDebug() << "unchecked";
            QApplication::instance()->removeEventFilter(filterApp);
        }
    });

    //включить-выключить фильтр на уровне приложения
    connect(ui->actionCustomAppFilter, &QAction::triggered, [&]() {
        if(ui->actionCustomAppFilter->isChecked()) {
            (static_cast<CustomApplication *>(qApp))->isMouseMoveAllowed = false;
        }
        else {
            (static_cast<CustomApplication *>(qApp))->isMouseMoveAllowed = true;
        }
    });

    //фильтр для редиректра сообщений
    //фильтр вешаем на label_source и события будем бросать на label_destination
    ui->label_destination->setText("destination label");
    customEventFilter = new CustomEventFilter();
    //customEventFilter->setDestination(ui->label_destination);
    ui->label_source->installEventFilter(customEventFilter);
    //connect(ui->la

    //добавить виджет на таб
    QHBoxLayout* layout = new QHBoxLayout();
    WarmSwitcher *ws = new WarmSwitcher(this);
    layout->addWidget(ws);

    //контрольный лейбл который ловит сигнал
    controlLabel = new QLabel();
    QString controlLabelText = ws->getStatus() == true ? "Включен" : "Выключен";
    controlLabel->setText(controlLabelText);
    layout->addWidget(controlLabel);

    ui->tab_5->setLayout(layout);

    connect(ws, &WarmSwitcher::became_on, [&]() {
       qDebug() << "became_on";
       controlLabel->setText("ON");
    });

    connect(ws, &WarmSwitcher::became_off, [&]() {
       qDebug() << "became_off";
       controlLabel->setText("OFF");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

