#include <QCoreApplication>
#include <QtCore>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")){
        qDebug() << "ERROR";
        return -1;
    }
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("C:/Users/betoh/Desktop/Programas/usuarios.db");
    if(!bd.open()){
        qDebug() << "ERROR";
        return -2;
    }
    QSqlQuery q;
    if(!q.exec("CREATE TABLE IF NOT EXISTS usuario"
           "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"
           ", nombre VARCHAR(255) NOT NULL, contra VARCHAR(255) NOT NULL, "
           "mail VARCHAR(255) NOT NULL, tipo VARCHAR(255) NOT NULL)")){
        qDebug() << "ERROR";
        return -3;
    }
    if(!q.exec("CREATE TABLE IF NOT EXISTS productos"
           "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"
           ", nombre VARCHAR(255) NOT NULL, codigo VARCHAR(255) NOT NULL, "
           "material VARCHAR(255) NOT NULL,bote VARCHAR(255) NOT NULL,imagen VARCHAR(255) NOT NULL)")){
        qDebug() << "ERROR";
        return -3;
    }
    if(!q.exec("CREATE TABLE IF NOT EXISTS pedidos"
           "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"
           ", nombre VARCHAR(255) NOT NULL, direccion VARCHAR(255) NOT NULL, "
           "tipob VARCHAR(255) NOT NULL,cant VARCHAR(255) NOT NULL)")){
        qDebug() << "ERROR";
        return -3;
    }



    q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('Diego','54321','diegocj02@gmail.com','Vendedor')");
    q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('Roberto','121212','betohr48@gmail.com','Vendedor')");
    q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('admin','admin','example@example.com','Vendedor')");
    q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('Frida','a1a2a3','syahwat@hotmail.com','Recolector')");
    q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('Yael','1234','estradayael199@gmail.com','Recolector')");
    q.exec("INSERT INTO usuario(nombre,contra,mail,tipo) VALUES('admin','admin','example@example.com','Recolector')");

    q.exec("INSERT INTO productos(nombre,codigo,material,bote,imagen) VALUES('Botella agua','758104000159','plastico','PET','C:/Users/betoh/Desktop/Programas/Productos/botella.jpg')");
    q.exec("INSERT INTO productos(nombre,codigo,material,bote,imagen) VALUES('Boing','75001797','tetrapck','carton','C:/Users/betoh/Desktop/Programas/Productos/boing.jpg')");
    q.exec("INSERT INTO productos(nombre,codigo,material,bote,imagen) VALUES('Arizona','613008738846','lata','aluminio','C:/Users/betoh/Desktop/Programas/Productos/arizona.jpg')");
    q.exec("INSERT INTO productos(nombre,codigo,material,bote,imagen) VALUES('Cafe Ole','7503001453194','botella de cristal','vidrio','C:/Users/betoh/Desktop/Programas/Productos/cafeole.png')");
    q.exec("INSERT INTO productos(nombre,codigo,material,bote,imagen) VALUES('libreta','7891027179625','libreta de carton','carton','C:/Users/betoh/Desktop/Programas/Productos/libreta.jpg')");
    bd.close();
    return -5;
    return a.exec();
}
