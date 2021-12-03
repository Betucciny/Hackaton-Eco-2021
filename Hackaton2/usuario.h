#ifndef USUARIO_H
#define USUARIO_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class usuario;
}

class usuario : public QMainWindow
{
    Q_OBJECT

public:
    explicit usuario(QWidget *parent = nullptr);
    ~usuario();

private slots:
    void on_buscar_clicked();

    void on_recoleccion_clicked();

private:
    Ui::usuario *ui;
};

#endif // USUARIO_H
