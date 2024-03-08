#include <fmt/ranges.h>
#include <map>
#include <vector>
#include <random>
#include <algorithm>

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

    auto studGrades = std::map<int, std::vector<int>>();

    for (auto stud : students) {
        for (int i = 0; i < 10; ++i) {
            auto dev = std::random_device();
            std::mt19937 rng(dev());
            auto dist = std::uniform_int_distribution<std::mt19937::result_type>(1,6);
            int grade = dist(dev);
            studGrades[stud.studentNumber].push_back(grade);
        }
    }
    auto proj = [](std::vector<int> const &V){
        double avg = 0;
        for(int grade : V)
            avg += grade;
        return avg/V.size();
    };
//    auto maxAvg = std::ranges::max_element(studGrades.begin()->second,studGrades.end()->second, [](std::vector<int> const &V){
//        double avg = 0;
//        for(int grade : V)
//            avg += grade;
//        return avg/V.size();
//    });
    //auto studWithHighestAvg = std::ranges::find(students, );
    return 0;
}