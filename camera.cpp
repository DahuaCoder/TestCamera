#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    m_ptrUi(new Ui::Camera),
    m_ptrCamera(NULL),
    m_ptrImageCapture(NULL)
{
    m_ptrUi->setupUi(this);
}

Camera::~Camera()
{
    delete m_ptrUi;
    delete m_ptrCamera;
    delete m_ptrImageCapture;
}

void Camera::initialize()
{
    QByteArray cameraDevice;
    QActionGroup* videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    for (const QByteArray& deviceName : QCamera::availableDevices()) {
        QString description = m_ptrCamera->deviceDescription(deviceName);
        QAction* videoDeviceAction = new QAction(description, videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant(deviceName));

        if (cameraDevice.isEmpty()) {
            cameraDevice = deviceName;
            setCamera(cameraDevice);
            videoDeviceAction->setChecked(true);
        }

        m_ptrUi->menuDevices->addAction(videoDeviceAction);
    }

    connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));
}

void Camera::startCamera()
{
    m_ptrCamera->start();
}

void Camera::stopCamera()
{
    m_ptrCamera->stop();
}

void Camera::takePicture()
{
    m_ptrCamera->searchAndLock();
    m_ptrImageCapture->capture();
    m_ptrCamera->unlock();
}

void Camera::updateCameraDevice(QAction* action)
{
    setCamera(action->data().toByteArray());
}

void Camera::setCamera(const QByteArray& cameraDevice)
{
    if (cameraDevice.isEmpty()) {
        m_ptrCamera = new QCamera;
    }
    else {
        m_ptrCamera = new QCamera(cameraDevice);
    }

    m_ptrCamera->setViewfinder(m_ptrUi->viewFinder);
    m_ptrUi->viewFinder->show();
    m_ptrImageCapture = new QCameraImageCapture(m_ptrCamera);
    m_ptrCamera->setCaptureMode(QCamera::CaptureStillImage);

    connect(m_ptrUi->captureButton, SIGNAL(clicked()), SLOT(takePicture()));
}
