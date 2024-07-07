//#define NOMINMAX //before including window

#include <iomanip>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>


//#include <Windows.h>

//#include <WinCon.h>



using namespace std;


/*
void timer(int sec)
{
   //cout<<"\e[?251"<<(unsigned char)176<<endl;

    
    
    printf("\e[?251 ");
   
  // SetConsoleCP(437);
  // SetConsoleOutputCP(437);

    
   char x=219;
    cout<<"\n\n\n\t\t\t\tlLoading...";
    cout<<"\n\n\n\t\t\t\t";

    

    for(int i=0; i<5; i++)
    {
      cout<<x;
      sleep(1);
    }
   
   cout<<"\n\t\t\t\t"<< (char)1 <<"!";
   system("clear");
   system("Pause");




    
    
    
    cout << "You have ... sec" << endl;
    sleep(sec);
    
    cout << "FireWorks !" << endl; 
} */

void timer(int sec)
{
   cout<<"\n\n\t\t\t\t";
   cout<<"You have "<<sec<<" sec to remember!";
   cout<<"\n\n\t\t\t\t\t";

    for(int i = 0; i < sec; i++)
    {
        cout << "|";
        cout.flush(); // Ensure immediate output of the character
        sleep(1); // Wait for 1 second
    }
    cout << endl; // Move to the next line after the timer ends
   
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