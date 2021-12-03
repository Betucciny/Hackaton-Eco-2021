#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include <QMainWindow>

namespace Ui {
class recolector;
}

class recolector : public QMainWindow
{
    Q_OBJECT

public:
    explicit recolector(QWidget *parent = nullptr);
    ~recolector();

private slots:
    void on_pushButton_clicked();

private:
    Ui::recolector *ui;
};

#endif // RECOLECTOR_H
