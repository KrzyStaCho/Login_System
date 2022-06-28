#pragma once
#include <iostream>

class MainProgram {
    static std::string PathToFile;
    static void GetDataFromUser(std::string& username, std::string& password);
    static std::string PreparateData(const std::string& username, const std::string& password);
public:
    static void RunProgram();
};
