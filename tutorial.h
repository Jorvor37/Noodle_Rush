#include<iostream>
#include "order.h"
using namespace std;
#include<unistd.h>

int tutorial()
{
    order bowl(1,2,3,2);
    
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


    cout<<"   ___________________________________________________________"<<endl;
    cout<<"\n\t"<<bowl.get_name()<<endl;
    cout<<"   ___________________________________________________________\n"<<endl;
    sleep(4);

    bowl.select_noodle(1);
    bowl.select_meat(2);
    bowl.select_soup(3);
    bowl.select_veg(2);
    
    system("clear");
    cout<<"\t\t\t   Let's get started! \n";
    sleep(2);
    system("clear");

    
    return 0;
}

