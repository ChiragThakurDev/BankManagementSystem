#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "Database.h"

class BankManager
{
private:
    Database database;

public:
    BankManager();

    void createAccount();
    void displayAccounts();
    void searchAccount();
};

#endif