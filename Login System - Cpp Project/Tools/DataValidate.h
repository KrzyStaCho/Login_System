#pragma once
#include <exception>
#include <iostream>

class DataValidate {
    static bool isEmpty(const std::string& text);
    static bool haveOthersChar(const std::string& text, const std::string& collectionOfChar);
public:
    static void RemoveChar(std::string& text, const char& character);
    static std::string GetPartOfString(std::string& text, const char& separator);
    
    static int StringToInt(std::string& text);
    static float StringToFloat(std::string& text);
    static char GetOneCharacter(std::string& text, unsigned index = 0);

    static std::string IntToString(const int& number);
    static std::string FLoatToString(const float& number);

    static bool CheckMinMax(const int& number, const int& max, const int& min);
    static bool CheckMinMax(const float& number, const float& max, const float& min);
};

class DataValidateException : public std::exception {
public:
    DataValidateException() : exception("Error: DataValidate") {}
    DataValidateException(char const* const Message) : exception(Message) {}
};