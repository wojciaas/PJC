#include "fmt/ranges.h"
#include <algorithm>
#include <vector>

struct Student{
    std::string name;
    std::string surname;
    int studentNumber;

    Student(std::string name, std::string surname, int studentnNumber)
            : name(name), surname(surname), studentNumber(studentnNumber){}
};

int main(){
    auto students = std::vector<Student>{
        Student("Jan", "Kowalski", 12324),
        Student("Arkadiusz", "Glowacki", 53112),
        Student("Juan", "Zan", 53232),
        Student("Ben", "Swolo", 94722),
        Student("Ben", "Masny", 93822)
    };

    fmt::print("Zadanie 1\n\n");

    fmt::print("Studenci posortowani wg imion rosnaco\n");
    auto comp = [](Student const &stud1, Student const &stud2){
        return stud1.name < stud2.name;
    };
    std::ranges::sort(students, comp);
    for(auto stud : students)
        fmt::print("{}\n", stud.name);

    fmt::print("\nStudenci posortowani wg numerow indeksow malejaco\n");
    std::ranges::sort(students, [](Student const &stud1, Student const &stud2){
        return stud1.studentNumber > stud2.studentNumber;
    });
    for(auto stud : students)
        fmt::print("{}\n", stud.studentNumber);

    fmt::print("\nStudenci posortowani alfabetycznie wg ostatniej litery nazwiska\n");
    std::ranges::sort(students, {},[](Student const &stud)->auto{
        return stud.surname.at(stud.surname.size() - 1);
    });
    for(auto stud : students)
        fmt::print("{}\n", stud.surname);
    return 0;
}