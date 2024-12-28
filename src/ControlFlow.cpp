//
// Created by Jasiek on 28.12.2023.
//

#include <stdexcept>
#include "ControlFlow.h"
ControlFlow::ControlFlow() : termWhileBlk(false) {}
bool ControlFlow::FlowExists()
{
    for(int i = 0; i < simpleBlkVec.size();i++)
    {
        nonReachPoints(i);
        for(int j = 0; j < simpleBlkVec[i].size();j++)
        {
            if(retTVec[i] != Helper::voidName && simpleBlkVec[i][j].size() == 0 && !termVec[i][j] && reachVec[i][j])
            {
                std::string str = "\"" + funcNameVec[i].first + "\"" + " (line " + std::to_string(funcNameVec[i].second) + ")" +
                        " doesn't  have return statement in every path";
                throw std::invalid_argument(str);
            }
        }
    }
    return true;
}
void ControlFlow::nonReachPoints(int indx)
{
    reachVec[indx][0] = true;
    for(int i = 0; i < simpleBlkVec[indx].size(); i++)
    {
       for(const auto & v: simpleBlkVec[indx][i])
       {
           reachVec[indx][v] = true;
       }
    }
    if(termWhileBlk)
    {
        for( int i = whileBlk; i < reachVec[indx].size(); i++)
        {
            reachVec[indx][i] = false;
        }
    }
}
void ControlFlow::newFunc( const std::string &str, const std::string &ret,int line)
{
    simpleBlkVec.emplace_back();
    funcNameVec.emplace_back(str,line);
    retTVec.emplace_back(ret);
    termVec.emplace_back();
    reachVec.emplace_back();
    newBlk();
}
void ControlFlow::setClass(const std::string &str)
{
    currClass = str;
}
void ControlFlow::newInfLoop()
{
    infLoopVec.push_back(getCurrBlk());
}
void ControlFlow::endInfLoop()
{
    infLoopVec.pop_back();
}
void ControlFlow::newBlk()
{
    simpleBlkVec.back().emplace_back();
    termVec.back().emplace_back(false);
    reachVec.back().emplace_back(false);
    isIf = false;
}
std::string ControlFlow::getCurFunName()
{
    return funcNameVec.back().first;
}
std::string ControlFlow::getCurFunType()
{
    return retTVec.back();
}
std::string  ControlFlow::getCurClass()
{
    return currClass;
}
int ControlFlow::getCurrBlk()
{
    return simpleBlkVec.back().size()-1;
}
bool ControlFlow::getIsIf() { return isIf;}
void ControlFlow::newVirtBlock(int p1, int p2)
{
    virt_p1 = p1;
    virt_p2 = p2;
    isIf = true;
}
void ControlFlow::addMissBlk()
{
    newBlk();
    auto virtBlk = getCurrBlk();
    addNewNode(virt_p1,virtBlk);
    addNewNode(virt_p2,virtBlk);
    isIf = false;
}
void ControlFlow::addNewNode(int blk, int node)
{
    if(!termVec.back()[blk])
    {
        simpleBlkVec.back()[blk].emplace(node);
    }
}
bool ControlFlow::term(const std::string& str )
{
    termVec.back().back() = true;
    for (const auto &loop : infLoopVec)
    {
        termVec.back().at(loop) = true;
        whileBlk = loop < whileBlk ? loop : whileBlk;
        termWhileBlk = true;
    }

    if (str != retTVec.back() && !InformationSaver::GetInstance().classPar(retTVec.back(),str))
    {
        return false;
    }
    return true;
}