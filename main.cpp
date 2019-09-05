#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"




int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase :: addDatabase("QMYSQL");


    QApplication a(argc, argv);
    db.setHostName("192.168.0.116");
    db.setUserName("alo");
    db.setPassword("123");
    db.setDatabaseName("facebook");
    db.open();
    MainWindow w;
    w.show();

    return a.exec();
}
