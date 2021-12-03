#include "mainwindow.h"
#include "ui_mainwindow.h"

extern int u;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tipou->addItem("Vendedor");
    ui->tipou->addItem("Recolector");
   //Conectar a funcion
}

MainWindow::~MainWindow()
{   

    delete ui;
}

void MainWindow::on_iniciarb_clicked()
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
    if(!q.exec("CREATE TABLE IF NOT EXISTS usuario"
           "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"
           ", nombre VARCHAR(255) NOT NULL, contra VARCHAR(255) NOT NULL, "
           "mail VARCHAR(255) NOT NULL, tipo VARCHAR(255) NOT NULL)")){
        ui->error->setText("ERROR");
        return;
    }

    QString user = ui->usuariobox->text();
    QString pass = ui->contrabox->text();
    QString tuser = ui->tipou->currentText();


    q.exec("SELECT * FROM usuario");
    while (q.next()) {
        if(user==q.value("nombre").toString() && pass==q.value("contra").toString() &&
                tuser=="Vendedor" && tuser==q.value("tipo").toString()){
            usuario *ventana2 = new usuario(this);
            ventana2->show();
            this->hide();
        }

        if(user==q.value("nombre").toString() && pass==q.value("contra").toString() &&
                tuser=="Recolector" && tuser==q.value("tipo").toString()){
            recolector *ventana2 = new recolector(this);
            ventana2->show();
            this->hide();
        }
        u=q.value("id").toInt();
    }

    bd.close();
}


void MainWindow::on_registrarb_clicked()
{
    Registar *ventana1 = new Registar(this);
    ventana1->show();
    this->hide();

}

void MainWindow::myfunction(){

}
