#include <iostream>
#include"sqlite/sqlite3.h"
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<cstring>

using namespace std;

class Trip {
public:
    std::string date;
    std::string destination;
};

class User {
public:
    std::string username;
    std::string email;
    std::string password;
};

class Operator {
private:
    sqlite3* db;

public:
    Operator() {
        // Open or create the SQLite database
        if (sqlite3_open("travel_app.db", &db) != SQLITE_OK) {
            throw std::runtime_error("Cannot open database.");
        }

        // Create tables if they don't exist
        const char* createTripsTableQuery = "CREATE TABLE IF NOT EXISTS trips (date TEXT, destination TEXT);";
        const char* createUsersTableQuery = "CREATE TABLE IF NOT EXISTS users (username TEXT, email TEXT, password TEXT);";

        if (sqlite3_exec(db, createTripsTableQuery, 0, 0, 0) != SQLITE_OK ||
            sqlite3_exec(db, createUsersTableQuery, 0, 0, 0) != SQLITE_OK) {
            throw std::runtime_error("Error creating tables.");
        }
    }

    ~Operator() {
        // Close the SQLite database
        sqlite3_close(db);
    }

    void login(const std::string& username, const std::string& password) {
        // Implement login using SQLite
        // Throw an exception in case of failure
    }

    bool checkDate(string d)
    {

        std::time_t currentTime = std::time(nullptr);
        std::tm* currentLocalTime = std::localtime(&currentTime);
        char currentDateString[11];
        std::strftime(currentDateString, sizeof(currentDateString), "%Y-%m-%d", currentLocalTime);
        int result = d.compare(currentDateString);
        if (result < 0)
            return true;
        else
            return false;
    }
    bool checkSpell(string s)
    {
        if (s.contains("!@#%^&*()_+-={}[];':"))

            return true;
    }
    void addTrip(const Trip& trip) {
        // Implement adding a trip using SQLite
        // Throw an exception in case of failure
    }

    // Additional methods for deleting trips, etc.
};

class UserManager {
private:
    sqlite3* db;

public:
    UserManager() {
        // Open or create the SQLite database
        if (sqlite3_open("travel_app.db", &db) != SQLITE_OK) {
            throw std::runtime_error("Cannot open database.");
        }
    }

    ~UserManager() {
        // Close the SQLite database
        sqlite3_close(db);
    }

    void createUser(const std::string& username, const std::string& email, const std::string& password) {
        // Implement user creation using SQLite
        // Throw an exception in case of failure
    }

    User authenticate(const std::string& username, const std::string& password) {
        // Implement user authentication using SQLite
        // Throw an exception in case of failure
        // Return the authenticated user
    }
};

int main() {
    try {
        Operator operatorInstance;
        UserManager userManager;

        operatorInstance.login("operator", "password");
        operatorInstance.addTrip(Trip{ "2023-12-15", "Destination1" });

        userManager.createUser("user1", "user1@example.com", "strongpassword");
        User authenticatedUser = userManager.authenticate("user1", "strongpassword");

        // Rest of the application logic
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
