#include <iostream>
#include "Database.h"

int main()
{
    Database database("database/bank.db");

    database.connect();
    return 0;
}