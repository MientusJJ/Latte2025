//
// Created by Jasiek on 03.01.2024.
//

#ifndef LATTE_CLEARCODE_H
#define LATTE_CLEARCODE_H
#include <string>
#include <fstream>
#include "Helper.h"
class ClearCode {
private:
    std::string prev;
    std::ifstream infile;
    std::ofstream out;
    std::string inFileName;
    std::string outFileName;
    State innerState;
    std::string checkPush(std::string s);
    std::string checkPop(std::string s);
    std::string pushCut(std::string s);
    std::string popCut(std::string s);
    std::string prevCut(std::string s);
public:
    void start(const std::string &input,const std::string &output);
    void endik();
    ClearCode();
    void exec();

};


#endif //LATTE_CLEARCODE_H
