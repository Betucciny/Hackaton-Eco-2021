#include "registar.h"
#include "ui_registar.h"

Registar::Registar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registar)
{
    ui->setupUi(this);
    ui->tipou->addItem("Vendedor");
    ui->tipou->addItem("Recolector");
}

Registar::~Registar()
{
    delete ui;
}

void Registar::on_iniciarb_clicked()
{
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("C:/Users/betoh/Desktop/Programas/usuarios.db");
    if(!bd.open()){
        ui->error->setText("Error");
        return;
    }
    QSqlQuery q;

    QString user= ui->usuariobox->text();
    QString pass= ui->contrabox->text();
    QString cpass= ui->contrabox2->text();
    QString email= ui->correobox->text();
    QString type= ui->tipou->currentText();

    if(pass==cpass){
        q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('"+user+"','"+pass+"','"+email+"','"+type+"')");
    }else{
        ui->error->setText("Contraseña no coincide");
        return;
    }
    bd.close();

    this->close();
    MainWindow *ventana = new MainWindow(this);
    ventana->show();

}

