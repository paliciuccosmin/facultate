#include <iostream>
#include"sqlite/sqlite3.h"
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<cstring>
#include"Header.h"
using namespace std;


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


class Operator {
private:
    sqlite3* db;

public:
    Operator(const char* dbName) : db(nullptr) {
        if (openDatabase(db, dbName) == SQLITE_OK) {
            createTable();
        }
    }

    ~Operator() {
        closeDatabase();
    }

    void printAllTrips() {
        try {
            // Get all trips
            const char* selectQuery = "SELECT * FROM trips;";

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                std::cout << "All trips:" << std::endl;

                while (sqlite3_step(stmt) == SQLITE_ROW) {
                    int tripId = sqlite3_column_int(stmt, 0);
                    std::string destination = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                    std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

                    std::cout << "Trip ID: " << tripId << ", Destination: " << destination << ", Date: " << date << std::endl;
                }

                sqlite3_finalize(stmt);
            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void addTrip(const std::string& destination, const std::string& date) {
        try {
            if (!isValidCityName(destination)) {
                throw std::invalid_argument("Error: Invalid city name. Special characters are not allowed.");
            }
            if (!isValidDate(date)) {
                throw std::invalid_argument("Error: Invalid date format or date is in the past.");
            }
            char insertQuery[200];
            snprintf(insertQuery, sizeof(insertQuery), "INSERT INTO trips (destination, date) VALUES ('%s', '%s');",
                destination.c_str(), date.c_str());
            executeQuery(insertQuery);
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void deleteTrip(int tripId) {
        try {
            // Check if the trip exists
            char selectQuery[100];
            snprintf(selectQuery, sizeof(selectQuery), "SELECT * FROM trips WHERE id = %d;", tripId);

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                int result = sqlite3_step(stmt);
                sqlite3_finalize(stmt);

                if (result != SQLITE_ROW) {
                    throw std::invalid_argument("Error: Trip does not exist.");
                }
            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }

            // Delete the trip
            char deleteQuery[100];
            snprintf(deleteQuery, sizeof(deleteQuery), "DELETE FROM trips WHERE id = %d;", tripId);
            executeQuery(deleteQuery);
            std::cout << "Trip deleted successfully." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void modifyTrip(const std::string& oldDestination, const std::string& newDestination, const std::string& newDate) {
        try {

            // Check if the new city name is valid
            if (!isValidCityName(newDestination)) {
                throw std::invalid_argument("Error: Invalid city name. Special characters are not allowed.");
            }
            if (!isValidDate(newDate)) {
                throw std::invalid_argument("Error: Invalid date format or date is in the past.");
            }

            // Check if the trip with old destination exists
            char selectQuery[100];
            snprintf(selectQuery, sizeof(selectQuery), "SELECT * FROM trips WHERE destination = '%s';", oldDestination.c_str());

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                int result = sqlite3_step(stmt);
                sqlite3_finalize(stmt);

                if (result != SQLITE_ROW) {
                    throw std::invalid_argument("Error: Trip does not exist.");
                }
            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }

            // Modify the trip details
            char updateQuery[200];
            snprintf(updateQuery, sizeof(updateQuery), "UPDATE trips SET destination = '%s', date = '%s' WHERE destination = '%s';",
                newDestination.c_str(), newDate.c_str(), oldDestination.c_str());
            executeQuery(updateQuery);
            std::cout << "Trip modified successfully." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }



private:
    bool isValidDate(const std::string& date) {
        std::tm timeinfo = {};
        std::istringstream ss(date);
        ss >> std::get_time(&timeinfo, "%Y-%m-%d");

        if (ss.fail()) {
            return false; // Incorrect date format
        }

        std::time_t now = std::time(nullptr);
        std::time_t dateInSeconds = std::mktime(&timeinfo);

        return (dateInSeconds > now);
    }

    bool isValidCityName(const std::string& cityName) {
        for (char c : cityName) {
            if (!isalpha(c) && c != ' ' && c != '-') {
                return false;
            }
        }
        return true;
    }

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
        const char* createTableQuery = "CREATE TABLE IF NOT EXISTS trips (id INTEGER PRIMARY KEY, destination TEXT, date TEXT, duration TEXT);";
        executeQuery(createTableQuery);
    }

    void closeDatabase() {
        if (db) {
            sqlite3_close(db);
            db = nullptr;
        }
    }
};

class User {
private:
    sqlite3* db;
public:
    User(const char* dbName) : db(nullptr) {
        if (openDatabase(db, dbName) == SQLITE_OK) {
            createTable();
        }
    }

    ~User() {
        closeDatabase();
    }

    bool userExists(const std::string& u) {
        char selectQuery[100];
        snprintf(selectQuery, sizeof(selectQuery), "SELECT * FROM users WHERE username = '%s';", u.c_str());//verifica existenta username-ului in baza de date

        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            return false;
        }
        

        int result = sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        return result == SQLITE_ROW;
    }

    void createUser(const std::string& username, const std::string& email, const std::string& password) {
        try {
            // Check if the password is too weak
            if (isWeakPassword(password)) {
                throw std::invalid_argument("Error: Password is too weak. It should be at least 8 characters long and contain both letters and numbers.");
            }

            // Check if the email address is valid
            if (!isValidEmail(email)) {
                throw std::invalid_argument("Error: Invalid email address format.");
            }

            if (userExists(username)) {
                throw std::runtime_error("User already exists.");
            }
            vector<int> Password = encoder(password);
            string encodedPassword = vectorToString(Password);
            cout << encodedPassword << endl;
            char insertQuery[200];
            snprintf(insertQuery, sizeof(insertQuery), "INSERT INTO users (username, email, password) VALUES ('%s', '%s', '%s');", username.c_str(), email.c_str(), encodedPassword.c_str());
            executeQuery(insertQuery);
            std::cout << "User created successfully." << std::endl;

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    bool login(const std::string& username, const std::string& password) {
        try {
            if (!userExists(username)) {
                throw std::invalid_argument("User does not exist.");
            }
            vector<int> Password = encoder(password);
            string encodedPassword = vectorToString(Password);
            char selectQuery[200];
            snprintf(selectQuery, sizeof(selectQuery), "SELECT * FROM users WHERE username = '%s' AND password = '%s';", username.c_str(), encodedPassword.c_str());

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) != SQLITE_OK) {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }

            int result = sqlite3_step(stmt);
            sqlite3_finalize(stmt);

            if (result == SQLITE_ROW) {
                return true; // Login successful
            }
            else {
                throw std::invalid_argument("Invalid username or password.");
            }

        }
        catch (const std::exception& e) {
            std::cerr << "Login Error: " << e.what() << std::endl;
            return false; // Login failed
        }
    }
    void reserveTrip(const int tripId, const std::string& username) {
        try {
            // Check if the trip exists
            const char* selectQuery = "SELECT * FROM trips WHERE id = ?;";
            sqlite3_stmt* stmt;

            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, tripId);

                int result = sqlite3_step(stmt);
                sqlite3_finalize(stmt);

                if (result != SQLITE_ROW) {
                    throw std::invalid_argument("Error: Trip does not exist.");
                }
            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }

            // Reserve the trip for the user
            const char* insertQuery = "INSERT INTO user_reservations (user_id, trip_id) VALUES ((SELECT id FROM users WHERE username = ?), ?);";
            stmt = nullptr;

            if (sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
                sqlite3_bind_int(stmt, 2, tripId);

                executeRegistration(stmt);
                std::cout << "Trip reserved successfully." << std::endl;
            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void showTripsToDestination(const std::string& destination) {
        try {
            validateCityName(destination); // Check if the city name contains special characters

            // Get trips to the specified destination
            char selectQuery[100];
            snprintf(selectQuery, sizeof(selectQuery), "SELECT * FROM trips WHERE destination = '%s';", destination.c_str());

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                std::cout << "Trips to " << destination << ":" << std::endl;

                while (sqlite3_step(stmt) == SQLITE_ROW) {
                    int tripId = sqlite3_column_int(stmt, 0);
                    std::string tripDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                    std::cout << "Trip ID: " << tripId << ", Date: " << tripDate << std::endl;
                }

                sqlite3_finalize(stmt);

            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    void showUserReservations(const std::string& username) {
        try {
            // Get user reservations
            const char* selectQuery = "SELECT trips.destination, trips.date FROM user_reservations "
                "JOIN trips ON user_reservations.trip_id = trips.id "
                "JOIN users ON user_reservations.user_id = users.id "
                "WHERE users.username = ?;";

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr) == SQLITE_OK) {
                sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

                std::cout << "Your reservations:" << std::endl;

                while (sqlite3_step(stmt) == SQLITE_ROW) {
                    std::string tripDestination = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                    std::string tripDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                    std::cout << "Destination: " << tripDestination << ", Date: " << tripDate << std::endl;
                }

                sqlite3_finalize(stmt);

            }
            else {
                throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
            }

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
    bool isWeakPassword(const std::string& password) {
        return (password.length() < 8 || password.find_first_of("0123456789") == std::string::npos || password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == std::string::npos);
    }

    bool isValidEmail(const std::string& email) {
        size_t atPos = email.find('@');
        size_t dotPos = email.rfind('.');

        return (atPos != std::string::npos && dotPos != std::string::npos && atPos < dotPos);
    }
    void validateCityName(const std::string& cityName) {
        for (char c : cityName) {
            if (!isalpha(c) && c != ' ' && c != '-') {
                throw std::invalid_argument("Invalid city name: Special characters are not allowed.");
            }
        }
    }

    int openDatabase(sqlite3*& db, const char* dbName) {
        int rc = sqlite3_open(dbName, &db);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
        }
        return rc;
    }
    void executeRegistration(sqlite3_stmt* stmt) {
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(sqlite3_db_handle(stmt))));
        }
        sqlite3_finalize(stmt);
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
        createTableQuery = "CREATE TABLE IF NOT EXISTS user_reservations (id INTEGER PRIMARY KEY, user_id INTEGER,trip_id INTEGER,FOREIGN KEY(user_id) REFERENCES users(id),FOREIGN KEY(trip_id) REFERENCES trips(id)); ";
        executeQuery(createTableQuery);
    }

    void closeDatabase() {
        if (db) {
            sqlite3_close(db);
            db = nullptr;
        }
    }
};
void displayMenu() {
    std::cout << "-------------------------" << std::endl;
    std::cout << "1. Register a new user" << std::endl;
    std::cout << "2. Log in" << std::endl;
}
bool isAdmin(const std::string& username) {
    return (username == "admin");
}

void displayAdminMenu() {
    std::cout << "-------------------------" << std::endl;
    std::cout << "1. Add a trip" << std::endl;
    std::cout << "2. Delete a trip" << std::endl;
    std::cout << "3. Modify a trip" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void displayUserMenu() {
    std::cout << "-------------------------" << std::endl;
    std::cout << "1. Reserve a trip" << std::endl;
    std::cout << "2. Show trips to destination" << std::endl;
    std::cout << "3. Show user reservations" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "-------------------------" << std::endl;
}
int main() {
    primefiller();
    setkeys();
    const char* dbName = "database.db";
    User user(dbName);
    Operator op(dbName);
    std::string username, destination, date, newDestination, newDate;
    int choice;
    string d;
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
        case 1: {
            std::string email, password;
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            user.createUser(username, email, password);
            break;
        }
        case 2: {
            // Log in
            std::string password;
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            if (user.login(username, password)) {
                std::cout << "Login successful." << std::endl;

                // Check if the user is an admin
                if (isAdmin(username)) {
                    while (true) {
                        displayAdminMenu();
                        std::cout << "Enter your choice: ";
                        std::cin >> choice;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                        switch (choice) {
                        case 1:
                            std::cout << "Enter destination: ";
                            std::getline(std::cin, destination);
                            std::cout << "Enter date (YYYY-MM-DD): ";
                            std::getline(std::cin, date);
                            op.addTrip(destination, date);
                            std::cout << "Trip added successfully." << std::endl;
                            break;
                        case 2:
                            op.printAllTrips();
                            int tripId;
                            std::cout << "Enter destination ID to delete: ";
                            std::cin >> tripId;
                            op.deleteTrip(tripId);
                            std::cout << "Trip deleted successfully." << std::endl;
                            break;
                        case 3:
                            std::cout << "Enter the destination of the trip to modify: ";
                            std::getline(std::cin, destination);
                            std::cout << "Enter the new destination: ";
                            std::getline(std::cin, newDestination);
                            std::cout << "Enter the new date: ";
                            std::getline(std::cin, newDate);
                            op.modifyTrip(destination, newDestination, newDate);
                            std::cout << "Trip modified successfully." << std::endl;
                            break;
                        case 4:
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                        }

                        if (choice == 4) {
                            break; // Exit admin menu loop
                        }
                    }
                }
                else {
                    while (true) {
                        displayUserMenu();
                        std::cout << "Enter your choice: ";
                        std::cin >> choice;
                        switch (choice) {
                        case 1:
                            int tripId;
                            op.printAllTrips();
                            std::cout << "Enter destination Id: ";
                            std::cin >> tripId;
                            user.reserveTrip(tripId, username);
                            break;
                        case 2:
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Enter destination: ";
                            std::getline(std::cin, d);
                            user.showTripsToDestination(d);
                            break;
                        case 3:
                            user.showUserReservations(username);
                            break;
                        case 4:
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                        }
                    }

                    if (choice == 4) {
                        break;
                    }
                }
            }
            else {
                std::cout << "Login failed." << std::endl;
            }
            break;
        }
        
        }
    }

    return 0;
}