#include "updateprofiledialog.h"
#include "ui_updateprofiledialog.h"
#include <QSqlDatabase>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "user.h"
#include "global_var.h"
#include <QMessageBox>

updateprofileDialog::updateprofileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateprofileDialog)
{
    ui->setupUi(this);
}

updateprofileDialog::~updateprofileDialog()
{
    delete ui;
}

void updateprofileDialog::on_update_clicked()
{
    QString uname= QString::fromStdString( user_obj->get_username() );
    QString email= ui->lineEdit->text();
    QString first_name= ui->lineEdit_2->text();
    QString last_name= ui->lineEdit_3->text();
    QString phone_number= ui->lineEdit_4->text();
    QString gender;
    QString blood_group=ui->lineEdit_5->text();
    if(ui->radioButton->isChecked())
        gender="Male";
    else {
        gender="Female";
    }
    QSqlQuery qry;

    qry.prepare("SELECT email,first_name,last_name,gender,blood_group,phone_number FROM users_and_pass where username=:_uname");
    qry.bindValue(":_uname",uname);
    qry.exec();
    qry.first();
    QString ret_email,ret_fname,ret_lname,ret_phno,ret_gender,ret_bg;
    ret_email=qry.value(0).toString();
    ret_fname=qry.value(1).toString();
    ret_lname=qry.value(2).toString();
    ret_gender=qry.value(3).toString();
    ret_bg=qry.value(4).toString();
    ret_phno=qry.value(5).toString();

    if(email!=nullptr){
        ret_email=email;
    }

    if(first_name!=nullptr){
        ret_fname=first_name;
    }

    if(last_name!=nullptr){
        ret_lname=last_name;
    }

    if(gender!=nullptr){
        ret_gender=gender;
    }

    if(phone_number!=nullptr){
        ret_phno=phone_number;
    }

    if(blood_group!=nullptr){
        ret_bg=blood_group;
    }
    //QMessageBox::information(this,"Post details",uname);


   // QString temp_u;
   // bool is_UserName_valid=false;
   /* qry.prepare("SELECT * FROM users_and_pass");
    qry.exec();
    while( qry.next() )
        {
          temp_u = "";
          temp_u=qry.value(0).toString();

          if(temp_u==uname){
              is_UserName_valid=true;*/
                  /*   testing global user class obect   */

                  QSqlQuery query;
                  query.prepare("UPDATE users_and_pass SET  email=:e_mail,first_name=:f_name, last_name=:l_name, gender=:g, blood_group=:bg,phone_number=:phn where username=:_uname ");
                             //      "VALUES (?,?,?,?,?,?)");//:username,:email,:password)""where temp_u=u_name");
                  //  QVariant dest=QString::fromStdString(username);
                   /*if(email==nullptr){

                              query.bindValue(":e_mail",ret_email);
                    }

                    else{
                         QMessageBox::information(this,"test","ekhane achi bhaiya");
                         query.bindValue(":e_mail",email);
                    }


                    if(first_name==nullptr)
                        query.bindValue(":f_name",ret_fname);
                    else
                        query.bindValue(":f_name",first_name);

                    if(last_name==nullptr)
                        query.bindValue(":l_name",ret_lname);
                    else
                        query.bindValue(":l_name",last_name);


                    if(gender==nullptr)
                        query.bindValue(":g",ret_gender);
                    else
                        query.bindValue(":g",gender);

                    if(blood_group==nullptr)
                        query.bindValue(":bg",ret_bg);
                    else
                        query.bindValue(":bg",blood_group);

                    if(phone_number==nullptr)
                        query.bindValue(":phn",ret_phno);
                    else
                        query.bindValue(":phn",phone_number);
*/
                    query.bindValue(":e_mail",ret_email);
                    query.bindValue(":f_name",ret_fname);
                    query.bindValue(":l_name",ret_lname);

                    query.bindValue(":phn",ret_phno);
                    query.bindValue(":g",ret_gender);
                    query.bindValue(":bg",ret_bg);
                    query.bindValue(":_uname",uname);
                    query.exec();



          }


