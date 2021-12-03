#include "recolector.h"
#include "ui_recolector.h"

#include <recibir.h>

recolector::recolector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recolector)
{
    ui->setupUi(this);
}

recolector::~recolector()
{
    delete ui;
}

void recolector::on_pushButton_clicked()
{
    recibir *ventana1 = new recibir(this);
    ventana1->show();
    this->hide();
}

