#define NOMINMAX //before including window

#include <iomanip>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

#include <Windows.h>
#include <WinCon.h>
#include <ConsoleApi2.h>


using namespace std;

void timer(int sec)
{
   //cout<<"\e[?251"<<(unsigned char)176<<endl;

    system("COLOR E4");
    system("cls");
   printf("\e[?251");
   
   SetConsoleCP(437);
   SetConsoleOutputCP(437);

    int bar1=177, bar2=219;
    cout<<"\n\n\n\t\t\t\tLoading...";
    cout<<"\n\n\n\t\t\t\t";

    for (int i =0; i<25; i++) cout<<(char)bar1;

    cout<<"\r";
    cout<<"\t\t\t\t";

    for(int i=0; i<25; i++)
    {
      cout<<(char)bar2;
      sleep(sec);
    }
   cout<<"\n\t\t\t\t"<< (char)1 <<"!";
   system("Pause");




    
    /*
    
    cout << "You have ... sec" << endl;
    sleep(sec);
    
    cout << "FireWorks !" << endl;*/
}






/*void pressEnterToContinue()
{

}

bool timer(int &s)
{
   while (s!=0)
   {
      Sleep(1000);
      s-=1;

      cout<<setw(s)<<setfill('x');
   }
   return true;
}*/