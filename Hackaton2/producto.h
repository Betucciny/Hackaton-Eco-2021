#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QMainWindow>
#include <usuario.h>

#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class Producto;
}

class Producto : public QMainWindow
{
    Q_OBJECT

public:
    explicit Producto(QWidget *parent = nullptr);
    ~Producto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Producto *ui;
};

#endif // PRODUCTO_H
