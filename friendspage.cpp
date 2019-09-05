#include "friendspage.h"
#include "ui_friendspage.h"

friendspage::friendspage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendspage)
{
    ui->setupUi(this);
}

friendspage::~friendspage()
{
    delete ui;
}
