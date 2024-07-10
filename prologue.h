#include<iostream>
#include<iomanip>
#include<unistd.h>
using namespace std;

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
