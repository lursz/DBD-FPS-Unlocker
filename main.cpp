#include <iostream>
#include "editor.h"

int main() {

    std::cout << "Select your platform of choice:" << std::endl << "1. Steam" << std::endl << "2. Epic Games Store" << std::endl;
    int choice = 0;
    switch (std::cin.get()) {
    case '1':
        choice = 1;
        std::cout << "Steam selected" << std::endl;
        break;
    case '2':
        choice = 2;
        std::cout << "Epic Games selected" << std::endl;
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        return 1;
    }

    Editor editor(choice);
    editor.EditEngineIniFile();
    editor.EditGameUserSettingsIniFile();

    std::cout << "Success!" << std::endl;
    return 0;
}