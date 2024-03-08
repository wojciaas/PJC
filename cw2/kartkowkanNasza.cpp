#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::ranges::reverse;
using std::endl;

vector<float> fun(vector<int> vec);
void showV(vector<float> V);

int main(){
    vector<int> vec {1,2,3,4,5,6,7,8,9};
    showV(fun(vec));
    vector<float>res = fun((vec));
    reverse(res);
    cout << endl;
    res.pop_back();
    showV(res);
}
vector<float> fun(vector<int> vec){
    vector<float> res{};
    for (int i = 0; i < vec.size(); ++i) {
        if(i % 3 == 0) res.push_back(vec.at(i));
    }
    return res;
}

void showV(vector<float>V){
    for (auto value:V) {
        cout << value << " ";
    }
}