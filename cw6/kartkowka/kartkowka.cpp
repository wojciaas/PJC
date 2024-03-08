#include "fmt/ranges.h"
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void fun(float &d1, float &d2);

int main(){
    auto file = std::fstream("C:\\Users\\s27994\\CLionProjects\\PJC_PJ\\cw6\\numbers.txt");
    auto cyferkowo = std::map<int, int>();
    auto number = int();

    while(file >> number){
        cyferkowo[number] += 1;
    }
    for (auto pair : cyferkowo) {
        fmt::print("{} -> {}\n", pair.first, pair.second);
    }

    auto d1 = 2.0f;
    auto d2 = 3.14f;
    fun(d1,d2);
    fmt::print("Suma {}, Iloczyn {}", d1, d2);
    return 0;
}

void fun(float &d1, float &d2){
    auto tmp = d1;
    d1 += d2;
    d2 *= tmp;
}