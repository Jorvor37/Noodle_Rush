#include <iostream>
#include <cstdlib>
#include "order.h"
#include "game.h"
#include "node.h"
#include "LL.h"
#include "queue.h"
#include "tutorial.h"

using namespace std;


int main(){

    //tutorial();
    //Init game engine
    //Game game;

    queue q;
    order bowl;
    int day=1,time=7;
    int i;
    int a,b,c,d;

/*
cout<<"/*   ____         _____                     _   _                 _ _       */
/*  / ___| __ _  |_   _|_ _  _____      __ | \ | | ___   ___   __| | | ___  */
/* | |  _ / _` |   | |/ _` |/ _ \ \ /\ / / |  \| |/ _ \ / _ \ / _` | |/ _ \ */
/* | |_| | (_| |   | | (_| |  __/\ V  V /  | |\  | (_) | (_) | (_| | |  __/ */
// /*  \____|\__,_|   |_|\__,_|\___| \_/\_/   |_| \_|\___/ \___/ \__,_|_|\___| */";

    
    while(day<7){
        cout<<"Day "<<day<<endl;
        for(i=0; i<=2+day; i++)
        {   
            a = rand()%3+1;
            b = rand()%3+1;
            c = rand()%4+1;
            d = rand()%2+1;
            q.enqueue(order(a,b,c,d,0));
        }
        q.print_order();
        q.do_order();
        
        day++;
        time--;
    }
    return 0;
}