#include "IO_File.h"
#include <fstream>
#include <string>
using namespace std;

unsigned IO_File::CountLine(const string& path) {
    string line;
    unsigned counter = 0;
    ifstream mFile(path);

    if (!mFile.is_open()) throw IO_FileException("IO_File: Couldnt open file");
    while (mFile.peek() != EOF) {
        getline(mFile, line);
        ++counter;
    } mFile.close();

    return counter;
}

string IO_File::GetLine(const string& path, unsigned numberOfLine) {
    if (CountLine(path) < numberOfLine) throw IO_FileException("IO_File: Incorrect number of line");
    unsigned counter = 0;
    string line;
    ifstream mFile(path);

    if (!mFile.is_open()) throw IO_FileException("IO_File: Couldnt open file");
    while (counter < numberOfLine) {
        getline(mFile, line);
        ++counter;
    } mFile.close();

    return line;
}

std::string* IO_File::GetAllLine(const string& path) {
    const unsigned numberOfLine = CountLine(path);
    if (numberOfLine == 0) throw IO_FileException("IO_File: File is empty");

    auto* lineTab = new string[numberOfLine];
    ifstream mFile(path);

    if (!mFile.is_open()) throw IO_FileException("IO_File: Couldnt open file");
    for (int i = 0; mFile.peek() != EOF; i++) {
        getline(mFile, lineTab[i]);
    } mFile.close();

    return lineTab;
}

void IO_File::SaveLine(const string& path, const string& line, bool saveOldData, bool newLine) {
    ofstream mFile;
    
    if (saveOldData) mFile.open(path, ios_base::app);
    else mFile.open(path);

    mFile << line;
    if (newLine) mFile << endl;
}

void IO_File::SaveArray(const string& path, const string tab[], unsigned n, bool saveOldData, bool newLIne) {
    for (unsigned i = 0; i < n; i++) {
        SaveLine(path, tab[i], saveOldData, newLIne);
    }
}