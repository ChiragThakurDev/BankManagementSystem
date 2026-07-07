#include <iostream>
#include "BankManager.h"

using namespace std;

int main()
{
    BankManager manager;
    int choice;
    do
    {
        cout << "\n===============================\n";
        cout << "    BANK MANAGEMENT SYSTEM\n";
        cout << "===============================\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Exit\n";

        cout << "===============================\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.createAccount();
            break;

        case 2:
            manager.displayAccounts();
            break;

        case 3:
            manager.searchAccount();
            break;

        case 4:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
