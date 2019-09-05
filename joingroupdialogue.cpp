#include "joingroupdialogue.h"
#include "ui_joingroupdialogue.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"

joingroupdialogue::joingroupdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joingroupdialogue)
{
    ui->setupUi(this);
}

joingroupdialogue::~joingroupdialogue()
{
    delete ui;
}

void joingroupdialogue::on_join_clicked()
{
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString group_code= ui->gcode->text();
    QString group_name= ui->gname->text();
    QSqlQuery query;
    // bool sign_in_successful=false;
     QSqlQuery qry;
     QString temp_g,temp_c;
     bool is_GroupName_valid=false;
     qry.prepare("SELECT * FROM groupmember_table");
     qry.exec();
     while( qry.next() )
         {
           temp_g = "";
           temp_g=qry.value(0).toString();

           if(temp_g==group_name){
               is_GroupName_valid=true;
               temp_c=qry.value(1).toString();
               if(temp_c==group_code){
                   QSqlQuery query1;
                   query1.prepare("INSERT INTO groupmember_table (groupname,groupcode,member) "
                                  "VALUES (?,?,?)");
                   query1.addBindValue(group_name);
                   query1.addBindValue(group_code);
                   query1.addBindValue(uname);
                   query1.exec();
                   QMessageBox::information(this,"Join details","You have Successfully joined the group.");
               }
               else{
                   QMessageBox::information(this,"Login details","Incorrect group name or group code.");
                   break;
               }

           }
    }
    query.exec();
}
