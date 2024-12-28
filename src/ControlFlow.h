//
// Created by Jasiek on 28.12.2023.
//

#ifndef LATTE_CONTROLFLOW_H
#define LATTE_CONTROLFLOW_H


#include <vector>
#include <string>
#include <unordered_set>
#include "Helper.h"
#include "InformationSaver.h"
class ControlFlow
{
private:
    ControlFlow();
    std::vector<std::vector<bool>> reachVec;
    int whileBlk;
    bool termWhileBlk;
    std::vector<std::vector<bool>> termVec;
    std::vector<std::string> retTVec;
    std::vector<int> infLoopVec;
    std::string currClass;
    int virt_p1,virt_p2;
    bool isIf;
    std::vector<std::vector<std::unordered_set<int>>> simpleBlkVec;
    std::vector<std::pair<std::string, int>> funcNameVec;
public:
    static ControlFlow& getInstance() {
        static ControlFlow instance;
        return instance;
    }
    void newFunc(const std::string &str, const std::string &ret,int line);
    void nonReachPoints(int indx);
    ControlFlow(ControlFlow & ) = delete;
    ControlFlow & operator=(const ControlFlow&) = delete;
    bool FlowExists();
    void setClass(const std::string &str);
    void newInfLoop();
    bool getIsIf();
    void setMissingBlock();
    void endInfLoop();
    std::string getCurFunName();
    std::string getCurFunType();
    std::string getCurClass();
    int getCurrBlk();
    void newVirtBlock(int p1,int p2);
    void newBlk();
    bool term(const std::string& str );
    void addNewNode(int blk, int node);
    void addMissBlk();
};


#endif //LATTE_CONTROLFLOW_H
