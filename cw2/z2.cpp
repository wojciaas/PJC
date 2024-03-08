#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

vector<int> erase_n_biggest(vector<int>vec, int n);
void showV(vector<int>V);
int max_elem(vector<int>vec);

int main(){

}

vector<int> erase_n_biggest(vector<int>vec, int n){
    if (n >= vec.size())
        vec.clear();
    else
        for (int i = 0; i < n; ++i) {

        }
    return vec;
}

int max_elem(vector<int>vec){
    return std::max_element(vec.begin(), vec.end())
}

void showV(vector<int>V){
    for (auto num:V) {
        cout << num << " " << endl;
    }
}

