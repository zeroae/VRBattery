#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void pollBattery();

signals:
    void batteryLifeChanged(int newValue);

private:
    Ui::MainWindow *ui;

    SYSTEM_POWER_STATUS spsPwr;
};

#endif // MAINWINDOW_H
