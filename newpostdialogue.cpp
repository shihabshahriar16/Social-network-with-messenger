#include "newpostdialogue.h"
#include "ui_newpostdialogue.h"
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
#include "global_var.h"



newpostdialogue::newpostdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newpostdialogue)
{
    ui->setupUi(this);
}

newpostdialogue::~newpostdialogue()
{
    delete ui;
}

void newpostdialogue::on_post_clicked()
{
    QString post= ui->textEdit->toPlainText();

    /* global user class object */

    QString uname= QString::fromStdString( user_obj->get_username() );
    // no need ... QMessageBox::information(this,"Post details",uname);

    QSqlQuery query;
    query.prepare("INSERT INTO post_table (username,post, post_datetime) "
                       "VALUES (?,?, sysdate())");
        //:username,:email,:password)");
         //  QVariant dest=QString::fromStdString(username);
        query.addBindValue(uname);
        query.addBindValue(post);
        QMessageBox::information(this,"Post details","Sucessfully posted.");
        query.exec();

}
