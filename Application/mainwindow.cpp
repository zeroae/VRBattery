#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(pollBattery()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pollBattery()
{
    if( GetSystemPowerStatus(&this->spsPwr) )
    {
        emit batteryLifeChanged(static_cast<int>(this->spsPwr.BatteryLifePercent));
    }
}
