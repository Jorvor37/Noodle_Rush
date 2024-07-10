#include <iostream>
#include <cstdlib>
#include <stdio.h> 
#include <stdlib.h>


#include "stdlib.h"
#include "game.h"
#ifndef order_h
#define order_h

using namespace std;

float money=0, tutorialMoney=0;

class order
{
    private:
        string name;
        float price;
        int noodle; //1. rice n (เส้นเล็ก) 2. wide rice n (เส้นใหญ่) 3. egg n (บะหมี่) 
        int meat; //1. pork 2. beef 3. seafood
        int soup; //1. dried 2. clear 3. tom yum 4. nam tok
        int veg; //1. yes 2.no
        int time;
    public:
        order(){};
        order(int,int,int,int, int);
        ~order();
        void print();
        bool select_noodle();
        bool select_meat();
        bool select_soup();
        bool select_veg();
        void make();
        void cashier();
        void tutorialCashier();
        void endGame();
        string get_name();
};

string order::get_name()
{
    return name;
}

order::order(int choice_n, int choice_m, int choice_s, int choice_v, int t)
{
    //set order
    noodle = choice_n;
    meat = choice_m;
    soup = choice_s;
    veg = choice_v;
    time = t;

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
}

order::~order()
{
    //cout<<name<<" is ready to serve!"<<endl;
}

void order::print()
{
    cout<<name<<endl;
}

bool order::select_noodle()
{
    int x;
    do{
        //system("clear"); 
        fflush(stdin);
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

bool order::select_meat()
{
    int x;
    do
    {
        //system("clear");
        fflush(stdin);
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

bool order::select_soup()
{
    int x;
    do
    {
        //system("clear"); 
        fflush(stdin);
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

bool order::select_veg()
{
    int x;
    do 
    {
        //system("clear"); 
        fflush(stdin);
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

void order::make(){
  bool noodle, meat, soup, veg;
  pressEnterToContinue();
  cout<<"\t\t\t___________________________________________________________"<<endl;
  cout<<"\n\t\t\t  "<<get_name()<<endl;
  cout<<"\t\t\t___________________________________________________________"<<endl;
  if (time!=0) timer(time);
  noodle = select_noodle();
  meat = select_meat();
  soup = select_soup();
  veg = select_veg();
  pressEnterToContinue();
  cout<<name<<" is ready to serve!"<<endl<<endl;
  cashier();
  fflush(stdin);
  pressEnterToContinue();
}

void order::cashier()
{
        float payment = price + ((rand() % 100 + 1)); // Random payment larger than menu price
        float correctChange = payment - price;
        float playerChange;
        float finalChange;


        cout << "Menu Price: $" << price << endl;
        cout << "Customer pays: $" << payment << endl;
        cout << "Calculate the change to give back to the customer: $";
        cin >> playerChange;

        if (playerChange == correctChange) {
            float tip = 0.3 * price;
            cout << "Correct! You give the right change and earned a 30'%' tip: $" << tip << endl;
            finalChange = price + tip;
            money += finalChange;
        } 
        else if (playerChange < correctChange) {
            cout << "Wrong! You gave less money back. The customer complains and requests more payment." << endl;
            cout << "You should have given: $" << correctChange << " but you gave: $" << playerChange << endl;
            finalChange = price-(correctChange-playerChange);
            money += finalChange;
        } 
        else {
            cout << "Wrong! You gave too much money back. The customer happily takes the extra money." << endl;
            cout << "You should have given: $" << correctChange << " but you gave: $" << playerChange << endl;
            finalChange = payment-playerChange;
            money += finalChange;
        }

        cout << "Final Income $" << finalChange <<endl;
        cout << "Total Cash $" << money << endl;
}

void order::tutorialCashier(){
    float payment = price + ((rand() % 100 + 1)); // Random payment larger than menu price
        float correctChange = payment - price;
        float playerChange;
        float finalChange;


        cout << "Menu Price: $" << price << endl;
        cout << "Customer pays: $" << payment << endl;
        cout << "Calculate the change to give back to the customer: $";
        cin >> playerChange;

        if (playerChange == correctChange) {
            float tip = 0.3 * price;
            cout << "Correct! You give the right change and earned a 30'%' tip: $" << tip << endl;
            finalChange = price + tip;
            tutorialMoney += finalChange;
        } 
        else if (playerChange < correctChange) {
            cout << "Wrong! You gave less money back. The customer complains and requests more payment." << endl;
            cout << "You should have given: $" << correctChange << " but you gave: $" << playerChange << endl;
            finalChange = price-(correctChange-playerChange);
            tutorialMoney += finalChange;
        } 
        else {
            cout << "Wrong! You gave too much money back. The customer happily takes the extra money." << endl;
            cout << "You should have given: $" << correctChange << " but you gave: $" << playerChange << endl;
            finalChange = payment-playerChange;
            tutorialMoney += finalChange;
        }

        cout << "Final Income $" << finalChange <<endl;
        cout << "Total Cash $" << tutorialMoney << endl;
}

void order::endGame()
{
    system("clear");
    cout <<"                 :#%@@@@@%=                 " <<endl;
    cout <<"              :#@@@@@@@@@@@@@-              " <<endl;
    cout <<"             *@@@@@@@@@@@@@@@@%.            " <<endl;
    cout <<"            +@@@@@@@@@@@@@@@@@@%            " <<endl;
    cout <<"            @@@@@@@@@@@@@@@@@@@@=           " <<endl;
    cout <<"           :@@@@@@@@@@@@@@@@@@@@#           " <<endl;
    cout <<"           .@@@@@@@@@@@@@@@@@@@@*           " <<endl;
    cout <<"            #@@@@@@@@@@@@@@@@@@@.           " <<endl;
    cout <<"            :@@@@@@@@@@@@@@@@@@+            " <<endl;
    cout <<"             .@@@@@@@@@@@@@@@@+             " <<endl;
    cout <<"               +@@@@@@@@@@@@%.              " <<endl;
    cout <<"                 :*@@@@@@#=.                " <<endl;
    cout <<"            .=#%@@@@@@@@@@@@@%+.            " <<endl;
    cout <<"         -#@@@@@@@@@@@@@@@@@@@@@@%+.        " <<endl;
    cout <<"      .*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:      " <<endl;
    cout <<"     *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.    " <<endl;
    cout <<"   :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+   " <<endl;
    cout <<"  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*  " <<endl;
    cout <<" .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+ " <<endl;
    cout <<":*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%." <<endl;
    cout <<"=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:" <<endl;
    cout <<" .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+=\n" <<endl;
    sleep(1);
    cout << "You've donate $" << money << endl;
    cout << "And save " << money/25 << " people" << endl;
    pressEnterToContinue();
}

#endif