#include <iomanip>
#include <iostream>
#include <ctime>
#include <unistd.h>
//include <windows.h>
using namespace std;

void pressEnterToContinue()
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
}