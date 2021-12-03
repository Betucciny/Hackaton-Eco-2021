#ifndef GPEDIDO_H
#define GPEDIDO_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>



namespace Ui {
class gpedido;
}

class gpedido : public QMainWindow
{
    Q_OBJECT

public:
    explicit gpedido(QWidget *parent = nullptr);
    ~gpedido();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gpedido *ui;
};

#endif // GPEDIDO_H
