#include "camera.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Camera camera;
    camera.initialize();
    camera.show();

    return a.exec();
}
