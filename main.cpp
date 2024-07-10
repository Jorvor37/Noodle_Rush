#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "order.h"
#include "game.h"
#include "node.h"
#include "LL.h"
#include "queue.h"
#include "tutorial.h"
#include "file.h"
#include "increase_file.h"
#include "prologue.h"

using namespace std;


int main(){
    LinkedList list;
    string current_name;
    check_and_write_person(list, current_name);

    prologue();
    //tutorial();
    //Init game engine
    //Game game;

    queue q;
    order bowl;
    int day=1,time=7;
    int i;
    int a,b,c,d;

    tutorial();

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
        increaseday(list, current_name);
        time--;
        increasemoney(list, current_name, money);
        list.sort_by_money();
        write_list_to_file(list, "filename.txt");
    }
    return 0;
    
    system("clear");
    print_current_player(list, current_name);
    print_scoreboard(list, "filename.txt");
}
