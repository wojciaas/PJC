#include <iostream>
#include <vector>

void fMaxMin(std::vector<int*>vec, int **&max, int *&min, int **cMax, int *cMin);

std::vector<int> operator+ (std::vector<int> const &vec1, std::vector<int> const &vec2){
    return std::vector<int>{vec1.at(0) + vec2.at(0), vec1.at(vec1.size() - 1) + vec2.at(vec2.size() - 1)};
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

    int *pMaxHelp = &max;
    int **pMax = &pMaxHelp;
    int *pMin = &min;
    int *pCMax = &cMax;

    fMaxMin(vecP, pMax, pMin, &pCMax, &cMin);

    std::cout << "max -> " << max << std::endl;
    std::cout << "min -> " << min << std::endl;
    std::cout << "cMax -> " << cMax << std::endl;
    std::cout << "cMin -> " << cMin << std::endl;

    auto vecR = std::vector<int>{1, 2, 3} + std::vector<int>{2};
    auto vecR2 = std::vector<int>{1, 2, 3} + std::vector<int>{6, 2, 3, 4, 5, 6};

    for (auto &item : vecR)
        std::cout << item << " ";
    std::cout << std::endl;

    for (auto &item : vecR2)
        std::cout << item << " ";
    std::cout << std::endl;
}

void fMaxMin(std::vector<int*>vec, int **&max, int *&min, int **cMax, int *cMin){
    int inMax = *vec.at(0);
    int inMin = *vec.at(0);
    int inCMax = 1;
    int inCMin = 1;

    for (int i = 1; i < vec.size(); ++i) {

        if (*vec.at(i) == inMax)
            inCMax++;
        if (*vec.at(i) == inMin)
            inCMin++;

        if (*vec.at(i) > inMax){
            inMax = *vec.at(i);
            inCMax = 1;
        }
        if (*vec.at(i) < inMin){
            inMin = *vec.at(i);
            inCMin = 1;
        }
    }

    **max = inMax;
    *min = inMin;
    **cMax = inCMax;
    *cMin = inCMin;
}