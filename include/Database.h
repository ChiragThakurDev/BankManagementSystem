#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite3.h"
#include "Account.h"

class Database
{
private:
    sqlite3 *db;
    std::string dbName;

public:
    Database(const std::string &dbName);
    ~Database();

    bool connect();
    void disconnect();

    bool executeQuery(const std::string &query);

    bool addAccount(const Account &account);
};

#endif