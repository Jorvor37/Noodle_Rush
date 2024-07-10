#include<iostream>
#include "order.h"
using namespace std;
#include<unistd.h>

int tutorial()
{
    order bowl(1,2,3,2,0);
    
    system("clear");
    cout<<"\t\t\tTUTORIAL \n\n";
    sleep(1);
    cout<<"\t\t   7 days of selling. \n\n";
    sleep(1);
    cout<<"As the day passes by , the harder it gets. -> Less time you will get. \n\n";
    sleep(2);
    cout<<"\t   The menu will be random each round.\n\n";
    sleep(1);
    cout<<"\t   This is the menu for tutorial round.\n";
    cout<<"In the actual round, there will be timer for you to memorize the menu.\n";
    sleep(1);

    cout<<"   ___________________________________________________________"<<endl;
    cout<<"\n\t"<<bowl.get_name()<<endl;
    cout<<"   ___________________________________________________________\n"<<endl;
    sleep(4);
    cout<<"\tselect the right answer to serve a bowl of noodle.\n"<<endl;
    cout<<"if you pick the wrong ingredient, your money will get deducted 5 baht each.\n"<<endl;

    bowl.select_noodle();
    bowl.select_meat();
    bowl.select_soup();
    bowl.select_veg();
    bowl.tutorialCashier();

    pressEnterToContinue();
    
    system("clear");
    cout<<"\t\t\t   Let's get started! \n";
    sleep(2);
    system("clear");

    
    return 0;
}

