#include "Parser.h"
#include "Absyn.h"
#include <stdio.h>
#include "ClearCode.h"
#include "Numbers.h"
#include "FileSaver.h"
#include "InformationSaver.h"
#include "FunctionsAndClasses.h"
#include <string>
#include <stdexcept>
#include "ControlFlow.h"
#include "Analyser.h"
#include "ControlOffset.h"
#include "CreateOutput.h"
#include "AnalyserSem.h"
int main(int argc,char ** argv) {
    FILE * input;
    std::string filename_input,filename_output;
    if(argc-1 == 0)
    {
        fprintf(stderr,"ERROR\nNo file\n");
        return Numbers::MAIN_ERROR;
    }
    input = fopen(argv[1],"r");
    if(input == nullptr)
    {
       fprintf(stderr,"ERROR\nCouldn't open input file\n");
       return Numbers::MAIN_ERROR;
    }

    filename_input = std::string(argv[1]);
    auto [dir,second] = FileSaver::GetInstance().NameOfFile(filename_input,"s");
    auto [clearName,outName] = second;

    Program * progInput;
    try
    {
         progInput = pProgram(input);
    }
    catch (std::exception &e)
    {
        std::string str = "Int should be between -2147483648 and 2147483647!";
        FileSaver::GetInstance().addError(str,std::stoi((e.what())));
        FileSaver::GetInstance().printAllErrors();
        return Numbers::MAIN_ERROR;
    }
    if(progInput != nullptr)
    {
        FunctionsAndClasses *FaC = new FunctionsAndClasses;
        InformationSaver::GetInstance().lib();
        FaC->visitProgram(progInput);
        delete FaC;
        try
        {
            InformationSaver::GetInstance().InheritanceCorrectLoops();
            InformationSaver::GetInstance().checkMain();
            if(FileSaver::GetInstance().printAllErrors())
            {
                return Numbers::MAIN_ERROR;
            }
            Analyser *analys = new Analyser;
            analys->visitProgram(progInput);
            delete analys;
            InformationSaver::GetInstance().newClassPars();
            InformationSaver::GetInstance().newString("");
            AnalyserSem *analSem = new AnalyserSem;
            analSem->visitProgram(progInput);
            delete analSem;
            ControlFlow::getInstance().FlowExists();
        }
        catch(std::invalid_argument &e)
        {
            FileSaver::GetInstance().addError(e.what(),Numbers::UNEXCEPTED);
        }
        if(FileSaver::GetInstance().printAllErrors())
        {
            return Numbers::MAIN_ERROR;
        }
        ControlOffset::GetInstance().newPtrs();
        ControlOffset::GetInstance().newClassOffs();
        FileSaver::GetInstance().start(outName + ".bak");
        FileSaver::GetInstance().OneLine(".data\n\n");
        auto strs = InformationSaver::GetInstance().getStrings();
        for ( const auto & v: strs)
        {
            FileSaver::GetInstance().OneLine(v.second + ": .string \"");
            FileSaver::GetInstance().OneLine(v.first, true);
            FileSaver::GetInstance().OneLine("\"\n");
        }
        FileSaver::GetInstance().OneLine(".text\n\n");
        auto funs = InformationSaver::GetInstance().getFunc();
        for ( const auto & v: funs)
        {
           if(!InformationSaver::GetInstance().isLib(v.first))
          {
                FileSaver::GetInstance().OneLine(".globl " + v.first + "\n");
          }
        }
        CreateOutput *CrtOut = new CreateOutput(false);
        CrtOut->visitProgram(progInput);
        delete CrtOut;
        FileSaver::GetInstance().endik();
        ClearCode *clrCode = new ClearCode;
        clrCode->start(outName +".bak",outName);
        clrCode->exec();
        clrCode->endik();
        std::string execStr = argv[0];
        auto stash = execStr.find_last_of('/');
        std::string relDir =
                stash == std::string::npos ? execStr : execStr.substr(0, stash);
        std::string command =
                "gcc -c -o " + dir + "/" + clearName + ".o -m32 " + dir + "/" + clearName + ".s";
        std::string linker ="ld -o " + dir + "/" + clearName + " -melf_i386 " + dir + "/" + clearName + ".o " + relDir + "/lib/runtime.o " + relDir + "/lib/crti.o lib/libc.a lib/crt1.o lib/crtn.o";
        std::system(command.c_str());
        std::system(linker.c_str());
        FileSaver::GetInstance().printOk();
        return Numbers::EVERYTHING_OK;
    }

    return Numbers::MAIN_ERROR;
}
