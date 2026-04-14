#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "Account.h"
#include <vector>
using namespace std;

class BankSystem {
private:
    vector<Account> accounts;

public:
    void createAccount();
    void deleteAccount();
    Account* findAccount(int id);

    void deposit();
    void withdraw();
    void showBalance();

    void saveToFile();
    void loadFromFile();
};

#endif