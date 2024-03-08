#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::accumulate;

vector<int> sort_bigger_half(vector<int>vec);
void showV(vector<int>V);

int main(){
    vector<int> v1 = {8,3,5,6,5,1,5,4,2};
    showV(v1);
    showV(sort_bigger_half(v1));
}

void showV(vector<int>V){
    for (auto num:V) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> sort_bigger_half(vector<int>vec){
    accumulate(vec.begin(), vec.begin() + vec.size()/2, 0) >
    accumulate(vec.rbegin(), vec.rbegin() + vec.size()/2, 0) ?
    sort(vec.begin(), vec.begin() + vec.size()/2) :
    sort(vec.rbegin(), vec.rbegin() + vec.size()/2);
    return vec;
}
