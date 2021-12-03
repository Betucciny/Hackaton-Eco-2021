#include "usuario.h"
#include "ui_usuario.h"
#include <gpedido.h>
#include <producto.h>


extern int index;

usuario::usuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usuario)
{
    ui->setupUi(this);
}

usuario::~usuario()
{


    delete ui;
}

void usuario::on_buscar_clicked()
{
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")){
        ui->error->setText("ERROR");
        return;
    }
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("C:/Users/betoh/Desktop/Programas/usuarios.db");
    if(!bd.open()){
        ui->error->setText("ERROR");
        return;
    }
    QSqlQuery q;

    QString code = ui->icodigo->text();

    q.exec("SELECT * FROM productos");
    while (q.next()) {
        if(code==q.value("codigo").toString()){
            index=q.value("id").toInt();
        }
    }

    bd.close();
    Producto *ventana1 = new Producto(this);
    ventana1->show();
    this->hide();

}


void usuario::on_recoleccion_clicked()
{
    this->close();
    gpedido *ventana = new gpedido(this);
    ventana->show();
}

