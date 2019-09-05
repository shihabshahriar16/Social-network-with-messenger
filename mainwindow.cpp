#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menudialogue.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionlet_s_begin_triggered()
{
    menudialogue mendialogue;
    mendialogue.setModal(true);
    mendialogue.exec();
}
