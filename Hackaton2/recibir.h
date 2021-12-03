#ifndef RECIBIR_H
#define RECIBIR_H

#include <QMainWindow>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


namespace Ui {
class recibir;
}

class recibir : public QMainWindow
{
    Q_OBJECT

public:
    explicit recibir(QWidget *parent = nullptr);
    ~recibir();

private slots:
    void on_pushButton_clicked();

private:
    Ui::recibir *ui;
};

#endif // RECIBIR_H
