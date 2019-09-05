#include "friendpost_dialog.h"
#include "ui_friendpost_dialog.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


friendpost_dialog::friendpost_dialog(const QString &name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendpost_dialog), uname2(name)
{
    ui->setupUi(this);
    QSqlQuery qry;
        //QString uname= QString::fromStdString( user_obj->get_username() );

    qry.prepare("SELECT post,post_datetime FROM post_table where username=:_uname2 order by post_datetime desc");
    qry.bindValue(":_uname2",uname2);
    qry.exec();
    QString post;
    while(qry.next()){
        post=post+qry.value(0).toString()+"\n";
        post=post+qry.value(1).toString()+"\n \n \n \n \n \n";
    }

    ui->textBrowser->setText(post);
}

friendpost_dialog::~friendpost_dialog()
{
    delete ui;
}
