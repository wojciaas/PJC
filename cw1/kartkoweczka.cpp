#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;
using std::string;

bool length(vector<string>v1, vector<string>v2);

int main(){
    vector<string> vec1{"asia", "basia", "lala"}, vec2{"janina", "elzbieta", "konstantynopolitanczykowianeczka"};
    cout << (length(vec1, vec2) != 0 ? "true" : "false");
}

bool length(vector<string>v1, vector<string>v2){
    string najdluzszy1 = v1.at(0), najdluzszy2 = v2.at(0);
    for (int i = 0; i < v1.size(); ++i) {
        if (najdluzszy1.length() < v1.at(i).length()) {
            najdluzszy1 = v1.at(i);
        }
    }
    for (int i = 0; i < v2.size(); ++i) {
        if (najdluzszy2.length() < v2.at(i).length()) {
            najdluzszy2 = v2.at(i);
        }
    }
    return najdluzszy1.length() < najdluzszy2.length();
}