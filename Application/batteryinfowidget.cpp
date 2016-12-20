#include "batteryinfowidget.h"
#include "ui_batteryinfowidget.h"

#include <QTimer>
#include <QDebug>

BatteryInfoWidget::BatteryInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryInfoWidget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(pollBattery()));
    timer->start(1000);
}

BatteryInfoWidget::~BatteryInfoWidget()
{
    delete ui;
}

void BatteryInfoWidget::pollBattery()
{
    qInfo() << "Poll for battery information.";
    if( GetSystemPowerStatus(&m_spsPwr) )
    {
        emit batteryLifeChanged(static_cast<int>(m_spsPwr.BatteryLifePercent));
    }
}
