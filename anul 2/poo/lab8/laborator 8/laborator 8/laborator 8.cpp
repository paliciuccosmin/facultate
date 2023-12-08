#include <iostream>
#include"sqlite/sqlite3.h"
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<cstring>

using namespace std;

class User {
private:
    sqlite3* db;
    std::string username;
    std::string email;
    std::string password;

public:
    User(const char* dbName) : db(nullptr) {
        if (openDatabase(db, dbName) == SQLITE_OK) {
            createTable();
        }
    }

    ~User() {
        closeDatabase();
    }

    void createUser(const std::string& u, const std::string& e, const std::string& p) {
        username = u;
        email = e;
        password = p;

        char insertQuery[200];
        snprintf(insertQuery, sizeof(insertQuery), "INSERT INTO users (username, email, password) VALUES ('%s', '%s', '%s');", username.c_str(), email.c_str(), password.c_str());
        executeQuery(insertQuery);
    }

private:
    int openDatabase(sqlite3*& db, const char* dbName) {
        int rc = sqlite3_open(dbName, &db);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
        }
        return rc;
    }

    int executeQuery(const char* query) {
        char* errMsg;
        int rc = sqlite3_exec(db, query, 0, 0, &errMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", errMsg);
            sqlite3_free(errMsg);
        }
        return rc;
    }

    void createTable() {
        const char* createTableQuery = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, email TEXT, password TEXT);";
        executeQuery(createTableQuery);
    }

    void closeDatabase() {
        if (db) {
            sqlite3_close(db);
            db = nullptr;
        }
    }
};

int main(){


}
