#include "grouppostdialogue.h"
#include "ui_grouppostdialogue.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <string>
#include "user.h"
#include "group_n.h"
#include "global_var.h"

grouppostdialogue::grouppostdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grouppostdialogue)
{
    ui->setupUi(this);
}

grouppostdialogue::~grouppostdialogue()
{
    delete ui;
}

void grouppostdialogue::on_pushButton_clicked()
{
    QString post= ui->textEdit->toPlainText();

    QString uname= QString::fromStdString( user_obj->get_username() );
    QString gname= QString::fromStdString( group_n_obj2->get_groupname() );
    QSqlQuery query;
    query.prepare("INSERT INTO groups_table (groupname,username,post,post_datetime) "
                       "VALUES (?,?,?, sysdate())");
        query.addBindValue(gname);
        query.addBindValue(uname);
        query.addBindValue(post);
        QMessageBox::information(this,"Post details","Sucessfully posted.");
        query.exec();
}
