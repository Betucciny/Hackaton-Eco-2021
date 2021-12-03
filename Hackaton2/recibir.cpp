#include "recibir.h"
#include "ui_recibir.h"

int count=0;

recibir::recibir(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recibir)
{
    ui->setupUi(this);
}

recibir::~recibir()
{
    delete ui;
}

void recibir::on_pushButton_clicked()
{
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")){
        return;
    }
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("C:/Users/betoh/Desktop/Programas/usuarios.db");
    if(!bd.open()){
        return;
    }
    QSqlQuery q;
    count++;
    q.exec("SELECT * FROM pedidos WHERE id = "+QString::number(count));
    q.next();

    QString dir = q.value("direccion").toString();
    QString img = "C:/Users/betoh/Desktop/Programas/Direcciones/"+q.value("id").toString()+".png";

    ui->imagen->setPixmap(img);
    ui->direcccc->setText(dir);

    bd.close();
}

