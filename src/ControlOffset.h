//
// Created by Jasiek on 30.12.2023.
//

#ifndef LATTE_CONTROLOFFSET_H
#define LATTE_CONTROLOFFSET_H


#include <unordered_map>
#include <string>
#include "Helper.h"
#include <stdexcept>
#include "InformationSaver.h"
class ControlOffset {
private:
    ControlOffset() = default;
    void newClassOffs(const std::string &str);
    void newPtrs(const std::string &str);
    std::unordered_map<std::string, localVariabletoOff> functionsMap;
    std::unordered_map<std::string, classVariabletoOff> classVarMap;
    std::unordered_map<std::string, int> bytesAllocMap;
    std::unordered_map<std::string, int> classSizeOfMap;
public:
    ControlOffset(const ControlOffset &) = delete;
    ControlOffset& operator=(const ControlOffset &) = delete;
    static ControlOffset & GetInstance()
    {
        static ControlOffset _controlOffset;
        return _controlOffset;
    }
    int getPtr(const std::string &funName, const std::string &nameLoc, int indx);
    int getBytesAlloc(const std::string &funName) ;
    int getClassOffset(const std::string &className, const std::string &varName);
    int getSizeofClass(const std::string &className);
    void newPtrs();
    void newClassOffs();

};


#endif //LATTE_CONTROLOFFSET_H
