//
// Created by Jasiek on 27.12.2023.
//

#ifndef LATTE_INFORMATIONSAVER_H
#define LATTE_INFORMATIONSAVER_H

#include <set>
#include "Helper.h"

class InformationSaver {
private:
 InformationSaver();
 Type * _voidT;
 Type * _stringT;
 Type * _intT;

 Arg * _intA;
 Arg * _stringA;

 ListArg * _emptyListAr;
 ListArg * _intListAr;
 ListArg * _stringListAr;
 int _indx;
 std::unordered_map<std::string, std::set<std::string>> classParentsMap;
 std::unordered_map<std::string, classType> classesMap;
 std::unordered_map<std::string, std::string> stringsMap;
 std::set<std::string> libMap;
 std::set<std::string> localMethodsMap;
 std::unordered_map<std::string, bool> classExistsMap;
 std::unordered_map<std::string, functionVariable> functionsMap;
 bool checkSingleLoop(int i, const std::vector<int> &inher,std::vector<bool> &vis, std::vector<bool> &loop);
 std::vector<symbolTab> symbVec;
 std::unordered_map<std::string, int> declMap;
 const std::tuple<std::string,int,bool,bool> &ifSymbolExists( const symbolTab &t,const std::string & str);
public:
    void lib();
    InformationSaver(InformationSaver & ) = delete;
    InformationSaver & operator=(const InformationSaver&) = delete;
    ~InformationSaver();
    bool IfExists(const std::string &);
    static InformationSaver& GetInstance()
    {
        static InformationSaver _informationSaver;
        return _informationSaver;

    }
    decltype(auto) getParents()
    {
        return classParentsMap;
    }
    bool newFunc(const std::string & idx, Type * type,ListArg * ar);
    bool newClass(const std::string & par,const std::string & idx);
    bool classPar(const std::string & par,const std::string & idx);
    bool InheritanceCorrectLoops();
    bool checkMain();

    bool checkType(const std::string & str);
    bool funLocalifExists(const std::string & str);
    bool ifClassExists(const std::string & str);
    bool isLib(const std::string &str);
    bool newParam(const std::string &funName, const std::string &locName, const std::string &type, int indx);
    bool newParamLocal(const std::string &funName, const std::string &locName, const std::string &type, int indx);
    void newMethodLocal(const std::string & str);
    void newClassExists(const std::string &str);
    bool newClassMethod(const std::string & className, const std::string & name,Type *type, ListArg *ar);
    bool newClassVar(const std::string & className, const std::string & varName, const std::string &type);
    const std::unordered_map<std::string, functionVariable>& getFunc();
    void addSymbFromParent(const std::string & className, const std::string & parName);
    void newClassPars();
    void newClassPars(const std::string & str);
    const std::unordered_map<std::string, classType>& getClasses();
    const std::unordered_map<std::string, std::string>& getStrings();
    const localVariable& getFuncLocals(const std::string &funName);
    const classVariable &getClassVars(const std::string &className);
    void newString(const std::string & str);
    void newClassNulls();
    const std::string& getStringName(const std::string &str);
    bool IfExistsClass(const std::string & str);
    std::string getFuncType(const std::string &str);
    ListArg* getFuncAr(const std::string &str);
    std::string getMethodType(const std::string &className, const std::string &name);
    ListArg* getMethodAr(const std::string &className, const std::string &name);
    const std::string& getinWhichClassisMethod(const std::string &className, const std::string &name);
    const std::string& getVarinClassType(const std::string &className, const std::string &name);
    std::string newLabel();
    bool isSymReference(const std::string& str);
    bool isSymInit(const std::string& str);
    int getSymIndex(const std::string & str);
    const std::string& getSymType(const std::string &str);
    void restart();
    bool newSym(const std::string & str, const std::string &t,bool init, bool ref = false);
    void BlkEntry();
    void BlkExit();
};


#endif //LATTE_INFORMATIONSAVER_H
