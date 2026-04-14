#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    int accNo;
    string name;
    double balance;
    int pin;

public:
    Account(int no = 0, string n = "", double b = 0, int p = 0);

    int getAccNo();
    bool verifyPin(int enteredPin);

    void deposit(double amt);
    void withdraw(double amt);
    void display();

    string serialize();
    void deserialize(string data);
};

#endif