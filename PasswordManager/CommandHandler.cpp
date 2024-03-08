#include "CommandHandler.h"

/**
 * @brief Default constructor for CommandHandler class.
 */

CommandHandler::CommandHandler() {
    fileManager = FileManager();
    option = 0;
}

/**
 * @brief This method is used to run the program.
 */

auto CommandHandler::run() -> void {
    fmt::println(
            "┌{0:─^{2}}┐\n"
            "│{1: ^{2}}│\n"
            "└{0:─^{2}}┘\n", "", "PASSWORD MANAGER", 20);
    fileManagerInstructions();
}

/**
 * @brief This method is used to display the file manager instructions.
 */

auto CommandHandler::fileManagerInstructions() -> void {
    do {
        fmt::println("----------File Manager---------");
        fmt::print("Choose an option:\n"
                   "1. List files from default directory\n"
                   "2. Enter the absolute path of the file\n"
                   "3. Exit\n"
                   "Enter option: ");
        std::cin >> option;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fmt::print("Invalid option. Enter the correct option: ");
            std::cin >> option;
        }
        switch (option) {
            case 1:
                system("cls");
                fmt::println("----------Files from default directory---------");
                size_t filesAmount;
                int chosenFile;
                do {
                    auto filesNames = fileManager.listAndChooseFile();
                    int iter = 0;
                    filesAmount = filesNames.size();
                    for (auto const &p: std::filesystem::directory_iterator("./")) {
                        if (p.path().extension() == ".pjc")
                            fmt::println("{}. -> {}", ++iter, p.path().filename().string());
                    }
                    fmt::print("Choose the file or 0 to exit: ");
                    std::cin >> chosenFile;
                    while(std::cin.fail() || chosenFile < 0 || chosenFile > filesAmount) {
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        fmt::print("Invalid option. Enter the correct option: ");
                        std::cin >> chosenFile;
                    }

                    if (chosenFile != 0){
                        std::string password;
                        fmt::print("Enter the {} password: ", filesNames[chosenFile]);
                        std::cin >> password;
                        fileManager.setPath(filesNames[chosenFile]);
                        fileManager.setPassword(password);
                    }
                } while (chosenFile < 0 && chosenFile > filesAmount);
                system("cls");
                passwordManagerInstructions();
                break;
            case 2:
                system("cls");
                fmt::println("----------File from specific destination---------");
                bool isFileOpen;
                do {
                    std::string path;
                    fmt::print("Enter the absolute path of the file: ");
                    std::cin >> path;
                    isFileOpen = fileManager.isFileOpen(path);
                    if (!isFileOpen)
                        fmt::println("File not found. Try again.");
                    else {
                        std::string password;
                        fmt::print("Enter the {} password: ", path);
                        std::cin >> password;
                        fileManager.setPath(path);
                        fileManager.setPassword(password);
                    }
                } while (!isFileOpen);
                system("cls");
                passwordManagerInstructions();
                break;
            case 3:
                fmt::println("Goodbye..");
                exit(0);
            default:
                fmt::print("Invalid option. Enter the correct option: ");
                break;
        }
    } while (option != 3);
}

/**
 * @brief This method is used to display the password manager instructions.
 */

auto CommandHandler::passwordManagerInstructions() -> void {
    int option = 0;
    std::string category, password, name, service, login, choice;
    do {
        fmt::println("----------Password Manager---------");
        fmt::print("Choose an option:\n"
                   "1. Search passwords\n"
                   "2. Sort passwords\n"
                   "3. Add password\n"
                   "4. Edit password\n"
                   "5. Delete password\n"
                   "6. Add category\n"
                   "7. Delete category\n"
                   "8. Exit\n"
                   "Enter option: ");
        std::cin >> option;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fmt::print("Invalid option. Enter the correct option: ");
            std::cin >> option;
        }
        switch (option) {
            case 1:
                system("cls");
                fmt::println("----------Search passwords---------");
                fileManager.getPasswordManager().searchPasswords();
                break;
            case 2:
                system("cls");
                fmt::println("----------Sort passwords---------");
                fileManager.getPasswordManager().sortPasswords();
                break;
            case 3:
                system("cls");
                fmt::println("----------Add password---------");
                listCategories();
                if (!fileManager.getPasswordManager().getPasswords().empty()) {
                    fmt::print("Choose the category to add the password: ");
                    std::cin >> category;
                    while (!fileManager.getPasswordManager().getPasswords().contains(category)) {
                        fmt::print("Category not found. Enter the correct category: ");
                        std::cin >> category;
                    }
                    fmt::print("Enter the name of the password: ");
                    std::cin >> name;
                    fmt::print("Do you want to generate a password? (y/n): ");
                    std::cin >> choice;
                    while (choice != "y" && choice != "n") {
                        fmt::print("Invalid option. Enter the correct option: ");
                        std::cin >> choice;
                    }
                    if (choice == "y") {
                        fmt::print("Enter the length of the password: ");
                        int length;
                        std::cin >> length;
                        while(std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            fmt::print("Invalid option. Enter the correct option: ");
                            std::cin >> length;
                        }
                        fmt::print("Do you want to use uppercase? (y/n): ");
                        std::cin >> choice;
                        while (choice != "y" && choice != "n") {
                            fmt::print("Invalid option. Enter the correct option: ");
                            std::cin >> choice;
                        }
                        bool uppercase = choice == "y";
                        fmt::print("Do you want to use special characters? (y/n): ");
                        std::cin >> choice;
                        while (choice != "y" && choice != "n") {
                            fmt::print("Invalid option. Enter the correct option: ");
                            std::cin >> choice;
                        }
                        bool specialCharacters = choice == "y";
                        do {
                            password = fileManager.getPasswordManager().generatePassword(length, uppercase, specialCharacters);
                            fmt::println("Generated password: {}", password);
                            fmt::print("Do you want to use this password? (y/n): ");
                            std::cin >> choice;
                        } while (choice == "n");
                    } else {
                        fmt::print("Enter the password: ");
                        std::cin >> password;
                        while (fileManager.getPasswordManager().isPasswordUsed(password)){
                            fmt::print("Password already used. Enter another password: ");
                            std::cin >> password;
                        }
                        switch (fileManager.getPasswordManager().passwordStrength(password)) {
                            case 1:
                                fmt::println("Password strength: Weak");
                                break;
                            case 2:
                                fmt::println("Password strength: Weak");
                                break;
                            case 3:
                                fmt::println("Password strength: Medium");
                                break;
                            case 4:
                                fmt::println("Password strength: Strong");
                                break;
                        }
                    }
                    fmt::print("Do you want to add a service? (y/n): ");
                    std::cin >> choice;
                    while (choice != "y" && choice != "n") {
                        fmt::print("Invalid option. Enter the correct option: ");
                        std::cin >> choice;
                    }
                    if (choice == "y") {
                        fmt::print("Enter the service: ");
                        std::cin >> service;
                    }
                    fmt::print("Do you want to add a login? (y/n): ");
                    std::cin >> choice;
                    while (choice != "y" && choice != "n") {
                        fmt::print("Invalid option. Enter the correct option: ");
                        std::cin >> choice;
                    }
                    if (choice == "y") {
                        fmt::print("Enter the login: ");
                        std::cin >> login;
                    }
                    fileManager.getPasswordManager().addPassword(name, password, category, service, login);
                } else {
                    fmt::println("There are no categories to add the password!");
                }
                break;
            case 4: {
                system("cls");
                fmt::println("----------Edit password---------");
                listCategories();
                fmt::print("Enter the category to list the passwords: ");
                std::cin >> category;
                while (!fileManager.getPasswordManager().getPasswords().contains(category)) {
                    fmt::print("Category not found. Enter the correct category: ");
                    std::cin >> category;
                }
                fmt::println("Passwords from category {}:", category);
                int i = 1, passwordIndex;
                for (auto const &p: fileManager.getPasswordManager().getPasswords().at(category))
                    fmt::println("{}. {}", i++, p.name);
                fmt::print("Select the password: ");
                std::cin >> passwordIndex;
                while (passwordIndex < 1 || passwordIndex > fileManager.getPasswordManager().getPasswords().at(category).size()) {
                    fmt::print("Invalid option. Enter the correct option: ");
                    std::cin >> passwordIndex;
                }
                fmt::print("Do you want to edit the name? (y/n): ");
                std::cin >> choice;
                while (choice != "y" && choice != "n") {
                    fmt::print("Invalid option. Enter the correct option: ");
                    std::cin >> choice;
                }
                if (choice == "y") {
                    fmt::print("Enter the new name: ");
                    std::cin >> name;
                    fileManager.getPasswordManager().getPasswords().at(category).at(passwordIndex - 1).name = name;
                }
                fmt::print("Do you want to edit the password? (y/n): ");
                std::cin >> choice;
                while (choice != "y" && choice != "n") {
                    fmt::print("Invalid option. Enter the correct option: ");
                    std::cin >> choice;
                }
                if (choice == "y") {
                    fmt::print("Enter the new password: ");
                    std::cin >> password;
                    while (fileManager.getPasswordManager().isPasswordUsed(password)){
                        fmt::print("Password already used. Enter another password: ");
                        std::cin >> password;
                    }
                    fileManager.getPasswordManager().getPasswords().at(category).at(passwordIndex - 1).password = password;
                }
                fmt::print("Do you want to edit the service? (y/n): ");
                std::cin >> choice;
                while (choice != "y" && choice != "n") {
                    fmt::print("Invalid option. Enter the correct option: ");
                    std::cin >> choice;
                }
                if (choice == "y") {
                    fmt::print("Enter the new service: ");
                    std::cin >> service;
                    fileManager.getPasswordManager().getPasswords().at(category).at(passwordIndex - 1).service = service;
                }
                fmt::print("Do you want to edit the login? (y/n): ");
                std::cin >> choice;
                while (choice != "y" && choice != "n") {
                    fmt::print("Invalid option. Enter the correct option: ");
                    std::cin >> choice;
                }
                if (choice == "y") {
                    fmt::print("Enter the new login: ");
                    std::cin >> login;
                    fileManager.getPasswordManager().getPasswords().at(category).at(passwordIndex - 1).login = login;
                }
            }
                break;
            case 5:
                system("cls");
                fmt::println("----------Delete password---------");
                fileManager.getPasswordManager().deletePassword();
                break;
            case 6:
                system("cls");
                fmt::println("----------Add category---------");
                fmt::print("Enter the category name to add: ");
                std::cin >> category;
                while (fileManager.getPasswordManager().getPasswords().contains(category)) {
                    fmt::print("Category already exists. Enter another category: ");
                    std::cin >> category;
                }
                fileManager.getPasswordManager().addCategory(category);
                break;
            case 7:
                system("cls");
                if (!fileManager.getPasswordManager().getPasswords().empty()){
                    fmt::println("----------Delete category---------");
                    listCategories();
                    fmt::print("Enter the category to delete: ");
                    std::cin >> category;
                    while (!fileManager.getPasswordManager().getPasswords().contains(category)) {
                        fmt::print("Category not found. Enter the correct category: ");
                        std::cin >> category;
                    }
                    fileManager.getPasswordManager().deleteCategory(category);
                } else {
                    fmt::println("There are no categories to delete!");
                }
                break;
            case 8:
                fileManager.writeFile();
                system("cls");
                break;
            default:
                fmt::print("Invalid option. Enter the correct option: ");
                break;
        }
    } while (option != 8);
}

/**
 * @brief List all categories
 */

auto CommandHandler::listCategories() -> void {
    fmt::println("Categories:");
    for(auto const &c : fileManager.getPasswordManager().getPasswords())
        fmt::println("{}", c.first);
}
