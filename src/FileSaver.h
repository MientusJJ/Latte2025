//
// Created by Jasiek on 27.12.2023.
//

#ifndef LATTE_FILESAVER_H
#define LATTE_FILESAVER_H

#include <fstream>
#include <vector>

class FileSaver {
private:
    FileSaver() = default;
    std::ofstream _of;
    std::string _name="";
    std::string _program="";
    std::vector<std::string> errorsVec;
    void openFile();
public:

    FileSaver(FileSaver & ) = delete;
    FileSaver & operator=(const FileSaver&) = delete;
    void toFile();
    void Addline(const std::string & str);
    void OneLine(const std::string & str,bool clear = false);
    void endik();
    void start(const std::string &name);
    void addError(const std::string &,int);
    bool printAllErrors();
    void printOk();
    static FileSaver& GetInstance()
    {
        static FileSaver _informationSaver;
        return _informationSaver;

    }
    std::pair<std::string,std::pair<std::string,std::string>> NameOfFile(const std::string &in, const std::string &endik);
};


#endif //LATTE_FILESAVER_H
