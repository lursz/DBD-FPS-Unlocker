#ifndef _EDITOR_H
#define _EDITOR_H
#include <iostream>

class Editor
{
private:
    std::string folder_path;
    std::string engine_path;
    std::string game_user_path;
    std::string engine_ini_command;

public:
    Editor(int choice);
    ~Editor();

    void makeFileReadOnly(const std::string &filePath);
    void EditEngineIniFile();
    void EditGameUserSettingsIniFile();
};
#endif // EDITOR_H