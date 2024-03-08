#include <fmt/chrono.h>
#include <iostream>
#include <map>
#include "FileManager.h"
#pragma once

class CommandHandler {
public:
    CommandHandler();
    auto run() -> void;
private:
    FileManager fileManager;
    int option;
    auto fileManagerInstructions() -> void;
    auto passwordManagerInstructions() -> void;
    auto listCategories() -> void;
};