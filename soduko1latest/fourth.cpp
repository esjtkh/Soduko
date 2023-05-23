#include "fourth.h"
#include "ui_fourth.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>

fourth::fourth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fourth)
{
    ui->setupUi(this);
///read in file

    QFile file("info.txt");
    QTextStream in(&file);

    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    while(!file.atEnd())
    {
    ui->textBrowser->setText((in.readAll()));
    }
}

fourth::~fourth()
{
    delete ui;
}


