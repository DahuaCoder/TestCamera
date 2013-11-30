#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>

namespace Ui {
class Camera;
}

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

    void initialize();

private slots:
    void updateCameraDevice(QAction* action);
    void startCamera();
    void stopCamera();
    void takePicture();

private:
    void setCamera(const QByteArray& cameraDevice);

private:
    Ui::Camera* m_ptrUi;
    QCamera* m_ptrCamera;
    QCameraImageCapture* m_ptrImageCapture;
};

#endif // CAMERA_H
