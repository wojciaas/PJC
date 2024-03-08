#include "Encryption.h"

/**
 * @brief Default constructor for Encryption class.
 */

Encryption::Encryption() = default;

/**
 * @brief This method is used to set the master password for the encryption.
 * @param password The master password.
 */

auto Encryption::setMasterPassword(const std::string& password) -> void {
    this->masterPassword = password;
}

/**
 * @brief This method is used to encrypt a string.
 * @param string The string to encrypt.
 * @return The encrypted string.
 */

auto Encryption::encrypt(std::string& string) -> std::string& {
    int control = 0;
    for (char i : masterPassword) {
        control += ((int)i > 100 ? (int)i % 100 : (int)i % 10);
    }
    for (int i = 0; i < string.length(); i++){
        string[i] = (char)((int)string[i] + control);
    }
    return string;
}

/**
 * @brief This method is used to decrypt a string.
 * @param string The string to decrypt.
 * @return The decrypted string.
 */

auto Encryption::decrypt(std::string& string) -> std::string& {
    int control = 0;
    for (char i : masterPassword) {
        control += ((int)i > 100 ? (int)i % 100 : (int)i % 10);
    }
    for (int i = 0; i < string.length(); ++i) {
        string[i] = (char)((int)string[i] - control);
    }
    return string;
}