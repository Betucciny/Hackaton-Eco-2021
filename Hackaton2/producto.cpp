#include "producto.h"
#include <usuario.h>
#include <ui_producto.h>

extern int index;

Producto::Producto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Producto)
{
    ui->setupUi(this);


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

    q.exec("SELECT * FROM productos WHERE id = "+QString::number(index));
    q.next();


    QString cod = q.value("codigo").toString();
    QString bot = q.value("bote").toString();
    QString img = q.value("imagen").toString();
    QString dir;

    ui->fotoprod->setPixmap(img);
    if(bot=="aluminio"){
        dir="C:/Users/betoh/Desktop/Programas/botes/Aluminio icon.png";
    }else if(bot=="PET"){
        dir="C:/Users/betoh/Desktop/Programas/botes/PET Icon.png";
    }else if(bot=="carton"){
        dir="C:/Users/betoh/Desktop/Programas/botes/Carton icon.png";
    }else if(bot=="vidrio"){
        dir="C:/Users/betoh/Desktop/Programas/botes/Vidrio Icon.png";
    }else{
        dir="C:/Users/betoh/Desktop/Programas/botes/Basura ICON.png";
    }
    ui->fotobote->setPixmap(dir);
    ui->codigo->setText(cod);
    ui->nombrebote->setText(bot);
    index=0;
    bd.close();
}

Producto::~Producto()
{


    delete ui;
}

void Producto::on_pushButton_clicked()
{
    this->close();
    usuario *ventana = new usuario(this);
    ventana->show();
}

