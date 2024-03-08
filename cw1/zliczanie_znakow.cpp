#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;

int countChars(vector<char> vec, char c);
int countChars(string s, char c);

int main() {
    cout << countChars(vector<char>{'a', 'l', 'a'}, 'a') << '\n'
        << countChars("", 'a') << '\n'
        << countChars(string{'k', 'a', 'j', 'a', 'k'}, 'a') << '\n'
        << countChars(string("kajak"), 'k') << '\n'
        << countChars(vector<char>{'k', 'a', 'j', 'a', 'k'}, 'j') << '\n'
        << countChars("kajak", 'x') << '\n';

    return 0;
}
int countChars(vector<char>vec, char c) {
    int counter{0};
    for (int i = 0; i < vec.size(); ++i) {
        if (vec.at(i) == c) counter++;
    }
    return counter;
    //return count_if(vec.begin(), vec.end(), find(vec.begin(), vec.end(),c));}
}

int countChars(string s, char c) {
    int counter{0};
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == c) counter++;
    }
    return counter;
}