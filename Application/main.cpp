#include "batteryinfowidget.h"
#include "openvroverlaycontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Initialize Qt
    QApplication a(argc, argv);

    BatteryInfoWidget* pWidget = new BatteryInfoWidget();

    // Initialize VR
    bool bSuccess = COpenVROverlayController::SharedInstance()->Init();
    if (bSuccess) {
        COpenVROverlayController::SharedInstance()->SetWidget(pWidget);
        qInfo() << "VROverlayController Initialized.";
    }
    else {
        qInfo() << "Unable to start VROverlayController";
        pWidget->show();
    }
    return a.exec();
}
