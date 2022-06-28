#include "DataValidate.h"
#include <string>
using namespace std;

bool DataValidate::isEmpty(const std::string& text) {
    return empty(text);
}

bool DataValidate::haveOthersChar(const string& text, const string& collectionOfChar) {
    return text.find_first_not_of(collectionOfChar) != string::npos;
}

void DataValidate::RemoveChar(string& text, const char& character) {
    text.erase(remove(text.begin(), text.end(), character), text.end());
}

string DataValidate::GetPartOfString(string& text, const char& separator) {
    if (isEmpty(text)) throw DataValidateException("DataValidate: Data is empty");
    string partOfText = text.substr(0, text.find(separator));
    text.erase(0, text.find(separator) + 1);
    return partOfText;
}

int DataValidate::StringToInt(string& text) {
    RemoveChar(text, ' ');
    if (isEmpty(text)) throw DataValidateException("DataValidate: Data is empty");
    if (haveOthersChar(text, "1234567890")) throw DataValidateException("DataValidate: Incorrect data");
    return stoi(text);
}

float DataValidate::StringToFloat(string& text) {
    RemoveChar(text, ' ');
    if (isEmpty(text)) throw DataValidateException("DataValidate: Data is empty");
    if (haveOthersChar(text, "1234567890.")) throw DataValidateException("DataValidate: Incorrect data");
    return stof(text);
}

char DataValidate::GetOneCharacter(string& text, unsigned index) {
    RemoveChar(text, ' ');
    if (isEmpty(text)) throw DataValidateException("DataValidate: Data is empty");
    return text[0];
}

string DataValidate::IntToString(const int& number) {
    return to_string(number);
}

string DataValidate::FLoatToString(const float& number) {
    return to_string(number);
}

bool DataValidate::CheckMinMax(const int& number, const int& max, const int& min) {
    return number >= min && number <= max;
}

bool DataValidate::CheckMinMax(const float& number, const float& max, const float& min) {
    return number >= min && number <= max;
}