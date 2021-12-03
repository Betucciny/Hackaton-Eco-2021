#ifndef REGISTAR_H
#define REGISTAR_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <mainwindow.h>


namespace Ui {
class Registar;
}

class Registar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registar(QWidget *parent = nullptr);
    ~Registar();

private slots:
    void on_iniciarb_clicked();

private:
    Ui::Registar *ui;
};

#endif // REGISTAR_H
