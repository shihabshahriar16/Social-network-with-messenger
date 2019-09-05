#include "showmembersdialogue.h"
#include "ui_showmembersdialogue.h"
#include "group_n.h"
#include "user.h"
#include "global_var.h"
#include <string>
#include <QMessageBox>
#include<QString>
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

showmembersdialogue::showmembersdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showmembersdialogue)
{
    ui->setupUi(this);
    //will write here;
    QSqlQuery qry;
        QString gname= QString::fromStdString( group_n_obj2->get_groupname() );
        qry.prepare("SELECT * FROM groupmember_table where groupname=:_uname");
        qry.bindValue(":_uname",gname);
        qry.exec();
       // qry.first();
        QString post;
        while(qry.next()){
            post=post+qry.value(2).toString()+"\n";
        }
        ui->textBrowser->setText(post);
}

showmembersdialogue::~showmembersdialogue()
{
    delete ui;
}
