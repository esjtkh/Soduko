#include "secondpage.h"
#include "ui_secondpage.h"
#include "thirdpage.h"
#include <QString>
#include <fstream>
//#include <iostream>
using namespace std;
#include "mainclass.h"
mainclass mncls1;

secondpage::secondpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondpage)
{
    ui->setupUi(this);
}

secondpage::~secondpage()
{
    delete ui;
}

void secondpage::on_submitbtn_clicked()
{
     QString name ;
     name = ui->lineEdit->text();
    mncls1.writefile(name);


    third=new thirdpage();
    hide();
    third->show();

    }
///////////////////////////////////////////////////////////



