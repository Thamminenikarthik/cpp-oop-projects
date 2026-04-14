#include "BankSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

void BankSystem::createAccount() {
    int id, pin;
    string name;
    double bal;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Balance: ";
    cin >> bal;

    cout << "Set PIN: ";
    cin >> pin;

    accounts.push_back(Account(id, name, bal, pin));
    cout << "Account created successfully\n";
}

void BankSystem::deleteAccount() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccNo() == id) {
            accounts.erase(accounts.begin() + i);
            cout << "Deleted\n";
            return;
        }
    }
    cout << "Not found\n";
}

Account* BankSystem::findAccount(int id) {
    for (auto &acc : accounts)
        if (acc.getAccNo() == id)
            return &acc;
    return nullptr;
}

void BankSystem::deposit() {
    int id, pin;
    double amt;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter PIN: ";
    cin >> pin;

    cout << "Enter amount: ";
    cin >> amt;

    Account* acc = findAccount(id);

    if (acc && acc->verifyPin(pin)) {
        acc->deposit(amt);
        cout << "Deposit successful\n";
    } else {
        cout << "Invalid ID or PIN\n";
    }
}

void BankSystem::withdraw() {
    int id, pin;
    double amt;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter PIN: ";
    cin >> pin;

    cout << "Enter amount: ";
    cin >> amt;

    Account* acc = findAccount(id);

    if (acc && acc->verifyPin(pin)) {
        acc->withdraw(amt);
    } else {
        cout << "Invalid ID or PIN\n";
    }
}

void BankSystem::showBalance() {
    int id, pin;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter PIN: ";
    cin >> pin;

    Account* acc = findAccount(id);

    if (acc && acc->verifyPin(pin)) {
        acc->display();
    } else {
        cout << "Invalid ID or PIN\n";
    }
}

void BankSystem::saveToFile() {
    ofstream file("bank.txt");

    for (auto &acc : accounts)
        file << acc.serialize() << endl;

    file.close();
}

void BankSystem::loadFromFile() {
    ifstream file("bank.txt");
    string line;

    while (getline(file, line)) {
        Account acc;
        acc.deserialize(line);
        accounts.push_back(acc);
    }

    file.close();
}