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
    engine_ini_command = "[/script/engine.engine]\nbSmoothFrameRate=false\nMinSmoothedFrameRate=5\nMaxSmoothedFrameRate=240\nbUseVSync=false\n";
    /* -------------------------------------------------------------------------- */
    // get %appdata% path
    folder_path = getenv("APPDATA");
    folder_path.erase(folder_path.length() - 8, 8);
    // append the rest of the path
    if (choice == 2)
        folder_path += epic_path;
    else if (choice == 1)
        folder_path += steam_path;
    engine_path = folder_path + "Engine.ini";
    game_user_path = folder_path + "GameUserSettings.ini";
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
    if (!engineFile.is_open())
        std::cerr << "Failed to open file for writing: " << engine_path << std::endl;
    
    // Place the command
    engineFile << engine_ini_command;
    engineFile.close();

    // Make the file read only
    makeFileReadOnly(engine_path);
}

void Editor::EditGameUserSettingsIniFile()
{
    std::ifstream iFile(game_user_path);
    if (!iFile.is_open())
    {
        std::cerr << "Failed to open file for reading: " << game_user_path << std::endl;
        return;
    }

    // Read the file
    std::string line;
    std::string modifiedContent;
    while (std::getline(iFile, line))
    {
        if ((line.find("FPSLimit=30") != std::string::npos) || (line.find("FPSLimit=60") !=std::string::npos))
            line = "FPSLimit=500";
        modifiedContent += line + "\n";
    }
    iFile.close();

    // Save to the file
    std::ofstream oFile(game_user_path);
    if (!oFile.is_open())
    {
        std::cerr << "Failed to open file for writing: " << game_user_path << std::endl;
        return;
    }

    oFile << modifiedContent;
    oFile.close();

    // Make the file read only
    makeFileReadOnly(game_user_path);
}