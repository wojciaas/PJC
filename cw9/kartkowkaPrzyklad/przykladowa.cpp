#include <vector>
#include <iostream>

void fMaxMin(std::vector<int*>vec, int *max, int **min, int **&cMax, int *&cMin);

std::vector<int> operator* (std::vector<int> const &vec1, std::vector<int> const &vec2){
    return std::vector<int>{vec1[0] * vec2[0], vec1[vec1.size() - 1] * vec2[vec2.size() - 1]};
}

int main(){
    auto vec = std::vector<int> {1, 2, 1, 42, 2, 2, 42, 1, 1, 2, 1, 42};
    auto vecP = std::vector<int*>();

    for (auto &item : vec){
        vecP.push_back(&item);
    }

    int max;
    int min;
    int cMax;
    int cMin;

    int *pMin = &min;
    int *cMaxHelp = &cMax;
    int **pCMax = &cMaxHelp;
    int *pCMin = &cMin;

    fMaxMin(vecP, &max, &pMin, pCMax, pCMin);

    std::cout << "max -> " << max << std::endl;
    std::cout << "min -> " << min << std::endl;
    std::cout << "cMax -> " << cMax << std::endl;
    std::cout << "cMin -> " << cMin << std::endl;

    auto vec1 = std::vector<int>{1,2,3};
    auto vec2 = std::vector<int>{6,2,3,4,5,8};
    auto vecR = vec1 * vec2;

    for(int &i : vecR){
        std::cout << i << " ";
    }
}

void fMaxMin(std::vector<int*>vec, int *max, int **min, int **&cMax, int *&cMin){
    int inMin = *vec.at(0);
    int inMax = *vec.at(0);
    int inCMax = 1;
    int inCMin = 1;

    for (int i = 1; i < vec.size(); ++i) {
        if (*vec.at(i) == inMin)
            inCMin++;
        if (*vec.at(i) == inMax)
            inCMax++;

        if (*vec.at(i) < inMin){
            inMin = *vec.at(i);
            inCMin = 1;
        }
        if (*vec.at(i) > inMax){
            inMax = *vec.at(i);
            inCMax = 1;
        }
    }

    *max = inMax;
    *cMin = inCMin;
    **min = inMin;
    **cMax = inCMax;
}