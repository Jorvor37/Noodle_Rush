#include <iostream>
#include <cstdlib>
#include "order.h"
#include "node.h"
#include "LL.h"

using namespace std;

int main(){
    //Init game engine
    //Game game;
    LL line;
    int day=0;
    int i;
    int a,b,c,d;
    

    for(i=0; i<=5+2*day; i++)
    {   
        a = rand()%3+1;
        b = rand()%3+1;
        c = rand()%4+1;
        d = rand()%2+1;
        line.insert(order(a,b,c,d));
    }


    return 0;
}