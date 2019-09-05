#include "menudialogue.h"
#include "ui_menudialogue.h"
#include "signindialogue.h"
#include "signupdialogue.h"

menudialogue::menudialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menudialogue)
{
    ui->setupUi(this);
}

menudialogue::~menudialogue()
{
    delete ui;
}

void menudialogue::on_signin_clicked()
{
    signindialogue sindialogue;
    sindialogue.setModal(true);
    sindialogue.exec();
}


void menudialogue::on_signup_clicked()
{
    signupdialogue supdialogue;
    supdialogue.setModal(true);
    supdialogue.exec();
}
