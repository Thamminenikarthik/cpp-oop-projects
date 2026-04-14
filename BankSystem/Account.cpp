#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(int no, string n, double b, int p) {
    accNo = no;
    name = n;
    balance = b;
    pin = p;
}

int Account::getAccNo() {
    return accNo;
}

bool Account::verifyPin(int enteredPin) {
    return pin == enteredPin;
}

void Account::deposit(double amt) {
    balance += amt;
}

void Account::withdraw(double amt) {
    if (amt <= balance)
        balance -= amt;
    else
        cout << "Insufficient balance\n";
}

void Account::display() {
    cout << "AccNo: " << accNo
         << " Name: " << name
         << " Balance: " << balance << endl;
}

string Account::serialize() {
    return to_string(accNo) + " " + name + " " +
           to_string(balance) + " " + to_string(pin);
}

void Account::deserialize(string data) {
    string temp;
    int i = 0;

    // accNo
    while (data[i] != ' ') temp += data[i++];
    accNo = stoi(temp);

    // name
    temp = ""; i++;
    while (data[i] != ' ') temp += data[i++];
    name = temp;

    // balance
    temp = ""; i++;
    while (data[i] != ' ') temp += data[i++];
    balance = stod(temp);

    // pin
    temp = ""; i++;
    while (i < data.size()) temp += data[i++];
    pin = stoi(temp);
}