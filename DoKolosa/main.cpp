#include <iostream>
#include <map>
#include <fstream>
#include <string>

int main() {
    auto charCounter = std::map<char, int>();
    std::string word = "kobyla ma maly bok";
    for (auto &c : word)
        charCounter[c] ++;
    for (auto &[key, pair] : charCounter)
        std::cout << key << " -> " << pair << std::endl;
    return 0;
}
