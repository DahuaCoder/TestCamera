#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    m_ptrUi(std::make_shared<Ui::Camera>()),
    m_ptrCamera()
{
    m_ptrUi->setupUi(this);

    QString outputMsg;  // Debug

    QActionGroup* videoDevicesGroup = new QActionGroup(this);
    for (const QByteArray& deviceName : QCamera::availableDevices()) {
        QString description = m_ptrCamera->deviceDescription(deviceName);
        outputMsg.append(description).append(QString("\n"));    // Debug
        QAction* videoDeviceAction = new QAction(description, videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant(deviceName));

        m_ptrUi->menuDevices->addAction(videoDeviceAction);
    }

    connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));

    m_ptrUi->label->setText(outputMsg); // Debug

}

Camera::~Camera()
{

}


void Camera::updateCameraDevice(QAction* action)
{

}

void Camera::setCamera(const QByteArray& cameraDevice)
{
    if (cameraDevice.isEmpty()) {
        m_ptrCamera = std::make_shared<QCamera>();
    }
    else {
        m_ptrCamera = std::make_shared<QCamera>(cameraDevice);
    }
}
