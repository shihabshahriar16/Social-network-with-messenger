#include "peopleyoumayknow_dialog.h"
#include "ui_peopleyoumayknow_dialog.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"
#include<string>
#include <QtCore>
#include <QtGui>

peopleYouMayKnow_dialog::peopleYouMayKnow_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::peopleYouMayKnow_dialog)
{
    ui->setupUi(this);
    QString uname= QString::fromStdString(user_obj->get_username());
    QString uname2, uname3;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM friends where username1=:_uname or username2=:_uname");
    qry.bindValue(":_uname", uname);
    qry.exec();
    QString temp_uname="";
    while(qry.next())
    {
        uname2="";
        if(qry.value(0).toString()==uname)
            uname2=qry.value(1).toString();
        else uname2= qry.value(0).toString();
        QSqlQuery q;
        q.prepare("SELECT * FROM friends where username1=:_uname2 OR username2=:_uname2");
        q.bindValue(":_uname2", uname2);
        q.exec();
        bool are_friends;
        while(q.next())
        {
            are_friends=false;
            uname3="";
            if(q.value(0).toString()==uname2)
                uname3=q.value(1).toString();
            else uname3=q.value(0).toString();
            QSqlQuery q2;
            q2.prepare("SELECT * FROM friends WHERE username1=:_uname AND username2=:_uname3");
            q2.bindValue(":_uname", uname);
            q2.bindValue(":_uname3", uname3);
            q2.exec();
            while(q2.next())
            {
                if( (q2.value(0).toString()==uname) && (q2.value(1).toString()==uname3) )
                {
                    are_friends=true;
                    break;
                }
            }
            q2.prepare("SELECT * FROM friends WHERE username1=:_uname3 AND username2=:_uname");
            q2.bindValue(":_uname3", uname3);
            q2.bindValue(":_uname", uname);
            q2.exec();
            while(q2.next())
            {
                if( (q2.value(0).toString()==uname3) && (q2.value(1).toString()==uname) )
                {
                    are_friends=true;
                    break;
                }
            }
            bool request_sent=false;
            if(!are_friends)
            {
                QSqlQuery q_req;
                q_req.prepare("SELECT * FROM requests where sender=:_uname AND recipient=:_uname3");
                q_req.bindValue(":_uname", uname);
                q_req.bindValue(":_uname3", uname3);
                q_req.exec();
                while(q_req.next())
                {
                    if((q_req.value(0).toString()==uname) && (q_req.value(1).toString()==uname3))
                    {
                        request_sent=true;
                        break;
                    }
                }
            }

            if(!are_friends && !request_sent && uname!=uname3)
            {
                QList<QListWidgetItem *> items = ui->listWidget->findItems(uname3, Qt::MatchExactly);
                if(items.size()==0)
                    ui->listWidget->addItem(uname3);
            }

        }
    }
}

peopleYouMayKnow_dialog::~peopleYouMayKnow_dialog()
{
    delete ui;
}

void peopleYouMayKnow_dialog::on_pushButton_clicked()  // sending friend request
{
    if(ui->listWidget->count()!=0)
    {
        QString uname2;
        uname2=ui->listWidget->currentItem()->text();

        QString uname= QString::fromStdString( user_obj->get_username() );

        //checking if request already sent
        bool request_sent=false;
        QSqlQuery q;
        q.prepare("SELECT * FROM requests WHERE sender=:_uname2 AND recipient=:_uname");
        q.bindValue(":_uname2", uname2);
        q.bindValue(":_uname", uname);
        q.exec();
        while(q.next())
        {
            if( (q.value(0).toString()==uname2) && (q.value(1).toString()==uname) )
            {
                request_sent=true;
                QMessageBox::information(this, "Request details", "You already have a request from this person! Please review 'See Friend Request'. ");
                break;
            }
        }
        // end of check

        if(!request_sent)
        {
            QSqlQuery query1;
            query1.prepare("INSERT INTO requests (sender, recipient) "
                           "VALUES (?,?)");
            query1.addBindValue(uname);
            query1.addBindValue(uname2);
            query1.exec();
        }
    }
    peopleYouMayKnow_dialog people;
    people.setModal(true);
    people.exec();
}
