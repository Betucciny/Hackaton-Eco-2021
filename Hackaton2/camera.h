#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>


namespace Ui {
class camera;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;


class camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = nullptr);
    ~camera();

private:
    Ui::camera *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
};

#endif // CAMERA_H
