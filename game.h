#ifndef game_h
#define game_h

#include <iostream>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

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

int doYesNo()
{
    char ans;
    do{
        fflush(stdin);
        cout << "answer Y or N: ";
        cin >> ans;
        if(ans=='y'||ans=='Y') return 1;
        else if(ans=='n'||ans=='N') return 2;
    } while (ans!='y'||ans!='Y'||ans!='n'||ans!='N');
    return 0;
}

int prologue()
{
    system("clear");

    cout<<"Before the noodle shop opened, our family knew the harsh reality of poverty and hunger. \n\n";
    sleep(2);
    cout<<"Once the shop began to flourish, it brought us financial stability and allowed my parents to help others in need. \n\n";
    sleep(3);
    cout<<"Inspired by their generosity, I now carry on the family business with a mission: \n\n";
    sleep(2);
    cout<<"to sustain our livelihood while generating enough profit to support those struggling with poverty and hunger. \n\n";
    sleep(3);
    cout<<"Welcome to our noodle shop, where every bowl served brings hope to our community. \n\n";
    
    pressEnterToContinue();
    system("clear");

    return 0;
}

#endif
