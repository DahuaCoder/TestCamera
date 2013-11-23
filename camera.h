#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QCamera>

#include <memory>

namespace Ui {
class Camera;
}

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private slots:
    void updateCameraDevice(QAction* action);

private:
    void setCamera(const QByteArray& cameraDevice);

private:
    std::shared_ptr<Ui::Camera> m_ptrUi;
    std::shared_ptr<QCamera> m_ptrCamera;
};

#endif // CAMERA_H
