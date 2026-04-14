#include "BankSystem.h"
#include <iostream>
using namespace std;

int main() {
    BankSystem bank;
    bank.loadFromFile();

    int choice;

    do {
        cout << "\n1.Create 2.Delete 3.Deposit 4.Withdraw 5.Balance 6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.deleteAccount(); break;
            case 3: bank.deposit(); break;
            case 4: bank.withdraw(); break;
            case 5: bank.showBalance(); break;
            case 6: bank.saveToFile(); break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}