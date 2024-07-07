#include "Cal.h"

using namespace std;

int main() {
    CashierSystem system;

    system.addMenuItem("Burger", 80);
    system.addMenuItem("Fries", 55);
    system.addMenuItem("Soda", 30);

    char continueCheckout = 'y';

    while (continueCheckout == 'y' || continueCheckout == 'Y') {
        system.displayMenu();
        system.checkout();

        cout << "Would you like to process another transaction? (y/n): ";
        cin >> continueCheckout;
    }

    return 0;
}
