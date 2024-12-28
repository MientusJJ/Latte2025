//
// Created by Jasiek on 30.12.2023.
//


#include "ControlOffset.h"
int ControlOffset::getPtr(const std::string &funName, const std::string &nameLoc, int indx)
{
    if(functionsMap.contains(funName))
    {
        return functionsMap.find(funName)->second.find(std::make_pair(nameLoc,indx))->second;
    }
    return 0;
}
int ControlOffset::getBytesAlloc(const std::string &funName)
{
    if(bytesAllocMap.contains(funName))
    {
        return bytesAllocMap.find(funName)->second;
    }
    return 0;
}
int ControlOffset::getClassOffset(const std::string &className, const std::string &varName)
{
    if(classVarMap.contains(className))
    {
        return classVarMap.find(className)->second.find(varName)->second;
    }
    return 0;
}
int ControlOffset::getSizeofClass(const std::string &className)
{
    if(classSizeOfMap.contains(className))
    {
        return classSizeOfMap.find(className)->second;
    }
    return 0;
}
void ControlOffset::newPtrs()
{
  auto &funcs = InformationSaver::GetInstance().getFunc();
  for (auto &v : funcs)
  {
      functionsMap.insert(std::make_pair(v.first,localVariabletoOff{}));
      bytesAllocMap.insert(std::make_pair(v.first,0));
      newPtrs(v.first);
  }
}
void ControlOffset::newClassOffs()
{
    auto &classes = InformationSaver::GetInstance().getClasses();
    for (auto &v : classes)
    {
        classVarMap.insert(std::make_pair(v.first,classVariabletoOff {}));
        classSizeOfMap.insert(std::make_pair(v.first,0));
        newClassOffs(v.first);
    }
}
void ControlOffset::newPtrs(const std::string &str)
{
    int args_pos = 8;
    int local_pos = -4;
    if(functionsMap.contains(str))
    {
        auto fun = functionsMap.find(str);
        auto &funLocal = InformationSaver::GetInstance().getFuncLocals(fun->first);
        for( auto &v : funLocal)
        {
            if(std::get<3>(v))
            {
                fun->second.insert(std::make_pair(std::make_pair(std::get<0>(v),std::get<2>(v)),args_pos));
                args_pos+=4;
            }
            else
            {
                fun->second.insert(std::make_pair(std::make_pair(std::get<0>(v),std::get<2>(v)),local_pos));
                local_pos -= 4;
                bytesAllocMap.find(str)->second +=4;

            }
        }
        return;
    }
    throw std::invalid_argument("Function " + str + " doesn't exists");
}
void ControlOffset::newClassOffs(const std::string &str)
{
    int oS = 0;
    if(classVarMap.contains(str))
    {
        auto cls = classVarMap.find(str);
        auto classVars = InformationSaver::GetInstance().getClassVars(cls->first);
        auto classOS = classSizeOfMap.find(str);
        oS = 0;
        for(const auto & v : classVars)
        {
            cls->second.insert(std::make_pair(v.first,oS));
            classOS->second +=4;
            oS+=4;
        }
        return;
    }
    throw std::invalid_argument("Class " + str + " doesn't exists");
}