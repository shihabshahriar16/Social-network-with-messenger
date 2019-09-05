#include "inagroupdialogue.h"
#include "ui_inagroupdialogue.h"
#include "grouppostdialogue.h"
#include "showmembersdialogue.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include<QString>
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "group_n.h"

inagroupdialogue::inagroupdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inagroupdialogue)
{
    ui->setupUi(this);
    //will do posts here;
    QSqlQuery qry;
        QString gname= QString::fromStdString( group_n_obj2->get_groupname() );
        qry.prepare("SELECT * FROM groups_table where groupname=:_uname order by post_datetime desc");
        qry.bindValue(":_uname",gname);
        qry.exec();
       // qry.first();
        QString post;
        while(qry.next()){
            post=post+qry.value(1).toString()+"\n";
            post=post+qry.value(2).toString()+"\n";
            post=post+qry.value(3).toString()+"\n \n \n \n \n \n";

        }
        ui->textBrowser->setText(post);

}

inagroupdialogue::~inagroupdialogue()
{
    delete ui;
}

void inagroupdialogue::on_post_clicked()
{
    grouppostdialogue gpdialog;
    gpdialog.setModal(true);
    gpdialog.exec();
}

void inagroupdialogue::on_show_clicked()
{
    showmembersdialogue smdialog;
    smdialog.setModal(true);
    smdialog.exec();


}

void inagroupdialogue::on_leave_clicked()
{
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString gname= QString::fromStdString( group_n_obj2->get_groupname() );
    QSqlQuery query;
    query.prepare("DELETE FROM groupmember_table where groupname=:_gname and member=:_uname");
        query.bindValue(":_gname",gname);
       query.bindValue(":_uname",uname);
        QMessageBox::information(this,"Post details","Group left. You will be missed.");
        query.exec();
}
