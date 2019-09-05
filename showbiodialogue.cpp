#include "showbiodialogue.h"
#include "ui_showbiodialogue.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include<QString>
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

showbiodialogue::showbiodialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showbiodialogue)
{
    ui->setupUi(this);
    QSqlQuery qry;
        QString uname= QString::fromStdString( user_obj->get_username() );
        qry.prepare("SELECT * FROM users_and_pass where username=:_uname");
        qry.bindValue(":_uname",uname);
        qry.exec();
       // qry.first();
        QString post;
        while(qry.next()){
            post=post+"Username:\t\t "+qry.value(0).toString()+"\n";
            post=post+"E-mail:\t\t "+qry.value(1).toString()+"\n";
            post=post+"First Name:\t\t "+qry.value(3).toString()+"\n";
            post=post+"Last Name:\t\t "+qry.value(4).toString()+"\n";
            post=post+"Gender:\t\t "+qry.value(5).toString()+"\n";
            post=post+"Blood Group:\t\t "+qry.value(6).toString()+"\n";
            post=post+"Phone number:\t "+qry.value(7).toString()+"\n";

        }
        ui->textBrowser->setText(post);
}

showbiodialogue::~showbiodialogue()
{
    delete ui;
}
