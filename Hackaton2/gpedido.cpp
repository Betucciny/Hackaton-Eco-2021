#include "gpedido.h"
#include "ui_gpedido.h"

#include <usuario.h>

extern int u;

gpedido::gpedido(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gpedido)
{
    ui->setupUi(this);
    ui->comboBox->addItem("PET");
    ui->comboBox->addItem("carton");
    ui->comboBox->addItem("aluminio");
    ui->comboBox->addItem("vidrio");
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(800);

}

gpedido::~gpedido()
{
    delete ui;
}

void gpedido::on_pushButton_clicked()
{
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("C:/Users/betoh/Desktop/Programas/usuarios.db");
    if(!bd.open()){
        return;
    }
    QSqlQuery q;
    q.exec("SELECT * FROM usuario WHERE id = "+QString::number(u));
    q.next();
    QString name = q.value("nombre").toString();
    QString direc = ui->direcccc->text();
    QString type = ui->comboBox->currentText();
    QString ca= ui->spinBox->text();
    q.exec("INSERT INTO pedidos(nombre,direccion,tipob,cant) VALUES('"+name+"','"+direc+"','"+type+"','"+ca+"')");
    bd.close();

    this->close();
    usuario *ventana = new usuario(this);
    ventana->show();

}

