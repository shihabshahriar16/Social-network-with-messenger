#include "newfriend_dialog.h"
#include "ui_newfriend_dialog.h"
#include "friendrequest_dialog.h"
#include "friendsearch_dialog.h"

newfriend_dialog::newfriend_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newfriend_dialog)
{
    ui->setupUi(this);
}

newfriend_dialog::~newfriend_dialog()
{
    delete ui;
}

void newfriend_dialog::on_seefriendrequest_button_clicked()
{
    friendrequest_dialog friendrequest;
    friendrequest.setModal(true);
    friendrequest.exec();
}

void newfriend_dialog::on_addnewfriend_button_clicked()
{
    friendsearch_dialog searchfriend;
    searchfriend.setModal(true);
    searchfriend.exec();
}
