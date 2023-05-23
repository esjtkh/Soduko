#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <string>
#include<QString>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class mainclass
{
public:
    mainclass();

    int nums[9][9];
     bool itemstate[9][9];

    void writefile( QString name)
    {
        ofstream file ("info.txt" , ios::out | ios :: app);
        string a = name.toStdString();
        file << a <<endl;
        file.close();


    };
    void readfile()
    {
        //read in file
        string names[100];
        int nums[100];
        int j= 0;
       ifstream file1("info.txt" , ios::in | ios :: app);
       string name1;

       //send to array

       while(!file1.eof())
       {
           file1>>names[j];
           file1>>nums[j];
           j++;
       }


       ///sort data in file

       for(int k=0;k<j-1;k++)
       {

           int a=nums[k];
           int max=a,imax=k;
           int b;

          for(int index=k+1;index<j-1;index++)
         {
               b=nums[index];
           if(b>max)
           {
               max=b;
               imax=index;
           }
         }
          string temp=names[k];
          names[k]=names[imax];
          names[imax]=temp;

          int tmpnum=nums[k];
          nums[k]=nums[imax];
          nums[imax]=tmpnum;

       }
        ofstream file ("info.txt" , ios::out );


           for(int i=0;i<j-1;i++)
           {

               file<<names[i]<<endl;
               file<<nums[i]<<endl;

           }
       file1.close();
       file.close();


    };
};

#endif // MAINCLASS_H
