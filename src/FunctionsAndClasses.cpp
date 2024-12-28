/*** BNFC-Generated Visitor Design Pattern FunctionsAndClasses. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "FunctionsAndClasses.h"



void FunctionsAndClasses::visitProgram(Program *t)
{
    t->accept(this);
}


void FunctionsAndClasses::visitProg(Prog *prog)
{
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);

}

void FunctionsAndClasses::visitFnDef(FnDef *p)
{
    /* Code For FnDef Goes Here */
    bool b = InformationSaver::GetInstance().newFunc(p->ident_,p->type_,p->listarg_);
    if(!b)
    {
        FileSaver::GetInstance().addError("Name of the function already used",p->line);
    }

}

void FunctionsAndClasses::visitClsDef(ClsDef *p)
{
    bool b = InformationSaver::GetInstance().newClass("",p->ident_);
    if(!b)
    {
        FileSaver::GetInstance().addError("Name of the class already used",p->line);
    }

}

void FunctionsAndClasses::visitInhClsDef(InhClsDef *p)
{
    bool b = InformationSaver::GetInstance().newClass(p->ident_2,p->ident_1);
    if(!b)
    {
        FileSaver::GetInstance().addError("Name of the class already used",p->line);
    }

}

void FunctionsAndClasses::visitListTopDef(ListTopDef *list_top_def)
{
    for (ListTopDef::iterator i = list_top_def->begin() ; i != list_top_def->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

