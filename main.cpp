//Include standard library
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
//Include our library
#include "order.h"
#include "game.h"
#include "node.h"
#include "queue.h"
#include "tutorial.h"
#include "file.h"

using namespace std;

//Declare function
void endGame();

int main(){

    /*
    Random new seed everytime
    Declare LinkedList, queue, and order classes
    Declare General variables
    Skip tutorial option by use function doYesNo() from "game.h" and tutorial() from "tutorial.h"
    Game will play for 7 days, then we use while loop
    We random a b c d with diffrent seed everytime make the output diffrent
    Call function enqueue() from "queue.h" to random the menu
    Call function do_order() from "queue.h" to let player makes orders to serve.
    Before the end of the day(end of while loop) we call function increaseday() and increasemoney() from "increase_file.h" to write data on filename.txt
    Then sorting by money on filename.txt using sort_by_money() from "linkedlist_person.h"
    Then update the file by write_list_to_file() function from "file.h"
    Call function endGame() to display player result after 7 days
    Lastly call function print_current_player() and print_scoreboard() from "file.h" to display the leader board
    */
    
    srand(static_cast<unsigned int>(time(0)));
    
    LinkedList list;
    string current_name;
    system("clear");
    prologue();
    check_and_write_person(list, current_name);

    queue q;
    order bowl;
    int day=1,time=8;
    int i;
    int a,b,c,d;

    cout << "\nDo you want to skip the tutorial?" <<endl;
    if(doYesNo()==2) tutorial();
    system("clear");
    
    while(day<=7){
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
        q.do_order();
        pressEnterToContinue();
        
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
    cout << "7 days completed \n" << endl;
    cout << "|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|" << endl;
    cout << "|       "<<"You've donated $" <<setw(7)<< money << "       |" << endl;
    cout << "|   providing food for " <<setw(4)<< (int)money/25 << " people    |" << endl;
    cout << "|＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿|" << endl;
    cout << "           \\ (• ᴗ •) /" << endl;
    cout << "            \\       /" << endl;
    sleep(1);
    pressEnterToContinue();
}