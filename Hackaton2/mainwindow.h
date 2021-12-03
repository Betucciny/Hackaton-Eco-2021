#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <registar.h>
#include <usuario.h>
#include <recolector.h>

#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_iniciarb_clicked();

    void on_registrarb_clicked();

    void myfunction();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};


#endif // MAINWINDOW_H
