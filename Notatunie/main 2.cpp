#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fmt/ranges.h>
#include <cmath>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

// Notes created by Michał Woliński s29239

// Adding 5 to integer by reference
void add5(int &x){
    x += 5;
}

// Print vector no matter what type
void showVecAUTO(auto vec) {
    for (auto item: vec)
        fmt::print("{} ", item);
    fmt::print("\n");
}

// Print vector no matter what type using template
template<typename T>
void showAnyVec(std::vector<T> vec) {
    for (auto item: vec)
        fmt::print("{} ", item);
    fmt::print("\n");
}

struct Student{
    std::string name;
    int studentNumber;
    // Constructor
    Student(std::string name, int studentNumber) : name(name), studentNumber(studentNumber){
        fmt::print("I've created student :D\n");
    }

    // Copying constructor
    Student(Student const &otherStudent) : name("someName"), studentNumber(1337){
        fmt::print("I've copied student :D\n");
    }

    // Destructor
    ~Student(){
        fmt::print("I've destroyed student D:\n");
    }
};

struct Base {
    virtual void print() const {
        fmt::print("Heaven :D\n");
    }
};

struct Derived : Base {
    void print() const override {
        fmt::print("Hell :(\n");
    }
};

void callPrintFunction(Base const &obj) {
    obj.print();
}

void fMaxMin(const int *tab, const int size, int &max, int *min, int **cMax, int *&cMin){
    int cntMax = 0, cntMin = 0;
    for (int i = 0; i < size; ++i) {
        if(max < tab[i]){
            max = tab[i];
            cntMax = 0;
        }
        if(*min > tab[i]){
            *min = tab[i];
            cntMin = 0;
        }
        if(max == tab[i]){
            cntMax++;
        }
        if(*min == tab[i]){
            cntMin++;
        }
    }
    **cMax = cntMax;
    *cMin = cntMin;
}

//fMaxMin2
void fMaxMin(std::vector<int*> vec, int *max, int **min, int **&cMax, int *&cMin){
    int cntMax = 0, cntMin = 0, mini = *vec[0], maxi = *vec[0];
    for(int *i : vec){
        if(maxi < *i){
            maxi = *i;
            cntMax = 0;
        }
        if(mini > *i){
            mini = *i;
            cntMin = 0;
        }
        if(maxi == *i){
            cntMax++;
        }
        if(mini == *i){
            cntMin++;
        }
    }

    *max = maxi;
    **min = mini;
    **cMax = cntMax;
    *cMin = cntMin;
}

//3
void fMaxMin(std::vector<int*> vec, int **&max, int *&min, int **cMax, int *cMin){
    int maxi = *vec[0], mini = *vec[0], cntMax = 0, cntMin = 0;
    for(int *i : vec){
        if(maxi < *i){
            maxi = *i;
            cntMax = 0;
        }
        if(mini > *i){
            mini = *i;
            cntMin = 0;
        }
        if(maxi == *i){
            cntMax++;
        }
        if(mini == *i){
            cntMin++;
        }
    }
    **max = maxi;
    *min = mini;
    **cMax = cntMax;
    *cMin = cntMin;
}

template<typename T>
std::vector<T> operator+(const std::vector<T> &vec1, const std::vector<T> &vec2) {
    auto result = std::vector<T>();
    auto iterations = std::max(vec1.size(), vec2.size());
    for (size_t i = 0; i < iterations; ++i) {
        T value1 = (i < vec1.size()) ? vec1[i] : 0;
        T value2 = (i < vec2.size()) ? vec2[i] : 0;
        result.push_back(value1 + value2);
    }
    return result;
}

/*template<typename T>
std::vector<T> operator+(const std::vector<T> &vec1, const std::vector<T> &vec2) {
    auto result = std::vector<T>();
    int sum1 = 0, sum2 = 0;
    sum1 = vec1.front() + vec2.front();
    sum2 = vec1.back() + vec2.back();
    result.push_back(sum1);
    result.push_back(sum2);
    return result;
}*/

template<typename T>
std::vector<T> operator*(const std::vector<T> &vec1, const std::vector<T> &vec2) {
    auto result = std::vector<T>();
    int ilo1 = 0, ilo2 = 0;
    ilo1 = vec1.front() * vec2.front();
    ilo2 = vec1.back() * vec2.back();
    result.push_back(ilo1);
    result.push_back(ilo2);
    return result;
}

int main() {
    {
        const int size = 12;
        int a[size] = {1, 2, 1, 42, 2, 2, 42, 1, 1, 2, 1, 42};
        int max = a[0], min = a[0], cMax = 0, cMin = 0;
        int *pcMax = &cMax;
        int *pcMin = &cMin;
        fMaxMin(a, size, max, &min, &pcMax, *&pcMin);

        fmt::print("max -> {}\n", max);
        fmt::print("min -> {}\n", min);
        fmt::print("cMax -> {}\n", cMax);
        fmt::print("cMin -> {}\n", cMin);
    }

    {
        //fMaxMin2
        auto vec = std::vector<int>{1,2,1,42,2,2,42,1,1,2,1,42};
        auto vecP = std::vector<int*>();

        for(auto &item : vec){
            vecP.push_back(&item);
        }

        int max, min, cMax, cMin;

        int *pmin = &min; // adres min/pointer na min
        int *pcMax = &cMax; // pointer na cMax
        int **ppcMax = &pcMax; //pointer na pointer
        int *pcMin = &cMin; // pointer

        fMaxMin(vecP, &max, &pmin, ppcMax, pcMin);

        fmt::print("max {}\n", max);
        fmt::print("min {}\n", min);
        fmt::print("cmax {}\n", cMax);
        fmt::print("cmin {}\n", cMin);

        auto vec1 = std::vector<int>{1,2,3};
        auto vec2 = std::vector<int>{6,2,3,4,5,6};

        auto result = vec1 + vec2;
        fmt::print("{}", result);
    }

    {
        //3
        auto vec = std::vector<int>{1,2,1,42,2,2,42,1,1,2,1,42};
        auto vecP = std::vector<int*>();

        for(auto &item : vec){
            vecP.push_back(&item);
        }

        int max, min, cMax, cMin;

        int *pmax = &max;
        int **ppmax = &pmax;
        int *pmin = &min;
        int *pcMax = &cMax;

        fMaxMin(vecP, ppmax, pmin, &pcMax, &cMin);

        fmt::print("max {}\n", max);
        fmt::print("min {}\n", min);
        fmt::print("cmax {}\n", cMax);
        fmt::print("cmin {}\n", cMin);

        auto vec1 = std::vector<int>{1,2,3};
        auto vec2 = std::vector<int>{6,2,3,4,5,6};

        auto result = vec1 * vec2;
        fmt::print("{}", result);

        return 0;
    }

    {
        using namespace std;

        int x = 5;
        int* px = &x; //adres x
        int& rx = x; //alias na x
        int** ppx = &px;//adres px
        int*& rpx = px; //adres x

        cout << x << endl; //5
        cout << &x << endl; //@1 adres x
        cout << px << endl; //@1 adres x
        cout << &px << endl; //@2 adres px
        cout << *px << endl; //5
        cout << rx << endl; //5
        cout << &rx << endl; //@1 adres x
        cout << ppx << endl; //@2 adres px
        cout << &ppx << endl; //@3 adres na ppx
        cout << *ppx << endl; //@1
        cout << **ppx << endl; //5
        cout << rpx << endl; //@1
        cout << *rpx << endl; //5
        cout << &rpx << endl; //@1
    }
    // Struct
    {
        Student newStudent = {"Wlodzimierz", 50};
        auto copyOf = newStudent;

        fmt::print("\n ----------Polymorphism of methods--------- \n");
        auto b = Base();
        b.print();

        auto d = Derived();
        d.print();

        Base bd = Derived();
        bd.print();

        fmt::print("CPF\n");
        callPrintFunction(b);
        callPrintFunction(d);
        callPrintFunction(bd);
    }

    // VECTORS
    {
        std::vector<int> vec = {11,12,13,14,15,16,17,18,19,20,21};

        fmt::print("Whole vector: {}\n", vec);

        fmt::print("Middle element: {}\n", vec[vec.size()/2]);

        std::ranges::reverse(vec);
        fmt::print("Reversed vector: {}\n", vec);

        std::ranges::sort(vec);
        fmt::print("Sorted vector: {}\n", vec);

        vec.push_back(2137);
        fmt::print("Adding element to the end of the vector: {}\n", vec);

        vec.pop_back();
        fmt::print("Removing last element from the vector: {}\n", vec);

        vec.erase(vec.begin() + 3, vec.begin() + 5);
        fmt::print("Removing elements from index 3 to 5: {}\n", vec);

        fmt::print("Smallest element: {}\n", std::ranges::min(vec));

        fmt::print("Biggest element: {}\n", std::ranges::max(vec));

        vec = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
        auto toErase = std::ranges::unique(vec);
        vec.erase(toErase.begin(), toErase.end());
        fmt::print("Unique values in vector: {}\n", vec);

        // Creating vector using auto
        auto newVec = std::vector<std::string>();

        // Erases whole vector
        newVec.clear();
    }

    // LAMBDA
    {
        std::vector<int> vec = {11,12,13,14,15,16,17,18,19,20,21};

        // Counter of integers dividable by 2
        int counter = std::ranges::count_if(vec, [](int x) -> auto{return x % 2 == 0;});

        // Remove integer if dividable by 2
        std::ranges::remove_if(vec, [](int x) -> auto{return x % 2 == 0;});
        std::erase_if(vec, [](int x) -> auto{return x % 2 == 0;});

        // Reorders vector, elements dividable by 2 will be reordered to the beginning of vector
        std::ranges::partition(vec, [](int x) -> auto{return x % 2 == 0;});

        // Example of passing values to lambda expression
        auto biggerOne = [](double x, double y) -> int{
            if(x > y){
                return x;
            }else{
                return y; }
        };
        std::cout << "Which one is bigger as int: " << biggerOne(1.6, 7.2) << '\n';

        // Projection
        std::ranges::sort(vec, {}, [](int x)->int{
            return x % 10;
        });

        // Comparator
        std::ranges::sort(vec.begin(), vec.end(), [](int x, int y){
            if(x % 10 > y % 10){
                return false;
            }
            return true;
        });

    }

    // FILES
    {
        // Creating new file
        auto file = std::fstream("path");
        auto word = std::string();
        std::string line;

        // Iteration through every single line in file
        while(std::getline(file, line)){
            auto strStream = std::stringstream(line);
            // Passing one string at the time to *word*
            strStream >> word;

            // Writing into the file with out flag
            std::fstream new_file("somePathToFile", std::ios::out);
            while(strStream >> word){
                new_file << word << " ";
            }
        }

        // Iteration through every string, integer, whatever
        while(file >> word){

        }

    }

    // ITERATORS
    {
        std::vector<int> vec = {11,12,13,14,15,16,17,18,19,20,21};

        // Iterator of smallest element
        auto minEl = std::ranges::min_element(vec);

        // Iterator of biggest element
        auto maxEl = std::ranges::max_element(vec);

        // Iterator of desired element
        auto x = std::ranges::find(vec, 15);

        // Iterator of last element which returns true in lambda, also reorders just like std::ranges::partition
        auto lastEl = std::partition(vec.begin(), vec.end(),
                                            [](int x) -> auto{return x % 2 == 0;});

    }

    // SET
    {
        std::vector<int> vec = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};

        auto set = std::set<int>(vec.begin(), vec.end());
        fmt::print("Vector converted into set: {}\n", set);
    }

    // MAP
    {
        auto str = std::string("alamakota");
        auto occurrence = std::map<char, int>();
        for(auto letter : str)
            occurrence[letter] += 1;
        for(auto pair : occurrence)
            fmt::print("{} -> {}\n", pair.first, pair.second);
    }

    // REFERENCES
    {
        int x = 11;
        add5(x);
        std::cout << "X after void function add5: " << x << '\n';
    }

    // PREPROCESSORS
    {
        #define MAX

        #ifdef MAX
        #endif

        #ifndef MAX
        #error
        #endif
    }

    // ENUM
    {
        enum directions{
            up, down, left, right
        };
        auto direction = directions::left;
    }

    // CMATH
    {
        std::cout << "Square root of 169: " << sqrt(169) << "\n";
    }

    return 0;
}

// Notes created by Michał Woliński s29239