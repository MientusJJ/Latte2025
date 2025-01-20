//
// Created by Jasiek on 28.12.2023.
//

#ifndef LATTE_HELPER_H
#define LATTE_HELPER_H
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include "Absyn.h"
using localVariable = std::vector<std::tuple<std::string, std::string, int, bool>>;
using classVariable = std::vector<std::pair<std::string, std::string>>;
using classFunctions = std::unordered_map<std::string, std::tuple<Type*, ListArg*, std::string>>;
using classType = std::tuple<std::string, classVariable , classFunctions>;
using functionVariable = std::tuple<Type*, ListArg*, localVariable>;
using localVariabletoOff = std::map<std::pair<std::string, int>, int>;
using classVariabletoOff= std::unordered_map<std::string, int>;
using symbolTab = std::unordered_map<std::string, std::tuple<std::string, int, bool>>;


namespace Helper {
    const std::vector<std::string> libValues{"printInt", "printString", "error", "readInt", "readString"};
    const std::string voidName = "void";
    const std::string nullName = "null";
    const std::string intName = "int";
    const std::string stringName = "string";
    const std::string boolName = "boolean";
    const std::string tableName = "[]";
    const std::string stringTableName = "string[]";
    const std::string intTableName = "int[]";
    const std::string boolTableName = "boolean[]";
    const std::string lengthName = "length";
    const std::string errorName = "error";
    const std::string selfName = "self";
    const std::string poplName = "  popl ";
    const std::string pushlName = "  pushl ";
    const std::string retName = "  ret";
    const std::string movlName = "  movl ";
}
enum class State
{
    null,
    Push,
    Pop,
    Ret,
    Label,
};
#endif //LATTE_HELPER_H

