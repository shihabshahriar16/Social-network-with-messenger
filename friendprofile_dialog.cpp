#include "friendprofile_dialog.h"
#include "ui_friendprofile_dialog.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


friendprofile_dialog::friendprofile_dialog(const QString &name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendprofile_dialog), uname2(name)
{
    ui->setupUi(this);
    QSqlQuery qry;
    qry.prepare("SELECT * FROM users_and_pass where username=:_uname2");
    qry.bindValue(":_uname2",uname2);
    qry.exec();
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


friendprofile_dialog::~friendprofile_dialog()
{
    delete ui;
}

void friendprofile_dialog::set_uname2(QString uname2)
{
    this->uname2=uname2;
}

QString friendprofile_dialog::get_uname2()
{
    return this->uname2;
}
