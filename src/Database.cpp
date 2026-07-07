#include <iostream>
#include "Database.h"
#include <string>

Database::Database(const std::string &dbName)
{
    this->dbName = dbName;
    db = nullptr;
}

Database::~Database()
{
    disconnect();
}

bool Database::connect()
{
    int result = sqlite3_open(dbName.c_str(), &db);

    if (result != SQLITE_OK)
    {
        std::cout << "Database connection failed.\n";
        std::cout << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::cout << "Connection Successfully!\n";

    return true;
}

void Database::disconnect()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;

        std::cout << "Database Closed. \n ";
    }
}

bool Database::executeQuery(const std::string &query)
{
    char *errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        query.c_str(),
        nullptr,
        nullptr,
        &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cout << "SQL ERROR: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}
bool Database::addAccount(const Account &account)
{
    sqlite3_stmt *stmt = nullptr;
    std::string sql =
        "INSERT INTO accounts(account_number, first_name, last_name, pin, balance) "
        "VALUES (?, ?, ?, ?, ?);";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare statement.\n";
        std::cout << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    sqlite3_bind_int(stmt, 1, account.getAccountNumber());

    sqlite3_bind_text(
        stmt,
        2,
        account.getFirstName().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_text(
        stmt,
        3,
        account.getLastName().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_text(
        stmt,
        4,
        account.getPin().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_double(stmt, 5, account.getBalance());

    result = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (result != SQLITE_DONE)
    {
        std::cout << "Failed to insert account.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::cout << "Account created successfully!\n";

    return true;
}

void Database::displayAccounts()
{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "SELECT account_number, first_name, last_name, balance FROM accounts;";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare SELECT statement.\n";
        std::cout << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::cout << "\n==============================================\n";
    std::cout << "           ALL BANK ACCOUNTS\n";
    std::cout << "==============================================\n";

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int accountNumber = sqlite3_column_int(stmt, 0);

        std::string firstName =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        std::string lastName =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

        double balance =
            sqlite3_column_double(stmt, 3);

        std::cout << "Account Number : " << accountNumber << std::endl;
        std::cout << "First Name     : " << firstName << std::endl;
        std::cout << "Last Name      : " << lastName << std::endl;
        std::cout << "Balance        : " << balance << std::endl;
        std::cout << "----------------------------------------------\n";
    }

    sqlite3_finalize(stmt);
}

bool Database::searchAccount(int accountNumber)
{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "SELECT account_number, first_name, last_name, balance "
        "FROM accounts WHERE account_number =?;";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare search statement.\n";
        std::cout << sqlite3_errmsg(db) << std::endl;

        return false;
    }

    sqlite3_bind_int(stmt, 1, accountNumber);
    result = sqlite3_step(stmt);

    if (result == SQLITE_ROW)
    {
        int accNo = sqlite3_column_int(stmt, 0);

        std::string firstName =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        std::string lastName =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

        double balance =
            sqlite3_column_double(stmt, 3);

        std::cout << "\n=====================================\n";
        std::cout << "         ACCOUNT FOUND\n";
        std::cout << "=====================================\n";
        std::cout << "Account Number : " << accNo << std::endl;
        std::cout << "First Name     : " << firstName << std::endl;
        std::cout << "Last Name      : " << lastName << std::endl;
        std::cout << "Balance        : " << balance << std::endl;
        std::cout << "=====================================\n";

        sqlite3_finalize(stmt);
        return true;
    }
    sqlite3_finalize(stmt);
    return false;
}
