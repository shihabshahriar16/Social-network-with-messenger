#include "seefrriends_dialog.h"
#include "ui_seefrriends_dialog.h"
#include "friendprofile_dialog.h"
#include "friendpost_dialog.h"
#include "global_var.h"
#include "user.h"
#include "message_dialog.h"
#include<string>
#include <QtCore>
#include <QtGui>
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

seefrriends_dialog::seefrriends_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seefrriends_dialog)
{
    ui->setupUi(this);
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString temp_u,temp_g;
     QSqlQuery qry;
    qry.prepare("SELECT * FROM friends where username1=:_uname or username2=:_uname");
    qry.bindValue(":_uname",uname);
    qry.exec();
    while( qry.next() )
    {
          temp_u = "";
          temp_u=qry.value(0).toString();

          if(temp_u==uname){
              temp_g=qry.value(1).toString();
              ui->listWidget->addItem(temp_g);
              }
          else {
              temp_g=qry.value(0).toString();
              ui->listWidget->addItem(temp_g);
          }
     }
}

seefrriends_dialog::~seefrriends_dialog()
{
    delete ui;
}

void seefrriends_dialog::on_removeFriend_button_clicked()
{
    QString uname = QString::fromStdString(user_obj->get_username());
    QString uname2 = ui->listWidget->currentItem()->text();
    QSqlQuery qry;
    qry.prepare("DELETE FROM friends WHERE username1=:_uname AND username2=:_uname2");
    qry.bindValue(":_uname", uname);
    qry.bindValue(":_uname2", uname2);
    qry.exec();
    qry.prepare("DELETE FROM friends WHERE username1=:_uname2 AND username2=:_uname");
    qry.bindValue(":_uname2", uname2);
    qry.bindValue(":_uname", uname);
    qry.exec();

    QMessageBox::information(this, "Action details" , "Friend removed successfully.");
    seefrriends_dialog seefriends;
    seefriends.setModal(true);
    seefriends.exec();
}

void seefrriends_dialog::on_seeFriendprofile_button_clicked()
{
    QString uname2 = ui->listWidget->currentItem()->text();
    friendprofile_dialog friendprofile(uname2);
    //friendprofile.set_uname2(uname2);
    friendprofile.setModal(true);
    friendprofile.exec();
}

void seefrriends_dialog::on_seFriendposts_button_clicked()
{
    if(ui->listWidget->count()!=0)
    {
        QString uname2 = ui->listWidget->currentItem()->text();
        friendpost_dialog friendpost(uname2);
        //friendpost.set_uname2(uname2);
        friendpost.setModal(true);
        friendpost.exec();
    }
    else
    {
        seefrriends_dialog seefriends;
        seefriends.setModal(true);
        seefriends.exec();
    }
}

void seefrriends_dialog::on_message_button_clicked()
{
    if(ui->listWidget->count()!=0)
    {
        QString uname2 = ui-> listWidget-> currentItem()->text();
        message_dialog messagefriend(uname2);
        messagefriend.setModal(true);
        messagefriend.exec();
    }
    else
    {
        seefrriends_dialog seefriends;
        seefriends.setModal(true);
        seefriends.exec();
    }
}
