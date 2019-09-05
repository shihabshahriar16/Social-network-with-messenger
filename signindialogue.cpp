#include "signindialogue.h"
#include "ui_signindialogue.h"
#include "homepagedialogue.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include<string>
#include "user.h"
#include "global_var.h"

signindialogue::signindialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signindialogue)
{
    ui->setupUi(this);
}

signindialogue::~signindialogue()
{
    delete ui;
}

void signindialogue::on_pushButton_clicked()
{

   // bool sign_in_successful=false;
    QString uname=ui->uname_login->text();
    QString pass=ui->uname_pass->text();
    QSqlQuery qry;
    QString temp_u,temp_p;
    bool is_UserName_valid=false;
    qry.prepare("SELECT * FROM users_and_pass");
    qry.exec();
    while( qry.next() )
        {
          temp_u = "";
          temp_u=qry.value(0).toString();

          if(temp_u==uname){
              is_UserName_valid=true;
              temp_p=qry.value(2).toString();
              if(temp_p==pass){
                  QMessageBox::information(this,"Login details","Login Successful.");

                  /*   testing global user class obect   */

                  std::string _email = "email goes here";
                  std::string _uname = uname.toLocal8Bit().constData();   //converting QString to std::string
                  std::string _pass = pass.toLocal8Bit().constData();
                  user_obj=new user(_uname, _pass, _email);

                  // no need ....  QString te= QString::fromStdString(user_obj->get_username());
                  //no need ....  QMessageBox::information(this,"Post details", te );

                  /*   end of testing   */


                  homepagedialogue homdialogue;
                  homdialogue.setModal(true);
                  homdialogue.exec();
              }
              else{
                  QMessageBox::information(this,"Login details","Incorrect Username or Password.");
                  break;
              }

          }



        }
    if(is_UserName_valid==false){
            QMessageBox::information(this,"Login details","Incorrect Username or Password.");

    }

}
