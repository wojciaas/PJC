#include <string>
#pragma once

class Encryption {
public:
    Encryption();
    auto encrypt(std::string& string) -> std::string&;
    auto decrypt(std::string& string) -> std::string&;
    auto setMasterPassword(const std::string& password) -> void;
private:
    std::string masterPassword;
};