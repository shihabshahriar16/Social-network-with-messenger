#include "friendrequest_dialog.h"
#include "ui_friendrequest_dialog.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"
#include<string>
#include <QtCore>
#include <QtGui>

friendrequest_dialog::friendrequest_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendrequest_dialog)
{
    ui->setupUi(this);
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString temp_u;
     QSqlQuery qry;
    qry.prepare("SELECT * FROM requests where recipient=:_uname");
    qry.bindValue(":_uname",uname);
    qry.exec();
    while( qry.next() )
    {
          temp_u = "";
          temp_u=qry.value(0).toString();
          ui->listWidget->addItem(temp_u);
     }
}

friendrequest_dialog::~friendrequest_dialog()
{
    delete ui;
}

void friendrequest_dialog::on_accept_button_clicked()
{
    QString uname2;
    uname2=ui->listWidget->currentItem()->text();
    // not necessary ... std::string uname2 = l.toLocal8Bit().constData();
    QString uname= QString::fromStdString( user_obj->get_username() );
    QSqlQuery qry;
    qry.prepare("DELETE FROM requests WHERE sender=:_u2 AND recipient=:_u1");
    qry.bindValue(":_u2",uname2);
    qry.bindValue(":_u1", uname);
    qry.exec();
    bool are_friends=false;
    qry.prepare("SELECT * FROM friends where username1=:_uname OR username2=:_uname");
    qry.bindValue(":_uname", uname);
    qry.exec();
    while(qry.next())
    {
        if( (qry.value(0).toString()==uname) && (qry.value(1).toString()==uname2) )
        {
            are_friends=true;
            break;
        }
        else if( (qry.value(0).toString()==uname2) && (qry.value(1).toString()==uname) )
        {
            are_friends=true;
            break;
        }
    }
    if(are_friends)
    {
        QMessageBox::information(this, "Request details", "You two are already friends!");
    }
    else {
        QSqlQuery query2;
        query2.prepare("INSERT INTO friends(username1, username2)"
                       "VALUES(?,?)");
        query2.addBindValue(uname);
        query2.addBindValue(uname2);
        query2.exec();
    }
    friendrequest_dialog friendrequest;
    friendrequest.setModal(true);
    friendrequest.exec();
}
void friendrequest_dialog::on_decline_button_clicked()
{
    QString uname2;
    uname2=ui->listWidget->currentItem()->text();
    QString uname= QString::fromStdString( user_obj->get_username() );
    QSqlQuery qry;
    qry.prepare("DELETE FROM requests WHERE sender=:_u2 AND recipient=:_u1");
    qry.bindValue(":_u2",uname2);
    qry.bindValue(":_u1", uname);
    qry.exec();

    bool are_friends=false;
    qry.prepare("SELECT * FROM friends where username1=:_uname OR username2=:_uname");
    qry.bindValue(":_uname", uname);
    qry.exec();
    while(qry.next())
    {
        if( (qry.value(0).toString()==uname) && (qry.value(1).toString()==uname2) )
        {
            are_friends=true;
            break;
        }
        else if( (qry.value(0).toString()==uname2) && (qry.value(1).toString()==uname) )
        {
            are_friends=true;
            break;
        }
    }
    if(are_friends)
    {
        QMessageBox::information(this, "Request details", "You two are already friends! If you want to remove this friend, please go to 'See Friends'. ");
    }

    friendrequest_dialog friendrequest;
    friendrequest.setModal(true);
    friendrequest.exec();
}
