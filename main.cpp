//Include standard libary
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
//Include our libary
#include "order.h"
#include "game.h"
#include "node.h"
#include "LL.h"
#include "increase_file.h"
#include "linkedlist_person.h"
#include "order.h"
#include "queue.h"
#include "tutorial.h"
#include "node.h"
#include "person.h"

using namespace std;

//Declare function
void endGame();

int main(){
    /*
        1. Random new seed everytime
        2. Declare LinkedList, queue, and order classes
        3. Declare General variables
    */
    srand(static_cast<unsigned int>(time(0)));
    
    LinkedList list;
    string current_name;
    system("clear");
    check_and_write_person(list, current_name);

    queue q;
    order bowl;
    int day=1,time=8;
    int i,a,b,c,d;

    cout << "\nDo you want to skip the tutorial?" <<endl;
    if(doYesNo()==2) tutorial();
    system("clear");
    
    while(day<7){
        cout<<"   /)__/)"<<endl;
        cout<<"  (๑^᎑^๑)っ"<<endl;
        cout<<"|￣∪￣ ￣ |"<<endl;
        cout<<"|  Day "<<day<<"  |"<<endl;
        cout<<"|_________|"<<endl;


        for(i=1; i<=2+day; i++)
        {   
            a = rand()%3+1;
            b = rand()%3+1;
            c = rand()%4+1;
            d = rand()%2+1;
            q.enqueue(order(a,b,c,d,time));
        }
        //q.print_order();
        q.do_order();
        
        day++;
        increaseday(list, current_name);
        time--;
        increasemoney(list, current_name, money);
        list.sort_by_money();
        write_list_to_file(list, "filename.txt");
    }
    endGame();
    
    system("clear");
    print_current_player(list, current_name);
    print_scoreboard(list, "filename.txt");
}

void endGame()
{
    system("clear");
    cout << "|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|" << endl;
    cout << "|       "<<"You've donate $" <<setw(7)<< money << "       |" << endl;
    cout << "|  providing food for " <<setw(4)<< (int)money/25 << " people    |" << endl;
    cout << "|＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿|" << endl;
    cout << "           \\ (• ᴗ •) /" << endl;
    cout << "            \\       /" << endl;
    sleep(1);
    pressEnterToContinue();
}