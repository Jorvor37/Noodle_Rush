#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class MenuItem 
{
    public:
        string name;
        double price;

        // Constructor with initialization list
        MenuItem(string itemName, double itemPrice);
};

class CashierSystem 
{
    private:
        vector<MenuItem*> menu;

    public:
        //constructors and deconstructors
        CashierSystem();
        ~CashierSystem();

        //Functions
        void addMenuItem(string name, double price);
        void checkout();
        void displayMenu();
};

// MenuItem Class
// Constructor with initialization list
MenuItem::MenuItem(string itemName, double itemPrice) 
    {
        name = itemName;
        price = itemPrice;
    }


// CashierSystem Class
// Constructor with initialization list
CashierSystem::CashierSystem()
    {
        srand(static_cast<unsigned>(time(0))); // Seed for random number generation
    }

CashierSystem::~CashierSystem() 
    {  
        for (int i=0; i<menu.size();++i) {
            delete menu[i];
        }
    }

// Functions
void CashierSystem::addMenuItem(string name, double price) 
    {
        /*
            make new menu using unique pointer
        */
        MenuItem* newItem = new MenuItem(name, price);
        menu.push_back(newItem);  
    }

void CashierSystem::checkout() 
    {
        if (menu.empty()) {
            cout << "No items in the menu." << endl;
            return;
        }

        /*
            1. random the menu that customer will choose
            2. write variables for future conditions
            3. display customer choice using pointers
            4. check on conditions
            5. update money database (don't have the resturant class yet)
        */

        int selectedItemIndex = rand() % menu.size();
        MenuItem* selectedItem = menu[selectedItemIndex];
        
        double payment = selectedItem->price + ((rand() % 100 + 1)); // Random payment larger than menu price
        double correctChange = payment - selectedItem->price;
        double playerChange;
        double finalChange;

        cout << "Selected Menu Item: " << selectedItem->name << endl;
        cout << "Menu Price: $" << selectedItem->price << endl;
        cout << "Customer pays: $" << payment << endl;
        cout << "Calculate the change to give back to the customer: $";
        cin >> playerChange;

        if (playerChange == correctChange) {
            double tip = 0.3 * selectedItem->price;
            cout << "Correct! You give the right change and earned a 30'%' tip: $" << tip << endl;
            finalChange = selectedItem->price + tip;
            //update resturant balance using finalChange
        } else if (playerChange < correctChange) {
            cout << "Wrong! You gave less money back. The customer complains and requests more payment." << endl;
            cout << "You should have given: $" << correctChange << " but you gave: $" << playerChange << endl;
            finalChange = selectedItem->price-(correctChange-playerChange);
            //update resturant balance using finalChange
        } else {
            cout << "Wrong! You gave too much money back. The customer happily takes the extra money." << endl;
            cout << "You should have given: $" << correctChange << " but you gave: $" << playerChange << endl;
            finalChange = payment-playerChange;
            //update resturant balance using finalChange
        }

        cout << "Final Change -$" << finalChange <<endl;
    }

void CashierSystem::displayMenu()
    {
        /*
            1. use menu.empty from <vector> libary to check array
            2. if have an item continue to display
        */
        if (menu.empty()) {
            cout << "No items in the menu." << endl;
            return;
        }

        cout << "Menu Items:" << endl;
        for (int i=0; i<menu.size();i++) {
            MenuItem* currentItem = menu[i];
            cout << currentItem->name << " - $" << currentItem->price << endl;
        }
    }