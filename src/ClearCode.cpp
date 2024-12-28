//
// Created by Jasiek on 03.01.2024.
//

#include "ClearCode.h"
ClearCode::ClearCode() : innerState(State::null), prev("") {}
void ClearCode::start(const std::string &input,const std::string &output)
{
    this->inFileName = input;
    this->outFileName = output;
    infile.open(inFileName);
    out.open(output);
}
void ClearCode::endik()
{
    infile.close();
    out.close();
    remove(inFileName.c_str());
}

void ClearCode::exec()
{
    std::string line;
    bool start = false;
    bool text = false;
    while (std::getline(infile, line))
    {
        if (!start && !text && !line.empty() && line == ".text")
            text = true;

        if (!start && text && !line.empty() && line.at(0) != '.')
            start = true;
        else if (!start)
            out << line << "\n";

        if (!start)
            continue;
        switch (innerState)
        {
            case State::null:
            {
                if (checkPush(line) == Helper::pushlName)
                {
                    innerState = State::Push;
                    prev = pushCut(line);
                }
                else if (checkPop(line) == Helper::poplName)
                {
                    innerState = State::Pop;
                    prev = popCut(line);
                }
                else if (line == Helper::retName)
                {
                    innerState = State::Ret;
                    out << line << "\n";
                }
                else if (!line.empty() && line.at(0) == '.')
                {
                    innerState = State::Label;
                    prev = prevCut(line);
                }
                else
                {
                    out << line << "\n";
                }

                break;
            }
            case State::Pop:
            {
                if (checkPush(line) == Helper::pushlName)
                {
                    auto new_name = pushCut(line);

                    if (prev != new_name)
                    {
                        out << Helper::poplName + prev << "\n";
                        innerState = State::Push;
                        prev = pushCut(line);
                    }
                    else
                    {
                        innerState = State::null;
                    }
                }
                else if (checkPop(line) == Helper::poplName)
                {
                    out << Helper::poplName + prev << "\n";
                    innerState = State::Pop;
                    prev = popCut(line);
                }
                else if (line == Helper::retName)
                {
                    innerState = State::Ret;
                    out << line << "\n";
                }
                else if (!line.empty() && line.at(0) == '.')
                {
                    out << Helper::poplName + prev << "\n";
                    innerState = State::Label;
                    prev = prevCut(line);
                }
                else
                {
                    out << Helper::poplName + prev << "\n";
                    out << line << "\n";
                    innerState = State::null;
                }
                break;
            }
            case State::Push:
            {
                if (checkPush(line) == Helper::pushlName)
                {
                    out << Helper::pushlName + prev << "\n";
                    innerState = State::Push;
                    prev = pushCut(line);
                }
                else if (checkPop(line) == Helper::poplName)
                {
                    auto new_name = popCut(line);

                    if (prev != new_name)
                    {
                        out << Helper::movlName + prev + ", " + new_name + "\n";
                        innerState = State::null;
                        prev = "";
                    }
                    else
                    {
                        innerState = State::null;
                    }
                }
                else if (line == Helper::retName)
                {
                    innerState = State::Ret;
                    out << line << "\n";
                }
                else if (!line.empty() && line.at(0) == '.')
                {
                    out << Helper::pushlName + prev << "\n";
                    innerState = State::Label;
                    prev = prevCut(line);
                }
                else
                {
                    out << Helper::pushlName + prev << "\n";
                    out << line << "\n";
                    innerState = State::null;
                }
                break;
            }
            case State::Ret:
            {
                if (!line.empty() && line.at(0) == '.')
                {
                    innerState = State::Label;
                    prev = prevCut(line);
                }
                else if (!line.empty() && line.at(0) != ' ')
                {
                    out << line << "\n";
                    innerState = State::null;
                }

                break;
            }
            case State::Label:
            {
                if (line.empty())
                {
                    innerState = State::null;
                    prev = "";
                    break;
                }

                if (checkPush(line) == Helper::pushlName)
                {
                    out << "." << prev << "\n";
                    innerState = State::Push;
                    prev = pushCut(line);
                }
                else if (checkPop(line) == Helper::poplName)
                {
                    out << "." << prev << "\n";
                    innerState = State::Pop;
                    prev = popCut(line);
                }
                else if (line == Helper::retName)
                {
                    out << "." << prev << "\n";
                    innerState = State::Ret;
                    out << line << "\n";
                }
                else if (!line.empty() && line.at(0) == '.')
                {
                    out << "." << prev << "\n";
                    innerState = State::Label;
                    prev = prevCut(line);
                }
                else
                {
                    out << "." << prev << "\n";
                    out << line << "\n";
                    innerState = State::null;
                }

                break;
            }
        }
    }
}

std::string ClearCode::checkPush(std::string s)
{
    return s.substr(0,8);
}
std::string ClearCode::checkPop(std::string s)
{
    return s.substr(0,7);
}
std::string ClearCode::pushCut(std::string s)
{
    return s.substr(8); 
}
std::string ClearCode::prevCut(std::string s)
{
    return s.substr(1);
}
std::string ClearCode::popCut(std::string s)
{
    return s.substr(7);
}
