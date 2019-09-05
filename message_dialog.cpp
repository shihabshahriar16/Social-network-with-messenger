#include "message_dialog.h"
#include "ui_message_dialog.h"
#include "seefrriends_dialog.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

message_dialog::message_dialog(const QString &name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message_dialog), uname2(name)
{
    ui->setupUi(this);
    QSqlQuery qry;
        QString uname= QString::fromStdString( user_obj->get_username() );
        qry.prepare("SELECT sender,message_datetime, message_text FROM message_table where (sender=:_uname and reciever=:_uname2) or (sender=:_uname2 and reciever=:_uname) order by message_datetime asc");
        qry.bindValue(":_uname",uname);
        qry.bindValue(":_uname2", uname2);
        qry.exec();
       // qry.first();
        QString message_txt;
        while(qry.next()){
            message_txt=message_txt+qry.value(0).toString()+": \n    ";
           // time:
           // message_txt=message_txt+qry.value(1).toString()+" \n \n";
            message_txt=message_txt+qry.value(2).toString()+"\n \n";

        }
        ui->message_text_browser->setText(message_txt);
}

message_dialog::~message_dialog()
{
    delete ui;
}

void message_dialog::on_send_button_clicked()
{
    QString message_txt= ui->message_text_edit->toPlainText();

    QString uname= QString::fromStdString( user_obj->get_username() );

    QSqlQuery query;
    query.prepare("INSERT INTO message_table (sender,reciever, message_text, message_datetime) "
                       "VALUES (?,?, ?, sysdate())");
        //:username,:email,:password)");
         //  QVariant dest=QString::fromStdString(username);
        query.addBindValue(uname);
        query.addBindValue(uname2);
        query.addBindValue(message_txt);
        query.exec();

        message_dialog messagefriend(uname2);
        messagefriend.setModal(true);
        messagefriend.exec();


       // ui->message_text_browser->repaint();
       // qApp->processEvents();
       // self.text.setText(message_txt);
}
