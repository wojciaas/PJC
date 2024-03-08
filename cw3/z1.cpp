#include <iostream>
#include <vector>
#include <fmt/ranges.h>

enum VERSION{EVEN, ODD, PRIME};

using std::cout;
using std::vector;
using std::erase_if;
using std::sqrt;
using fmt::print;

auto remove_if_enum(vector<int>&V, VERSION ver) -> vector<int>{
    switch (ver) {
        case EVEN : erase_if(V,[](int n) -> bool{return n % 2 == 0;});
            return V;
        case ODD : erase_if(V, [](int n) -> bool{return n % 2 != 0;});
            return V;
        case PRIME : erase_if(V, [](int n) -> bool {
                if(n < 2) return false;
                for (int i = 2; i < sqrt(n); ++i) {
                    if (n % i) return false;
                }
                return true;
        });
            return V;
    }
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    print("{}\n",remove_if_enum(vec, PRIME));
    print("{}\n",remove_if_enum(vec, EVEN));
    print("{}\n",remove_if_enum(vec, ODD));
}