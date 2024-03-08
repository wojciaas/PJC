#include "PasswordManager.h"

/**
 * @brief Default constructor for PasswordManager class.
 */

PasswordManager::PasswordManager() {
    passwords = std::map<std::string, std::vector<Password>>();
}

/**
 * @brief This is the constructor for the Password struct.
 * @param name The name of the password.
 * @param password The password.
 * @param category The category of the password.
 * @param service The service of the password.
 * @param login The login of the password.
 */

Password::Password(const std::string& name, const std::string& password, const std::string& category, const std::string& service, const std::string& login) {
    this->name = name;
    this->password = password;
    this->category = category;
    this->service = service;
    this->login = login;
}

/**
 * @brief This method is used to search for passwords.
 */

auto PasswordManager::searchPasswords() -> void {

}

/**
 * @brief This method is used to sort the passwords.
 */

auto PasswordManager::sortPasswords() -> void {

}

/**
 * @brief This method is used to add a password to the map.
 * @param name The name of the password.
 * @param password The password.
 * @param category The category of the password.
 * @param service The service of the password.
 * @param login The login of the password.
 */

auto PasswordManager::addPassword(const std::string& name, const std::string& password, const std::string& category, const std::string& service, const std::string& login) -> void {
    passwords[category].emplace_back(name, password, category, service, login);
}

/**
 * @brief This method is used to delete a password.
 */

auto PasswordManager::deletePassword() -> void {

}

/**
 * @brief This method is used to add a category.
 * @param category The category to add.
 */

auto PasswordManager::addCategory(const std::string& category) -> void {
    passwords[category];
}

/**
 * @brief This method is used to delete a category.
 * @param category The category to delete.
 */

auto PasswordManager::deleteCategory(const std::string& category) -> void {
    passwords.erase(category);
}

/**
 * @brief This method is used to get the passwords.
 * @return The passwords.
 */

auto PasswordManager::getPasswords() -> std::map<std::string, std::vector<Password>>& {
    return passwords;
}

/**
 * @brief This method is used to generate a password.
 * @param length The length of the password.
 * @param upper Whether or not the password should contain uppercase letters.
 * @param special Whether or not the password should contain special characters.
 * @return The generated password.
 */

auto PasswordManager::generatePassword(const int& length, const bool& upper, const bool& special) -> std::string {
    std::string password;
    std::string characters = "abcdefghijklmnopqrstuvwxyz";
    if (upper)
        characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (special)
        characters += "!@#$%^&*()-_+=[]{};:\"'<>,.?/\\|";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, characters.length() - 1);

    for (int i = 0; i < length; i++)
        password += characters[distrib(gen)];
    return password;
}

/**
 * @brief This method is used to check if a password is used.
 * @param password The password to check.
 * @return Whether or not the password is used.
 */

auto PasswordManager::isPasswordUsed(const std::string& password) -> bool {
    for (auto& category : passwords) {
        for (auto& pass : category.second) {
            if (pass.password == password)
                return true;
        }
    }
    return false;
}

/**
 * @brief This method is used to check the strength of a password.
 * @param password The password to check.
 * @return The strength of the password.
 */

auto PasswordManager::passwordStrength(const std::string &password) -> int {
    int strength = 1;
    if (password.length() >= 8)
        strength++;
    for(auto& character : password)
        if (isupper(character)){
            strength++;
            break;
        }
    for(auto& character : password)
        if (ispunct(character)){
            strength++;
            break;
        }
    return strength;
}