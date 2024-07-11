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
        1.  Random new seed everytime
        2.  Declare LinkedList, queue, and order classes
        3.  Declare General variables
        4.  Skip tutorial option by use function doYesNo() from "game.h" and tutorial() from "tutorial.h"
        5.  Game will play for 7 days, then we use while loop
        6.  We random a b c d with diffrent seed everytime make the output diffrent
        7.  Call function enqueue() from "queue.h" to random the menu
        8.  Call function do_order() from "queue.h" to let player makes orders to serve.
        9.  Before the end of the day(end of while loop) we call function increaseday() and increasemoney() from "increase_file.h" to write data on filename.txt
        10. Then sorting by money on filename.txt using sort_by_money() from "linkedlist_person.h"
        11. Then update the file by write_list_to_file() function from "file.h"
        12. Call function endGame() to display player result after 7 days
        13. Lastly call function print_current_player() and print_scoreboard() from "file.h" to display the leader board
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