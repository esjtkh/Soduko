#include "thirdpage.h"
#include "ui_thirdpage.h"
#include "mainclass.h"
#include <string>
#include <QString>
#include <fstream>
using namespace std;
 mainclass mncls;

thirdpage::thirdpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdpage)

{
    ui->setupUi(this);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            mncls.nums[i][j]=-1;
        }
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
           mncls.itemstate[i][j]=false;
        }
    }

    mncls.nums[0][1]=2;
    mncls.nums[0][5]=7;
    mncls.nums[0][8]=1;
    mncls.nums[1][3]=3;
    mncls.nums[1][4]=2;
    mncls.nums[1][7]=4;
    mncls.nums[2][1]=5;
    mncls.nums[3][2]=2;
    mncls.nums[3][5]=9;
    mncls.nums[4][3]=8;
    mncls.nums[5][0]=1;
    mncls.nums[5][7]=9;
    mncls.nums[5][8]=3;
    mncls.nums[6][4]=9;
    mncls.nums[7][1]=7;
    mncls.nums[8][0]=9;
    mncls.nums[7][5]=3;
    mncls.nums[8][8]=2;
}

thirdpage::~thirdpage()
{
    delete ui;
}




void thirdpage::on_tableWidget_cellChanged(int row, int column)
{
    ///////////////////////////////////////////////////////////////////////




      QString a=(ui->tableWidget->item(row,column)->text());

       int b =a.toInt();

       mncls.nums[row][column]=b;
       bool state=false;
       bool state2=true;



//////if item is red
///
       if(ui->tableWidget->item(row,column)->QTableWidgetItem::background()==Qt::red)
       {
           if(state2!=false)
           {
           for(int i=0;i<9;i++)
           {
               if(i != column )
              {
               if(mncls.nums[row][i]==b)
                {
               ui->tableWidget->item(row,column)->setBackground(Qt::red);
               state2=false;
               break;
                }
              }
       }
           }
           if(state2!=false)
           {
           for(int i=0;i<9;i++)
           {
               if(i!=row )
               {
               if(mncls.nums[i][column]==b)
                {
                   ui->tableWidget->item(row,column)->setBackground(Qt::red);
                   state2=false;
                }
               }
           }
           }
           if(state2!=false)
           {
               int row2=row-(row%3);
               int column2=column-(column%3);
               for(int i=row2;i<row2+3;i++)
               {
                   for(int j=column2;j<column2+3;j++)
                   {
                       if(j!=column)
                       {
                       if( mncls.nums[i][j]==b)
                       {
                            ui->tableWidget->item(row,column)->setBackground(Qt::red);
                            state2=false;
                            break;
                       }
                       }
                   }

               }

               if(state2!=false)
               {
               ui->tableWidget->item(row,column)->setBackground(Qt::white);
                 mncls.itemstate[row][column]=true;
                 state2=true;
               }
           }




          /* if(state2==true)
           {
               ui->tableWidget->item(row,column)->setBackground(Qt::white);
               mncls.itemstate[row][column]=true;

           }*/
   }

       else if( ui->tableWidget->item(row,column)->text()=="")
       {
           ui->tableWidget->item(row,column)->QTableWidgetItem::background()=Qt::white;
       }

////////////////////////////////////////////////////////////////////////////////////

//if item is white.

   else
 {
if(state!=true)
{
   for(int i=0;i<9;i++)
   {
       if(i!=column )
       {
       if(mncls.nums[row][i]==b)
        {
           ui->tableWidget->item(row,column)->setBackground(Qt::red);
           state=true;
           break;
        }
       }
   }
}
    if(state !=true)
   {
       for(int i=0;i<9;i++)
       {
           if(i!=row && state==false)
           {
           if(mncls.nums[i][column]==b)
            {
               ui->tableWidget->item(row,column)->setBackground(Qt::red);
               state=true;
               break;
            }
           }
       }

       if(state!=true)
       {
           int row2=row-(row%3);
           int column2=column-(column%3);

           for(int i=row2;i<row2+3;i++)
           {
               for(int j=column2;j<column2+3;j++)
               {
                   if(j!=column)
                   {
                   if( mncls.nums[i][j]==b)
                   {
                        ui->tableWidget->item(row,column)->setBackground(Qt::red);
                        state=true;
                        break;
                   }
                   }
               }
           }



       if(state==false)
       {
            mncls.itemstate[row][column]=true;

       }
   }

 }
 }

}

////////////////////////////////////////////////////////////////////////////////////



void thirdpage::on_pushButton_clicked()
{

    ofstream file ("info.txt" , ios::out | ios :: app);
    int score=0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(mncls.nums[i][j]>-1 && mncls.itemstate[i][j]==true)
            {
                score++;
            }
        }
    }
    file<<score<<endl;
    file.close();

    mncls.readfile();


    ////////////////////////
    this->hide();
    four=new fourth();
    four->show();


}
