#include <iostream>
#include <vector>

void fMaxMin(const int *tab, const int size, int &max, int *min, int **cMax, int *&cMin);

template<typename T>
std::vector<T> operator+ (const std::vector<T> &V1, const std::vector<T> &V2){
    auto iterations = std::max(V1.size(), V2.size());
    auto res = std::vector<T>();
    T val1;
    T val2;
    for (int i = 0; i < iterations; ++i) {
        val1 = (i < V1.size() ? V1.at(i) : 0);
        val2 = (i < V2.size() ? V2.at(i) : 0);
        res.push_back(val1 + val2);
    }
    return res;
}

int main(){
    int max;
    int min;
    int cMax;
    int cMin;

    int *pCMax = &cMax;
    int *pCMin = &cMin;

    const int size = 12;
    int a[size] = {1, 2, 1, 42, 2, 2, 42, 1, 1, 2, 1, 42};

    fMaxMin(a, size, max, &min, &pCMax, pCMin);

    std::cout << "max -> " << max << std::endl;
    std::cout << "min -> " << min << std::endl;
    std::cout << "cMax -> " << cMax << std::endl;
    std::cout << "cMin -> " << cMin << std::endl;

    {
        std::vector<int> vec1{1, 2, 3};
        std::vector<int> vec2{4, 5, 6, 7};

        auto result = vec1 + vec2;

        for (auto &item : result)
            std::cout << item << "\t";
        std::cout << std::endl;
    }

    {
        std::vector<float> vec1{1, 2, 3};
        std::vector<float> vec2{4, 5, 6, 7};

        std::vector<float> result = vec1 + vec2;

        for (auto &item: result) {
            std::cout << item << "\t";
        }
        std::cout << std::endl;
    }
}

void fMaxMin(const int *tab, const int size, int &max, int *min, int **cMax, int *&cMin){
    int inMax = tab[0];
    int inMin = tab[0];
    int CMax = 1;
    int CMin = 1;
    for (int i = 1; i < size; ++i) {
        if (tab[i] == inMax)
            CMax++;
        if (tab[i] == inMin)
            CMin++;

        if (tab[i] > inMax){
            inMax = tab[i];
            CMax = 1;
        }
        if (tab[i] < inMin){
            inMin = tab[i];
            CMin = 1;
        }
    }
    max = inMax;
    *min = inMin;
    *cMin = CMin;
    **cMax = CMax;
}