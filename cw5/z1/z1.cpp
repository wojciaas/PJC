#include <fstream>
#include <string>
#include <fmt/ranges.h>
#include <iostream>
#include <sstream>

int main(){
    auto file = std::fstream("C:\\Users\\Wojtek\\Desktop\\PJC\\cw5\\z1\\plik.txt");
    for (auto line = std::string(); std::getline(file, line); ) {
        auto word = std::string();
        auto strStream = std::stringstream(line);
        strStream >> word;
        auto plik = std::fstream("C:\\Users\\Wojtek\\Desktop\\PJC\\cw5\\z1\\"+word+".txt", std::fstream::app);
        while(strStream >> word){
            plik << word + "\n";
        }
    }
}