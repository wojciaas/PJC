#include "FileManager.h"

/**
 * @brief This is the constructor of the FileManager class.
 * @details This constructor initializes the encryption, password and password manager.
 */

FileManager::FileManager() {
    encryption = Encryption();
    passwordManager = PasswordManager();
}

/**
 * @brief This method is used to list all the files with the extension ".pjc" and choose one.
 * @return A map with the index and the path of the file.
 */

auto FileManager::listAndChooseFile() -> std::map<int, std::string> {
    int iter = 0;
    auto filesNames = std::map<int, std::string>();

    for (auto const &p: std::filesystem::directory_iterator("./"))
        if (p.path().extension() == ".pjc")
            filesNames.insert(std::pair<int, std::string>(++iter, p.path().string()));
    return filesNames;
}

/**
 * @brief This method is used to check if the file form specific path exists.
 * @param path The path of the file.
 * @return True if the file exists, false otherwise.
 */

auto FileManager::isFileOpen(const std::string& path) -> bool {
    file.open(path);
    bool isOpen = file.is_open();
    if (isOpen) file.close();
    return isOpen;
}

/**
 * @brief This method is used to get the password manager.
 * @return The password manager reference.
 */

auto FileManager::getPasswordManager() -> PasswordManager& {
    return this->passwordManager;
}

/**
 * @brief This method is used to set the path of the file.
 * @param path The path of the file.
 */

auto FileManager::setPath(const std::string& path) -> void {
    this->path = path;
}

/**
 * @brief This method is used to set the master password for the encryption.
 * @param password Entered password.
 */

auto FileManager::setPassword(const std::string& password) -> void {
    this->encryption.setMasterPassword(password);
    writeFileContent();
    readFile();
}

/**
 * @brief This method is used to read passwords from file and write them to the password manager.
 */

auto FileManager::readFile() -> void {
    if (!file.is_open()) file.open(path, std::ios::in);
    std::string name, password, category, service, login;
    std::size_t posY = 1;
    for(auto line = std::string(); std::getline(file, line); posY++) {
        std::stringstream ss(line);
        std::string token;
        char c;
        if (posY == 1 || posY == 3 || posY == 7){
            ss >> c >> c;
        }
        ss >> token;
        category = translateUnderscoreToSpaces(encryption.decrypt(token));
        ss >> token;
        password = encryption.decrypt(token);
        ss >> token;
        name = translateUnderscoreToSpaces(encryption.decrypt(token));

        if(!ss.eof()) {
            name = translateUnderscoreToSpaces(encryption.decrypt(token));
            ss >> token;
            if(!ss.eof()) {
                login = translateUnderscoreToSpaces(encryption.decrypt(token));
            }
        }
        passwordManager.addPassword(name, password, category, service, login);
    }
    file.close();
}

/**
 * @brief This method is used to write the passwords to the file.
 */

auto FileManager::writeFile() -> void {
    if (!file.is_open()) file.open(path, std::ios::out | std::ios::trunc);
    int posY = 1;

    for (auto const& [key, value] : passwordManager.getPasswords()) {
        for (auto password : value) {
            if (posY == 1)
                file << fileContent.at(0);
            else if (posY == 3)
                file << fileContent.at(1);
            else if (posY == 7)
                file << fileContent.at(2);
            file << encryption.encrypt(translateSpacesToUnderscore(password.category)) << " ";
            file << encryption.encrypt(translateSpacesToUnderscore(password.password)) << " ";
            file << encryption.encrypt(translateSpacesToUnderscore(password.name));
            if (!password.login.empty()) file << " " << encryption.encrypt(translateSpacesToUnderscore(password.login)) << " ";
            if (!password.service.empty()) file << encryption.encrypt(translateSpacesToUnderscore(password.service));
            file << std::endl;
        }
        posY++;
    }
    file.close();
}

/**
 * @brief This method is used to translate underscores to spaces.
 * @param string The string to translate.
 * @return The string with spaces.
 */

auto FileManager::translateUnderscoreToSpaces(std::string &string) -> const std::string& {
    for (char & i : string) {
        if (i == '_') i = ' ';
    }
    return string;
}

/**
 * @brief This method is used to translate spaces to underscores.
 * @param string The string to translate.
 * @return The string with underscores.
 */

auto FileManager::translateSpacesToUnderscore(std::string &string) -> std::string& {
    for (char & i : string) {
        if (i == ' ') i = '_';
    }
    return string;
}

/**
 * @brief This method is used to write the timestamp to the vector.
 * @return The vector with the file content.
 */

auto FileManager::writeFileContent() -> const std::vector<std::string>&{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);
    fileContent.push_back(std::to_string(now_tm->tm_hour));
    fileContent.push_back(std::to_string(now_tm->tm_min));
    fileContent.push_back(std::to_string(now_tm->tm_sec));
    return fileContent;
}