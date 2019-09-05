#include "signupdialogue.h"
#include "ui_signupdialogue.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

signupdialogue::signupdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupdialogue)
{
    ui->setupUi(this);
}

signupdialogue::~signupdialogue()
{
    delete ui;
}

void signupdialogue::on_pushButton_clicked()
{
   QString username= ui->lineEdit->text();
   QString email= ui->lineEdit_2->text();
   QString password= ui->lineEdit_3->text();
   QString c_pass= ui->lineEdit_4->text();

   if(c_pass==password){
       QSqlQuery query;
       query.prepare("INSERT INTO users_and_pass (username,email,password) "
                      "VALUES (?,?,?)");//:username,:email,:password)");
     //  QVariant dest=QString::fromStdString(username);

       query.addBindValue(username);
       query.addBindValue(email);
       query.addBindValue(password);
       query.exec();
   }
}
