#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int countEvens(vector<int>vec){
    int counter{};
    for (int i = 0; i < vec.size(); ++i) {
        if (vec.at(i) % 2 == 0) counter++;
    }
    return counter;
}

auto main() -> int {
    cout << countEvens({1, 2, 3, 4, 5}) << '\n'
         << countEvens({}) << '\n'
         << countEvens({1, -3, 5}) << '\n'
         << countEvens({0, 2, -4, 8}) << '\n';

    return 0;
}
