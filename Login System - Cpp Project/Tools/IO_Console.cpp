#include "IO_Console.h"
#include <string>
using namespace std;

string IO_Console::GetText(string prefixText, bool allLine) {
    string text;
    
    cout << prefixText;
    if (allLine) {
        cin.ignore(256, '\n');
        getline(cin, text);
    }
    else cin >> text;

    return text;
}

void IO_Console::PushText(const std::string& text, bool newLine) {
    cout << text;
    if (newLine) cout << endl;
}

void IO_Console::PushArray(std::string textTab[], int n, bool eachNewLine) {
    for (int i = 0; i < n; i++) {
        PushText(textTab[i], eachNewLine);
    }
}