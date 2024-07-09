#include <iostream>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#ifndef game_h
#define game_h

using namespace std;

void timer(int sec)
{
    cout << "\n\n\t\t\t\t\t";
    cout << "You have " << sec << " sec to remember!"<<endl;       
    for(int i = 0; i < sec; i++)
    {
        cout << "\t\t\t\t\t\t"; 
        for(int j = 0; j <= i; j++) {
            cout << "[]";
        }
        fflush(stdin);
        sleep(1); 
        cout << "\n\t\t\t\t\t\t" << "..." << (i + 1)*100/sec<< "%..." << flush;
        cout << "\033[F"; // ANSI escape code to move cursor up one line
    }
    sleep(1);
    system("clear");
}

void pressEnterToContinue()
{
    fflush(stdin);
    cout << "Press Enter to Continue"<<endl;
    while (getchar()!='\n');
    //system("clear");
}

#endif