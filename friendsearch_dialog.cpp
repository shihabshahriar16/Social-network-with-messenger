#include "friendsearch_dialog.h"
#include "ui_friendsearch_dialog.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"
#include<string>
#include <QtCore>
#include <QtGui>

friendsearch_dialog::friendsearch_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendsearch_dialog)
{
    ui->setupUi(this);
}

friendsearch_dialog::~friendsearch_dialog()
{
    delete ui;
}

void friendsearch_dialog::on_sendrequest_button_clicked()
{
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString uname2=ui->usernamesearch->text();
    QSqlQuery qry;
    QString temp_u,temp_c;
    bool is_uname2_valid=false;
    qry.prepare("SELECT * FROM users_and_pass where username=:_uname2");
    qry.bindValue(":_uname2", uname2);
    qry.exec();
    while(qry.next())
    {
        temp_u="";
        temp_u= qry.value(0).toString();
        if(temp_u==uname2)
        {
            is_uname2_valid=true;


            // check if already friends
            QSqlQuery q;
            q.prepare("SELECT * FROM friends where username1=:_uname or username2=:_uname");
            q.bindValue(":_uname", uname);
            q.exec();
            QString t_name, t_name2;
            bool are_friends = false;
            while(q.next())
            {
                t_name=""; t_name2="";
                t_name=q.value(0).toString();
                t_name2=q.value(1).toString();
                if( (t_name==uname && t_name2==uname2) || (t_name==uname2 && t_name2==uname) )
                {
                    are_friends = true;
                    break;
                }
            }
            if(are_friends)
            {
                QMessageBox::information(this, "Request details", "You two are already friends!");
                break;
            }
            // end of checking


            QSqlQuery query1;
            query1.prepare("INSERT INTO requests (sender, recipient) "
                           "VALUES (?,?)");
            query1.addBindValue(uname);
            query1.addBindValue(uname2);
            query1.exec();
            QMessageBox::information(this,"Request details","Request Sent!");
            break;

        }
        else{
            QMessageBox::information(this,"Error details","Incorrect username.");
            break;
        }

    }

    friendsearch_dialog searchfriend;
    searchfriend.setModal(true);
    searchfriend.exec();
}
