//
// Created by Jasiek on 27.12.2023.
//

#include <stdexcept>
#include "InformationSaver.h"
#include "FileSaver.h"
#include <iostream>
using namespace std;
InformationSaver::InformationSaver(): _indx(0)
{
    _voidT = new SimpleVarType(new Void);
    _stringT = new SimpleVarType(new Str);
    _intT = new SimpleVarType(new Int);
    _intA = new Ar(_intT, "x");
    _stringA = new Ar(_stringT, "x");
    _emptyListAr = new ListArg;
    _intListAr = new ListArg;
    _stringListAr = new ListArg;
    _intListAr->push_back(_intA);
    _stringListAr->push_back(_stringA);
}

InformationSaver::~InformationSaver()
{
    delete  _voidT;
    delete  _stringT;
    delete _intT;

    delete  _emptyListAr;
    delete  _intListAr;
    delete  _stringListAr;
}

bool InformationSaver::newFunc(const std::string & idx, Type * type,ListArg * ar)
{
    if(this->IfExists(idx))
    {
        return false;
    }
    functionsMap.emplace(idx,std::make_tuple(type,ar,localVariable{}));
    return true;
}
bool InformationSaver::newClass(const std::string & par,const std::string & idx)
{
    if(this->IfExists(idx))
    {
        return false;
    }
    classesMap.emplace(idx,std::make_tuple(par,classVariable{},classFunctions{}));
    classExistsMap.emplace(idx,false);
    return true;
}
bool InformationSaver::IfExistsClass(const std::string & str)
 {

  return
      classesMap.contains(str);
 }
bool InformationSaver::IfExists(const std::string & str)
{
    if(classesMap.contains(str) || functionsMap.contains(str))
    {
        return true;
    }
    return false;
}
void InformationSaver::lib()
{
    for(auto & v: Helper::libValues)
    {
        libMap.insert(v);
    }
    newFunc(Helper::libValues[0],_voidT,_intListAr);
    newFunc(Helper::libValues[1],_voidT,_stringListAr);
    newFunc(Helper::libValues[2],_voidT,_emptyListAr);
    newFunc(Helper::libValues[3],_intT,_emptyListAr);
    newFunc(Helper::libValues[4],_stringT,_emptyListAr);
}
void InformationSaver::newClassNulls()
{
  classParentsMap.insert(std::make_pair(Helper::nullName,std::set<std::string>{}));
     for(auto it : classesMap)
     {
        classParentsMap[Helper::nullName].insert(it.first);
     }
     for(auto it : classParentsMap)
     {
       for ( auto it2 : it.second)
         {
            cout << it.first << " " << it2 << endl;
         }
     }

}
bool InformationSaver::classPar(const std::string & par,const std::string & idx)
{
    if(classParentsMap.contains(idx))
    {
        auto it = classParentsMap.find(idx);
        if(it->second.contains(par))
        {
            return true;
        }
    }
    return false;
}
bool InformationSaver::InheritanceCorrectLoops()
{
    std::unordered_map<std::string,int> indexMap;
    std::vector<int> inher(classesMap.size(),-1);
    int ind{0};
    for(auto it = begin(classesMap); it != end(classesMap); it++)
    {
        indexMap.emplace(it->first,ind++);
    }
    for(auto it = begin(classesMap); it != end(classesMap); it++)
    {
        if(indexMap.contains(std::get<0>(it->second)))
        {
            if(std::get<0>(it->second) != "")
            {
                inher[indexMap.find(it->first)->second] = indexMap.find(std::get<0>(it->second))->second;
            }
        }
        else if(std::get<0>(it->second) != "")
        {
            std::string str = "\"" + it->first + "\"" + " doesn't have good defined ancestor class";
            FileSaver::GetInstance().addError(str,0);
        }
        std::vector<bool> vis(classesMap.size(),false);
        std::vector<bool> loop(classesMap.size(),false);
        for(int i = 0; i < classesMap.size();i++) {
            if (checkSingleLoop(i, inher, vis, loop)) {
                std::string str = "Cycles in inheritance of classes";
                FileSaver::GetInstance().addError(str,0);
            }
        }
    }
    return true;
}
bool InformationSaver::checkSingleLoop(int i, const std::vector<int> &inher,std::vector<bool> &vis, std::vector<bool> &loop)
{
    if(!vis[i])
    {
        vis[i] = true;
        loop[i] = true;
        if(inher[i] != -1)
        {
            if(!vis[inher[i]])
            {
                if(checkSingleLoop(inher[i],inher,vis,loop))
                {
                    return true;
                }
            }
            else if(loop[inher[i]])
            {
                return true;
            }
        }
    }
    loop[i] = false;
    return false;
}
bool InformationSaver::checkMain()
{
    auto it = functionsMap.find("main");
    if(it == functionsMap.end())
    {

        std::string str = "Main not found";
        FileSaver::GetInstance().addError(str,0);
        return false;
    }
    if(std::get<0>(it->second)->get() != Helper::intName)
    {

        std::string str = "Main has to return int.";
        FileSaver::GetInstance().addError(str,0);
    }
    if(!std::get<1>(it->second)->getTypes().empty())
    {

        std::string str = "Main can't take arguments.";
        FileSaver::GetInstance().addError(str,0);
    }
    return true;
}
bool InformationSaver::funLocalifExists(const std::string & str)
{
    return localMethodsMap.find(str) != localMethodsMap.end();

}
void InformationSaver::newMethodLocal(const std::string & str)
{
    localMethodsMap.insert(str);
}

bool InformationSaver::newClassMethod(const std::string & className, const std::string & name,Type *type, ListArg *ar)
{
    if(IfExists(name))
    {
        return false;
    }
    if(classesMap.contains(className))
    {
        auto ourClass  = classesMap.find(className);
        std::get<2>(ourClass->second).find(name);
        if(std::get<2>(ourClass->second).contains(name))
        {
            return false;
        }
        std::get<2>(ourClass->second).insert(std::make_pair(name,std::make_tuple(type,ar,className)));
        localMethodsMap.clear();
        return true;
    }
    return false;
}
bool InformationSaver::checkType(const std::string & str)
{
    if(!classesMap.contains(str) && str != Helper::intName && str != Helper::voidName &&
     str != Helper::boolName && str != Helper::stringName && str != Helper::boolTableName
      && str != Helper::stringTableName && str != Helper::intTableName)
  {
      if(str.length() > 2 && str.substr(str.length() - 2) == Helper::tableName)
      {
          if(classesMap.contains(str.substr(0,str.length() - 2)))
          {
              return true;
          }
      }

      return false;
  }
  return true;
}
bool InformationSaver::newClassVar(const std::string & className, const std::string & varName, const std::string &type)
{
    if(classesMap.contains(className))
    {
        for (const auto & var : std::get<1>(classesMap.find(className)->second))
        {
            if(var.first == varName)
            {
                return false;
            }
        }
        std::get<1>(classesMap.find(className)->second).emplace_back(varName,type);
        return true;
    }
    return false;
}
bool InformationSaver::ifClassExists(const std::string & str)
{
    if(classExistsMap.contains(str))
    {
        return classExistsMap.find(str)->second;
    }
    return false;
}
void InformationSaver::newClassExists(const std::string &str)
{
    if(classExistsMap.contains(str))
    {
        classExistsMap.find(str)->second = true;
    }
}
void InformationSaver::addSymbFromParent(const std::string & className, const std::string & parName)
{
    auto name = classesMap.find(className);
    auto par = classesMap.find(parName);
    for (const auto &v : std::get<1>(par->second))
    {
        std::get<1>(name->second).push_back(v);
    }
    for (const auto &v : std::get<2>(par->second))
    {
        std::get<2>(name->second).insert(v);
    }
}
void InformationSaver::newClassPars()
{
   for(const auto & name : classesMap)
   {
       classParentsMap.insert(std::make_pair(name.first,std::set<std::string>{}));
       newClassPars(name.first);
   }
}
void InformationSaver::newClassPars(const std::string & str)
{
    auto name = classesMap.find(str);
    auto par = classParentsMap.find(str);
    while(!std::get<0>(name->second).empty())
    {

        par->second.insert(std::get<0>(name->second));
        name = classesMap.find(std::get<0>(name->second));
    }
}
const std::unordered_map<std::string, functionVariable>& InformationSaver::getFunc()
{
    return functionsMap;
}
const std::unordered_map<std::string, classType>& InformationSaver::getClasses()
{
    return classesMap;
}
const localVariable& InformationSaver::getFuncLocals(const std::string &funName)
{
    if(functionsMap.contains(funName))
    {
        return std::get<2>(functionsMap.find(funName)->second);
    }
    throw std::invalid_argument("Function " + funName + " doesn't exists");

}
const classVariable& InformationSaver::getClassVars(const std::string &className)
{
    if(classesMap.contains(className))
    {
        return std::get<1>(classesMap.find(className)->second);
    }
    throw std::invalid_argument("Class " + className + " doesn't exists");
}
const std::unordered_map<std::string, std::string>& InformationSaver::getStrings()
{
    return stringsMap;
}
void InformationSaver::newString(const std::string & str)
{
    std::string s =  "loc_str_val$" + std::to_string(stringsMap.size());
    stringsMap.insert(std::make_pair(str,s));
}
const std::string& InformationSaver::getStringName(const std::string &str) {
    return stringsMap.find(str)->second;
}

bool InformationSaver::newParam(const std::string &funName, const std::string &locName, const std::string &type, int indx)
{
    if(functionsMap.contains(funName))
    {
        std::get<2>(functionsMap.find(funName)->second).push_back({locName,type,indx,true});
        return true;
    }
    return false;
}
bool InformationSaver::newParamLocal(const std::string &funName, const std::string &locName, const std::string &type, int indx)
{
    if(functionsMap.contains(funName))
    {
        std::get<2>(functionsMap.find(funName)->second).push_back({locName,type,indx,false});
        return true;
    }
    return false;
}
bool InformationSaver::isLib(const std::string &str)
{
    return libMap.contains(str);
}
std::string InformationSaver::getFuncType(const std::string &str)
{
    if(functionsMap.contains(str))
    {
        return std::get<0>(functionsMap.find(str)->second)->get();
    }
    throw std::invalid_argument("");
}
ListArg* InformationSaver::getFuncAr(const std::string &str)
{
    if(functionsMap.contains(str))
    {
        return std::get<1>(functionsMap.find(str)->second);
    }
    throw std::invalid_argument("");
}
std::string InformationSaver::getMethodType(const std::string &className, const std::string &name)
{
    if(classesMap.contains(className))
    {
        auto cls = classesMap.find(className);
        if(std::get<2>(cls->second).contains(name))
        {
            auto fun = std::get<2>(cls->second).find(name);
            return std::get<0>(fun->second)->get();

        }
        throw std::invalid_argument("Class \"" + className + "\"" + " doesn't contain \"" + name +"\"");
    }
    throw std::invalid_argument("Class \"" + className + "\"" + " doesn't exists");
}
ListArg* InformationSaver::getMethodAr(const std::string &className, const std::string &name)
{
    if(classesMap.contains(className))
    {
        auto cls = classesMap.find(className);
        if(std::get<2>(cls->second).contains(name))
        {
            auto fun = std::get<2>(cls->second).find(name);
            return std::get<1>(fun->second);

        }
        throw std::invalid_argument("Class \"" + className + "\"" + " doesn't contain \"" + name +"\"");
    }
    throw std::invalid_argument("Class \"" + className + "\"" + " doesn't exists");
}
const std::string& InformationSaver::getinWhichClassisMethod(const std::string &className, const std::string &name)
{
    if(classesMap.contains(className))
    {
        auto cls = classesMap.find(className);
        if(std::get<2>(cls->second).contains(name))
        {
            auto fun = std::get<2>(cls->second).find(name);
            return std::get<2>(fun->second);

        }
        throw std::invalid_argument("Class \"" + className + "\"" + " doesn't contain \"" + name +"\"");
    }
    throw std::invalid_argument("Class \"" + className + "\"" + " doesn't exists");
}
const std::string& InformationSaver::getVarinClassType(const std::string &className, const std::string &name)
{
    if(classesMap.contains(className))
    {
        auto cls = classesMap.find(className);
        for( const auto & v: std::get<1>(cls->second))
        {
            if(name == v.first)
            {
                return v.second;
            }
        }
        throw std::invalid_argument("Class \"" + className + "\"" + " doesn't contain \"" + name +"\"");
    }
    throw std::invalid_argument("Class \"" + className + "\"" + " doesn't exists");
}
std::string InformationSaver::newLabel()
{
    return ".L" + std::to_string(++_indx);
}
const std::tuple<std::string,int,bool,bool>& InformationSaver::ifSymbolExists( const symbolTab &t,const std::string & str)
{
    if(t.contains(str))
    {
        return t.find(str)->second;
    }
    static std::tuple<std::string,int,bool,bool> a("",0,false,false);
    return a;
}
bool InformationSaver::isSymReference(const std::string& str)
{
    for (auto it = symbVec.rbegin(); it != symbVec.rend(); ++it)
    {
        auto& symbol = ifSymbolExists(*it, str);

        if (!std::get<0>(symbol).empty())
        {
            return std::get<3>(symbol);
        }
    }
    std::string s = "Symbol \"" + str +"\" doesn't exists";
    throw std::invalid_argument(s.c_str());

}
bool InformationSaver::isSymInit(const std::string& str)
{
    for (auto it = symbVec.rbegin(); it != symbVec.rend(); ++it)
    {
        auto& symbol = ifSymbolExists(*it, str);

        if (!std::get<0>(symbol).empty())
        {
            return std::get<2>(symbol);
        }
    }
    std::string s = "Symbol \"" + str +"\" doesn't exists";
    throw std::invalid_argument(s.c_str());

}
int InformationSaver::getSymIndex(const std::string & str)
{
    for (auto it = symbVec.rbegin(); it != symbVec.rend(); ++it)
    {
        auto& symbol = ifSymbolExists(*it, str);

        if (!std::get<0>(symbol).empty())
        {
            return std::get<1>(symbol);
        }
    }
    std::string s = "Symbol \"" + str +"\" doesn't exists";
    throw std::invalid_argument(s.c_str());
}
const std::string& InformationSaver::getSymType(const std::string &str)
{
    for (auto it = symbVec.rbegin(); it != symbVec.rend(); ++it)
    {
        auto& symbol = ifSymbolExists(*it, str);

        if (!std::get<0>(symbol).empty())
        {

            return std::get<0>(symbol);
        }
    }
    std::string s = "Symbol \"" + str +"\" doesn't exists";
    throw std::invalid_argument(s.c_str());
}
void InformationSaver::restart()
{
    symbVec.clear();
    declMap.clear();
}
bool InformationSaver::newSym(const std::string & str, const std::string &t,bool init, bool ref)
{

    if(std::get<0>(ifSymbolExists(symbVec.back(),str)).empty())
    {
        int indx = 0;
        if(declMap.contains(str))
        {
            indx = ++(declMap.find(str)->second);
        }
        else
        {
            declMap.insert(std::make_pair(str,1));
            indx++;
        }
        symbVec.back().emplace(std::make_pair(str,std::make_tuple(t,indx,init,ref)));
        return true;
    }
    return false;
}
void InformationSaver::BlkEntry()
{
    symbVec.emplace_back();
}
void InformationSaver::BlkExit()
{
   symbVec.pop_back();
}
