#include "gotogroupdialogue.h"
#include "ui_gotogroupdialogue.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"
#include "group_n.h"
#include<string>
#include <QtCore>
#include <QtGui>
#include "inagroupdialogue.h"

gotogroupdialogue::gotogroupdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gotogroupdialogue)
{
    ui->setupUi(this);
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString temp_u,temp_g;
    QSqlQuery query;
     QSqlQuery qry;
    qry.prepare("SELECT * FROM groupmember_table");
    qry.exec();
    while( qry.next() )
        {
          temp_u = "";
          temp_u=qry.value(2).toString();

          if(temp_u==uname){
              temp_g=qry.value(0).toString();
              ui->listWidget->addItem(temp_g);
              }
          }
   query.exec();

}

gotogroupdialogue::~gotogroupdialogue()
{
    delete ui;
}

void gotogroupdialogue::on_Go_clicked()
{
    QString l;
    l=ui->listWidget->currentItem()->text();
    std::string _l = l.toLocal8Bit().constData();
    group_n_obj2=new group_n(_l);
    inagroupdialogue ingdialog;
    ingdialog.setModal(true);
    ingdialog.exec();
}
