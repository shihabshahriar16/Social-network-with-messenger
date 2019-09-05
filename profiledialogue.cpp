#include "profiledialogue.h"
#include "ui_profiledialogue.h"
#include "newpostdialogue.h"
#include "updateprofiledialog.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include<QString>
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "showbiodialogue.h"

profiledialogue::profiledialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profiledialogue)
{
    ui->setupUi(this);
    QSqlQuery qry;
        QString uname= QString::fromStdString( user_obj->get_username() );
        qry.prepare("SELECT post,post_datetime FROM post_table where username=:_uname order by post_datetime desc");
        qry.bindValue(":_uname",uname);
        qry.exec();
       // qry.first();
        QString post;
        while(qry.next()){
            post=post+qry.value(0).toString()+"\n";
            post=post+qry.value(1).toString()+"\n \n \n \n \n \n";

        }
        ui->mypost->setText(post);

}

profiledialogue::~profiledialogue()
{
    delete ui;
}

void profiledialogue::on_newpost_clicked()
{
    newpostdialogue posdialogue;
    posdialogue.setModal(true);
    posdialogue.exec();
}

void profiledialogue::on_updateprofile_clicked()
{
    updateprofileDialog updatepro;
    updatepro.setModal(true);
    updatepro.exec();
}





void profiledialogue::on_pushButton_clicked()
{
    showbiodialogue sbdialog;
    sbdialog.setModal(true);
    sbdialog.exec();
}
