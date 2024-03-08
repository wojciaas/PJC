#include <iostream>

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int&mx, size_t& ix);

int main(){
    using std::cout;
    int a[]{2,3,4,2,7,4,7,2};
    size_t size = sizeof(a)/sizeof(*a);
    int mn, mx;
    size_t in, ix;
    minMaxRep(a,size,mn,in,mx,ix);
    cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << "]\n";
    cout << "Min = " << mn << " " << in << " times\n";
    cout << "Max = " << mx << " " << ix << " times\n";
}

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int&mx, size_t& ix){
    int min = a[0];
    int max = a[0];
    int cMin = 1;
    int cMax = 1;
    for (int i = 1; i < size; ++i) {
        if (a[i] == min)
            cMin++;
        if (a[i] == max)
            cMax++;

        if (a[i] < min){
            min = a[i];
            cMin = 1;
        }
        if (a[i] > max){
            max = a[i];
            cMax = 1;
        }
    }
    mn = min;
    mx = max;
    in = cMin;
    ix = cMax;
}