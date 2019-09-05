#include "friendspage_dialog.h"
#include "ui_friendspage_dialog.h"
#include "seefrriends_dialog.h"
#include "newfriend_dialog.h"
#include "peopleyoumayknow_dialog.h"

friendspage_dialog::friendspage_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendspage_dialog)
{
    ui->setupUi(this);
}

friendspage_dialog::~friendspage_dialog()
{
    delete ui;
}

void friendspage_dialog::on_seeFriends_button_clicked()
{
    seefrriends_dialog seefriends;
    seefriends.setModal(true);
    seefriends.exec();
}

void friendspage_dialog::on_makeNewFriend_button_clicked()
{
    newfriend_dialog newfriend;
    newfriend.setModal(true);
    newfriend.exec();
}

void friendspage_dialog::on_peopleYouMayKow_button_clicked()
{
    peopleYouMayKnow_dialog people;
    people.setModal(true);
    people.exec();
}
