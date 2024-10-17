bool isAdmin(const std::string& username) {
    // Implement a method to check if the user is an admin (e.g., based on a role in the database)
    // For simplicity, assume admin if the username is "admin"
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
    std::cout << "1. Register a new user" << std::endl;
    std::cout << "2. Log in" << std::endl;
    std::cout << "3. Add a trip" << std::endl;
    std::cout << "4. Reserve a trip" << std::endl;
    std::cout << "5. Show trips to destination" << std::endl;
    std::cout << "6. Show user reservations" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "-------------------------" << std::endl;
}

int main() {
    const char* dbName = "database.db";
    User user(dbName);
    Operator op(dbName);

    while (true) {
        std::string username;
        std::cout << "Enter username: ";
        std::getline(std::cin, username);

        if (!user.userExists(username)) {
            std::cout << "User does not exist. Please register first." << std::endl;
            continue;
        }

        displayMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        if (isAdmin(username)) {
            // Admin menu
            switch (choice) {
                case 1:
                    // Add a trip
                    break;
                case 2:
                    // Delete a trip
                    break;
                case 3:
                    // Modify a trip
                    break;
                case 4:
                    // Exit
                    std::cout << "Exiting the application. Goodbye!" << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } else {
            // Regular user menu
            switch (choice) {
                case 1:
                    // Register a new user
                    break;
                case 2:
                    // Log in
                    break;
                case 3:
                    // Add a trip
                    break;
                case 4:
                    // Reserve a trip
                    break;
                case 5:
                    // Show trips to destination
                    break;
                case 6:
                    // Show user reservations
                    break;
                case 7:
                    // Exit
                    std::cout << "Exiting the application. Goodbye!" << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    return 0;
}