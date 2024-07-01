#include <iostream>
#include <cstdlib>
#include "test.h"
//#include "node.h"
//#include "stack.h"

using namespace std;

int main(){
    //Init game engine
    //Game game;
    int day=0;
    int i;
    int a,b,c,d;
    

    for(i=0; i<=5+2*day; i++, day++)
    {   
        a = rand()%3+1;
        b = rand()%3+1;
        c = rand()%4+1;
        d = rand()%2+1;
        order bowl(a,b,c,d);
    }

    return 0;
}