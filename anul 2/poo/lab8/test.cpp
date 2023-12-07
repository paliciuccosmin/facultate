#include <iostream>
#include "sql/sqlite3.h"

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("sample.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }
}