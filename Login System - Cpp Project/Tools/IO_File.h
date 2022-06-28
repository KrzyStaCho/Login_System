#pragma once
#include <iostream>
#include <exception>

class IO_File {
public:
    static unsigned CountLine(const std::string& path);
    static std::string GetLine(const std::string& path, unsigned numberOfLine);
    static std::string* GetAllLine(const std::string& path);
    static unsigned FindLine(const std::string& path, const std::string& line);
    static void SaveLine(const std::string& path, const std::string& line, bool saveOldData = false, bool newLine = false);
    static void SaveArray(const std::string& path, const std::string tab[], unsigned n, bool saveOldData = false, bool newLIne = false);
};

class IO_FileException : public std::exception {
public:
    IO_FileException() : exception("Error: IO_File") {}
    IO_FileException(char const* const Message) : exception(Message) {}
};