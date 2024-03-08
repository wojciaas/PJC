#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main(){
    vector<string>names{};
    auto name = string();
    bool unique = true;
    cout << "Podaj imiona: ";
    for (int i = 0; i < 10; ++i) {
        cin >> name;
        names.push_back(name);
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (names.at(i) == names.at(j)) unique = false;
        }
        names.
    }
}