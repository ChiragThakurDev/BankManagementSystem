#include <iostream>
#include "BankManager.h"
#include "Account.h"

BankManager::BankManager()

    : database("database/bank.db")
{

    database.connect();

    std::string createTable =
        R"(
        CREATE TABLE IF NOT EXISTS accounts(
            account_number INTEGER PRIMARY KEY,
            first_name TEXT NOT NULL,
            last_name TEXT NOT NULL,
            pin TEXT NOT NULL,
            balance REAL NOT NULL
        );
    )";

    database.executeQuery(createTable);
}

void BankManager::createAccount()
{
    Account account;
    account.input();

    if (database.addAccount(account))
    {
        std::cout << "\nAccount Created Successfully!\n";
    }
    else
    {
        std::cout << "\n Failed to Create Account!\n";
    }
}