#include "groupsdialogue.h"
#include "ui_groupsdialogue.h"
#include "creategroupsdialogue.h"
#include "joingroupdialogue.h"
#include "gotogroupdialogue.h"

groupsdialogue::groupsdialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::groupsdialogue)
{
    ui->setupUi(this);
}

groupsdialogue::~groupsdialogue()
{
    delete ui;
}

void groupsdialogue::on_creategroup_clicked()
{
    creategroupsdialogue cgdialog;
    cgdialog.setModal(true);
    cgdialog.exec();
}

void groupsdialogue::on_joingroup_clicked()
{
    joingroupdialogue jgdialog;
    jgdialog.setModal(true);
    jgdialog.exec();
}

void groupsdialogue::on_gogroup_clicked()
{
    gotogroupdialogue gtdialog;
    gtdialog.setModal(true);
    gtdialog.exec();
}
