#include <fmt/ranges.h>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <set>

int main(){
    auto file = std::fstream("C:\\Users\\Wojtek\\Desktop\\PJC\\cw5\\kartkowkaPrzykladowa\\file.txt", std::fstream::in);
    auto literka = char();
    auto counter = int();
    auto literkowo = std::map<char, std::vector<int>>();

    for (auto line = std::string(); std::getline(file, line) ; ) {
        auto strStream = std::stringstream(line);
        counter++;
        while (strStream >> literka){
            literkowo[literka].push_back(counter);
        }
    }

    for (auto [literka, linia] : literkowo) {
        auto res = std::set(linia.begin(), linia.end());
        fmt::print("{} -> {}\n", literka, res);
    }
}