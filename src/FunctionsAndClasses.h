//
// Created by Jasiek on 28.12.2023.
//

#ifndef LATTE_FUNCTIONSANDCLASSES_H
#define LATTE_FUNCTIONSANDCLASSES_H

#include "Absyn.h"
#include <string>
#include "InformationSaver.h"
#include "FileSaver.h"
class FunctionsAndClasses : public Visitor
{
public:
    void visitProgram(Program *p) override;
    void visitProg(Prog *p)override;
    void visitFnDef(FnDef *p)override;
    void visitClsDef(ClsDef *p)override;
    void visitInhClsDef(InhClsDef *p)override;

    void visitListTopDef(ListTopDef *p);




};

#endif //LATTE_FUNCTIONSANDCLASSES_H
