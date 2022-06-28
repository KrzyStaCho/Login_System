#pragma once
#include <iostream>

class IO_Console {
public:
    static std::string GetText(std::string prefixText = "", bool allLine = false);
    static void PushText(const std::string& text, bool newLine = false);
    static void PushArray(std::string textTab[], int n, bool eachNewLine = false);
};
