#include "editor.h"
#include <fstream>
#include <string>
#include <windows.h>

Editor::Editor(int choice)
{
    /* -------------------------------------------------------------------------- */
    /*                                DATA TO EDIT                                */
    /* -------------------------------------------------------------------------- */
    std::string steam_path = "\\Local\\DeadByDaylight\\Saved\\Config\\WindowsNoEditor\\";
    std::string epic_path = "\\Local\\DeadByDaylight\\Saved\\Config\\EGS\\";
    std::string engine_ini_command = "[/script/engine.engine]\nbSmoothFrameRate=false\nMinSmoothedFrameRate=5\nMaxSmoothedFrameRate=240\nbUseVSync=false\n";
    /* -------------------------------------------------------------------------- */

    folder_path = getenv("APPDATA");
    if (choice == 2)
        folder_path += epic_path;
    else if (choice == 1)
        folder_path += steam_path;
    engine_path = folderpath + "Engine.ini";
    game_user_path = folderpath + "GameUserSettings.ini";
}
Editor::~Editor() {}



void Editor::makeFileReadOnly(const std::string &filePath)
{
    if (!SetFileAttributes(filePath.c_str(), FILE_ATTRIBUTE_READONLY))
        std::cerr << "Failed to set file as read-only: " << filePath << std::endl;
}

void Editor::EditEngineIniFile()
{
    std::ofstream engineFile(engine_path, std::ios_base::app);

    // Place the command
    if (!engineFile.is_open())
        std::cerr << "Failed to open file for writing: " << engine_path << std::endl;
    engineFile << engine_ini_command;
    engineFile.close();

    // Make the file read only
    makeFileReadOnly(engine_path);
}

void Editor::EditGameUserSettingsIniFile()
{
    std::ifstream userFile(game_user_path);
    if (!userFile.is_open())
    {
        std::cerr << "Failed to open file for reading: " << game_user_path << std::endl;
        return;
    }

    // Read the file
    std::string line;
    std::string modifiedContent;
    while (std::getline(userFile, line))
    {
        if (line.find("FPSLimit = 30") != std::string::npos)
        {
            line = "FPSLimit = 500";
        }
        modifiedContent += line + "\n";
    }
    userFile.close();

    // Save to the file
    std::ofstream userFile(game_user_path);
    if (!userFile.is_open())
    {
        std::cerr << "Failed to open file for writing: " << game_user_path << std::endl;
        return;
    }

    userFile << modifiedContent;
    userFile.close();

    // Make the file read only
    makeFileReadOnly(game_user_path);
}