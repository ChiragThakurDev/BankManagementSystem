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