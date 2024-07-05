#include <iostream>
#include <cstdlib>
#include "order.h"
#include "game.h"
#include "node.h"
#include "LL.h"



using namespace std;


int main(){
    //Init game engine
    //Game game;
    LL line;
    int day=0,n=10;
    int i;
    int a,b,c,d;

    
   while(day<7){
    for(i=0; i<=5+2*day; i++)
    {   
        a = rand()%3+1;
        b = rand()%3+1;
        c = rand()%4+1;
        d = rand()%2+1;
        line.insert(order(a,b,c,d));
        timer(2);
    }
    line.print_order();
    day++;
    n--;
   }
    
    return 0;
}