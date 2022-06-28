#include "MainProgram.h"
#include "Tools/DataValidate.h"
#include "Tools/IO_Console.h"
#include "Tools/IO_File.h"
using namespace std;

string MainProgram::PathToFile = "D://ProgramFile.txt";

void MainProgram::GetDataFromUser(string& username, string& password) {
    IO_Console::PushText("=======Logowanie=======", true);
    username = IO_Console::GetText("Podaj login: ");
    password = IO_Console::GetText("Podaj haslo: ");
    IO_Console::PushText("=======================", true);
}

string MainProgram::PreparateData(const string& username, const string& password) {
    string str = username + ';' + DataValidate::Hash(password);
    return str;
}

void MainProgram::RunProgram() {
    string Username, Password;
    GetDataFromUser(Username, Password);
    string line = PreparateData(Username, Password);
    unsigned index = IO_File::FindLine(PathToFile, line);
    if (index != 0) { IO_Console::PushText("Jestes zalogowany", true); return;}
    IO_Console::PushText("Nie ma cie w bazie danych. Czy chcesz sie wpisac? [Y/N]");
    string odp = IO_Console::GetText();
    if (odp != "Y") return;
    IO_File::SaveLine(PathToFile, line, true, true);
    IO_Console::PushText("Zostales zapisany", true);
}

int main() {
    try {
        MainProgram::RunProgram();
    } catch (exception& e) {
        cout << e.what();
    }
}