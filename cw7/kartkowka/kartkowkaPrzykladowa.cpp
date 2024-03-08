#include "fmt/ranges.h"
#include <vector>
#include <algorithm>

struct Bot{
    std::string name;
    int birthYear;
    int level;

    Bot(std::string name, int birthYear, int level)
            : name(name), birthYear(birthYear), level(level){

    }

    Bot(Bot const &otherBot)
            : name(otherBot.name), birthYear(otherBot.birthYear), level(666){
    }
};

struct Pet{
    std::string name;
    int birthYear;
    Pet(std::string name, int birthYear)
        : name(name), birthYear(birthYear){}

    Pet(Pet const& otherPet)
        : name("Unix"), birthYear(1970){}
};

int main(){

    auto bots = std::vector<Bot> {
            Bot("bot2", 1992, 1),
            Bot("bot1", 2002, 2),
            Bot("bot3", 2010, 3),
            Bot("bot5", 2022, 4),
            Bot("bot4", 2023, 5),
    };

    auto copy = &bots.at(0);

    fmt::print("original: {}\ncopy:{}\n", bots.at(0).level, copy->level);

    std::vector<std::vector<std::string>> matrix = {
            {"One", "Two", "Three"},
            {"Four", "Five", "Six"},
            {"Seven", "Eight", "Nine"}
    };

    auto proj = [](std::vector<std::string>& first, std::vector<std::string>& second)->auto{
        return first.at(first.size() - 1).length() < second.at(second.size() - 1).length();
    };

    std::sort(matrix.begin(), matrix.end(), proj);

    fmt::print("{}\n", matrix);

    Pet zwierze = {"testowe", 1969}; fmt::print("{} -> {}\n", zwierze.name, zwierze.birthYear);
    auto kopia = zwierze;
    fmt::print("{} -> {}\n", kopia.name, kopia.birthYear);

    auto pets = std::vector<Pet>{
        Pet("pies", 2000),
        Pet("kot", 1990),
        Pet("waz", 1980),
        Pet("kura", 2010),
        Pet("dinozaur", 50)
    };
    auto najstarsze = std::ranges::max_element(pets, [](Pet& pet, Pet& other){ return pet.birthYear > other.birthYear; });
    fmt::print("{} -> {}", najstarsze->name, najstarsze->birthYear);

    auto strings = std::vector<std::string>{
            "one", "two", "three", "four", "five", "six", "seven"
    };

    std::sort(strings.begin(), strings.end());
    fmt::print("{}\n", strings);

    auto comparator = [] (std::string left, std::string right){
        return left.size() < right.size();
    };

    std::sort(strings.begin(), strings.end(), comparator);
    fmt::print("{}\n", strings);

}