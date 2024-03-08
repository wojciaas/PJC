#include <string>
#include <fmt/core.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <map>
#include <chrono>
#include <ctime>
#include <vector>
#include "PasswordManager.h"
#include "Encryption.h"
#pragma once

class FileManager {
public:
    FileManager();
    auto listAndChooseFile() -> std::map<int, std::string>;
    auto isFileOpen(const std::string& path) -> bool;
    auto getPasswordManager() -> PasswordManager&;
    auto setPath(const std::string& path) -> void;
    auto setPassword(const std::string& password) -> void;
    auto writeFile() -> void;
private:
    std::string path;
    std::fstream file;
    PasswordManager passwordManager;
    Encryption encryption;
    std::vector<std::string> fileContent;
    auto writeFileContent() -> const std::vector<std::string>&;
    auto readFile() -> void;
    auto translateUnderscoreToSpaces(std::string& string) -> std::string const&;
    auto translateSpacesToUnderscore(std::string& string) -> std::string&;
};