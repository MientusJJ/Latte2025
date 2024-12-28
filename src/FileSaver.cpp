//
// Created by Jasiek on 27.12.2023.
//

#include "FileSaver.h"

std::pair<std::string,std::pair<std::string,std::string>> FileSaver::NameOfFile(const std::string &in, const std::string &endik)
{
    auto it = in.find_last_of('/');
    auto it2 = in.find_last_of('.');
    std::string one = (it == std::string::npos ? "." : in.substr(0,it));
    int cut;
    if(it2 == std::string::npos)
    {
        cut = in.length();
    }
    else
    {
        cut = it2;
    }

    std:: string two = in.substr(it+1,cut - it - 1);
    std:: string three = one +"/" + two + "." + endik;
    return {one,{two,three}};

}
void FileSaver::start(const std::string &name)
{
    this->_name = name;
    this->openFile();
}
void FileSaver::openFile()
{
    if(this->_name != "")
    {
        this->_of.open(this->_name);
    }
}
void FileSaver::toFile()
{
    this->_of << this->_program;
    this->_program.clear();
}
void FileSaver::OneLine(const std::string & str,bool clear)
{
    if(clear) {
        const char *s = str.c_str();
        char form[10];
        while (*s) {
            if (isalnum((unsigned char) *s)) {
                sprintf(form, "%c", *s);
            } else {
                sprintf(form, "\\%03hho", *s);
            }
            this->_of << form;
            s++;
        }
    }
    else
    {
        this->_of <<  str;
    }

}
void FileSaver::Addline(const std::string & str)
{
    this->_program = this->_program + str;

}
void FileSaver::endik()
{
    this->_of.close();
    this->_name = this->_program = "";
}
void FileSaver::addError(const std::string & str, int line)
{
    this->errorsVec.emplace_back("Line: " + std::to_string(line)+ "\n " + str + "\n");
}
bool FileSaver::printAllErrors()
{
    if(this->errorsVec.size() == 0)
    {
        return false;
    }
    fprintf(stderr,"ERROR\n");
    for(auto &v : errorsVec)
    {
        fprintf(stderr,"%s",v.c_str());
    }
    return true;
}
void FileSaver::printOk()
{
    fprintf(stderr,"OK\n");
}