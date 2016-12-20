#ifndef BATTERYINFOFORM_H
#define BATTERYINFOFORM_H

#include <QWidget>
#include <windows.h>

namespace Ui {
class BatteryInfoWidget;
}

class BatteryInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryInfoWidget(QWidget *parent = 0);
    ~BatteryInfoWidget();

signals:
    void batteryLifeChanged(int newValue);

private slots:
    void pollBattery();

private:
    Ui::BatteryInfoWidget *ui;

    SYSTEM_POWER_STATUS m_spsPwr;
};

#endif // BATTERYINFOFORM_H
