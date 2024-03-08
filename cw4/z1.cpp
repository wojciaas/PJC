#include <vector>
#include <set>
#include <fmt/ranges.h>

int main(){
    auto vec = std::vector<int>{3,4,2,5,6,1};
    auto set = std::set<int>(vec.begin(), vec.end());
    fmt::print("{}\n", set);
}