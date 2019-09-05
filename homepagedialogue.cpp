#include "homepagedialogue.h"
#include "ui_homepagedialogue.h"
#include "profiledialogue.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "user.h"
#include <string>
#include "groupsdialogue.h"
#include "friendspage_dialog.h"

homepagedialogue::homepagedialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homepagedialogue)
{
    ui->setupUi(this);
}

homepagedialogue::~homepagedialogue()
{
    delete ui;
}

void homepagedialogue::on_profile_clicked()
{
    profiledialogue prodialogue;
    prodialogue.setModal(true);
    prodialogue.exec();
}

void homepagedialogue::on_logout_clicked()
{
    QMessageBox::information(this,"Logout details","You have logged out. See you again!");
}

void homepagedialogue::on_groups_clicked()
{
    groupsdialogue gdialog;
    gdialog.setModal(true);
    gdialog.exec();
}

void homepagedialogue::on_pushButton_clicked()
{
    friendspage_dialog fpage;
    fpage.setModal(true);
    fpage.exec();
}

