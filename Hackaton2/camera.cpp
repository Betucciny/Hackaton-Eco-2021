#include "camera.h"
#include "ui_camera.h"
#include <QCamera>
#include <QCameraDevice>

#include <QVBoxLayout>


camera::camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);


}

camera::~camera()
{
    delete ui;
}
