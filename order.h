#include <iostream>
#include <cstdlib>
//#include "stdlib.h"
#ifndef order_h
#define order_h

using namespace std;

class order
{
    private:
        string name;
        float price;
        int noodle; //1. rice n (เส้นเล็ก) 2. wide rice n (เส้นใหญ่) 3. egg n (บะหมี่) 
        int meat; //1. pork 2. beef 3. seafood
        int soup; //1. dried 2. clear 3. tom yum 4. nam tok
        int veg; //1. yes 2.no
    public:
        order(){};
        order(int,int,int,int);
        ~order();
        void print();
        bool select_noodle(int);
        bool select_meat(int);
        bool select_soup(int);
        bool select_veg(int);
        float cashier();
        string get_name();
};

string order::get_name()
{
    return name;
}

order::order(int choice_n, int choice_m, int choice_s, int choice_v)
{
    //set order
    noodle = choice_n;
    meat = choice_m;
    soup = choice_s;
    veg = choice_v;

    //set name
    string n, m, s, v;
    switch(choice_n)
    {
        case 1: n="Rice Noodles"; break;
        case 2: n= "Wide Rice Noodles"; break;
        case 3: n= "Egg Noodles"; break;
    }
    switch(choice_m)
    {
        case 1: m="Pork"; price=40; break;
        case 2: m= "Beef"; price=50; break;
        case 3: m= "Seafood"; price=60; break;
    }
    switch(choice_s)
    {
        case 1: s="Dried "; break;
        case 2: s= "Clear"; break;
        case 3: s= "Tom Yum"; break;
        case 4: s= "Nam Tok"; break;
    }
    switch(choice_v)
    {
        case 1: v=" & Veggies"; break;
        case 2: v= " & No Veggies"; break;
    }
    
    if (soup==1) name = s + n + " with " + m + v;
    else name = n + " in " + s + " Soup with " + m + v;
    cout<<"\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t  "<<name<<endl;
    cout<<"\t\t\t___________________________________________________________"<<endl;
}

order::~order()
{
    //cout<<name<<" is ready to serve!"<<endl;
}

void order::print()
{
    cout<<name<<" "<<endl;
}

bool order::select_noodle(int noodle)
{
    int x;
    do{
        system("clear"); 
        cout<<"Select Noodle's Type?"<<endl;
        cout<<" 1. Rice Noodle"<<endl<<" 2. Wide Rice Noodle"<<endl<<" 3. Egg Noodle"<<endl;
        cin>>x;
    } while (x<1 || x>3);

    if (x!=noodle) 
    { 
        cout<<"You chose the wrong one! -5"<<endl; 
        price -=5;
        return false;
    }
    else return true;
}

bool order::select_meat(int meat)
{
    int x;
    do
    {
        system("clear"); 
        cout<<"Select Meat's Type?"<<endl;
        cout<<" 1. Pork"<<endl<<" 2. Beef"<<endl<<" 3. Seafood"<<endl;
        cin>>x;
    } while (x<1 || x>3);

    if (x!=meat) 
    { 
        cout<<"You chose the wrong one! -5"<<endl; 
        price -=5;
        return false;
    }
    else return true;
}

bool order::select_soup(int soup)
{
    int x;
    do
    {
        system("clear"); 
        cout<<"Select Soup's Type?"<<endl;
        cout<<" 1. Dried Noodle"<<endl<<" 2. Clear Soup"<<endl<<" 3. Tom Yum Soup"<<endl<<" 4. Nam Tok Soup"<<endl;
        cin>>x;
    } while (x<1 || x>4);

    if (x!=soup) 
    { 
        cout<<"You chose the wrong one! -5"<<endl; 
        price -=5;
        return false;
    }
    else return true;
}

bool order::select_veg(int veg)
{
    int x;
    do 
    {
        system("clear"); 
        cout<<"With Veggies?"<<endl;
        cout<<" 1. Yes"<<endl<<" 2. No"<<endl;
        cin>>x;
    } while (x<1 || x>2);

    if (x!=veg) 
    { 
        cout<<"You chose the wrong one! -5"<<endl; 
        price -=5;
        return false;
    }
    else return true;
}



float order::cashier()
{
    cout<<price;
    return price;
}

#endif