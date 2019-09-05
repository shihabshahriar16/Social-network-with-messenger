#include "creategroupsdialogue.h"
#include "ui_creategroupsdialogue.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"

creategroupsdialogue::creategroupsdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creategroupsdialogue)
{
    ui->setupUi(this);
}

creategroupsdialogue::~creategroupsdialogue()
{
    delete ui;
}

void creategroupsdialogue::on_create_clicked()
{
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString group_code= ui->gcode->text();
    QString group_name= ui->gname->text();
    QSqlQuery query;
    query.prepare("INSERT INTO groupmember_table (groupname,groupcode,member) "
                   "VALUES (?,?,?)");
    query.addBindValue(group_name);
    query.addBindValue(group_code);
    query.addBindValue(uname);

    query.exec();
}
