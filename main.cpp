#include <iostream>
#include <cstdlib>
#include "order.h"
#include "game.h"
#include "node.h"
#include "LL.h"
#include "tutorial.h"

using namespace std;


int main(){

    tutorial();
    //Init game engine
    //Game game;

    LL line;
    order bowl;
    int day=1,n=7;
    int i;
    int a,b,c,d;

cout<<"/*   ____         _____                     _   _                 _ _       */
/*  / ___| __ _  |_   _|_ _  _____      __ | \ | | ___   ___   __| | | ___  */
/* | |  _ / _` |   | |/ _` |/ _ \ \ /\ / / |  \| |/ _ \ / _ \ / _` | |/ _ \ */
/* | |_| | (_| |   | | (_| |  __/\ V  V /  | |\  | (_) | (_) | (_| | |  __/ */
/*  \____|\__,_|   |_|\__,_|\___| \_/\_/   |_| \_|\___/ \___/ \__,_|_|\___| */";

    
   while(day<7){
    for(i=0; i<=2+day; i++)
    {   
        a = rand()%3+1;
        b = rand()%3+1;
        c = rand()%4+1;
        d = rand()%2+1;
        line.insert(order(a,b,c,d));
        timer(n);
        /*
        bowl.select_noodle(a);
        bowl.select_meat(b);
        bowl.select_soup(c);
        bowl.select_veg(d); 
        */ 
        
    }
    line.print_order();
    day++;
    n--;
   }
    
    return 0;
}