#include<iostream>
//#include "LL.h"
#include "order.h"
using namespace std;
#include<unistd.h>

int tutorial()
{
    order test;
    order bowl;
    system("clear");
    cout<<"\t\t\tTUTORIAL \n\n";
    sleep(1);
    cout<<"\t\t   7 days of selling. \n\n";
    sleep(1);
    cout<<"As the day past by , the harder it gets. -> Less time you will get. \n\n";
    sleep(2);
    cout<<"The menu will be random each round.\n";
    sleep(1);

    test.order(1,2,2,2);
    bowl.select_noodle(1);
    bowl.select_meat(2);
    bowl.select_soup(2);
    bowl.select_veg(2);
    
    system("clear");
    cout<<"\t\t\t   Let's get started! \n";
    sleep(2);
    system("clear");

    
    return 0;
}

