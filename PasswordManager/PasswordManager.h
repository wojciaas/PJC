#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <random>
#include "Encryption.h"
#pragma once

struct Password {
    Password(const std::string& name, const std::string& password, const std::string& category, const std::string& service, const std::string& login);
    std::string name;
    std::string password;
    std::string category;
    std::string service;
    std::string login;
};

class PasswordManager {
public:
    PasswordManager();
    auto searchPasswords() -> void;
    auto sortPasswords() -> void;
    auto addPassword(const std::string& name, const std::string& password, const std::string& category, const std::string& service, const std::string& login) -> void;
    auto deletePassword() -> void;
    auto addCategory(const std::string& category) -> void;
    auto deleteCategory(const std::string& category) -> void;
    auto getPasswords() -> std::map<std::string, std::vector<Password>>&;
    auto generatePassword(const int& length, const bool& upper, const bool& special) -> std::string;
    auto isPasswordUsed(const std::string& password) -> bool;
    auto passwordStrength(const std::string& password) -> int;
private:
    std::map<std::string, std::vector<Password>> passwords;
};