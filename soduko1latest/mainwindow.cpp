#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondpage.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     secp = new secondpage();
     hide();
    secp->show();   
}
