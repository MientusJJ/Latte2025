//
// Created by Jasiek on 30.12.2023.
//

#include "CreateOutput.h"

#include <iostream>
#include <string>
using namespace std;


void CreateOutput::visitProgram(Program *t)
{
    t->accept(this);
} //abstract class
void CreateOutput::visitTopDef(TopDef *t) {} //abstract class
void CreateOutput::visitClsFld(ClsFld *t) {} //abstract class
void CreateOutput::visitArg(Arg *t) {} //abstract class
void CreateOutput::visitBlock(Block *t) {} //abstract class
void CreateOutput::visitStmt(Stmt *t) {} //abstract class
void CreateOutput::visitItem(Item *t) {} //abstract class
void CreateOutput::visitSimpleType(SimpleType *t) {} //abstract class
void CreateOutput::visitType(Type *t) {} //abstract class
void CreateOutput::visitExpr(Expr *t) {} //abstract class
void CreateOutput::visitAddOp(AddOp *t) {} //abstract class
void CreateOutput::visitMulOp(MulOp *t) {} //abstract class
void CreateOutput::visitRelOp(RelOp *t) {} //abstract class

void CreateOutput::visitProg(Prog *prog)
{
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);

}

void CreateOutput::visitFnDef(FnDef *p)
{
    /* Code For FnDef Goes Here */
   FileSaver::GetInstance().OneLine("\n" + p->ident_ + ":\n"  "  pushl \%ebp\n"  "  movl \%esp, \%ebp\n");
    auto bytes = ControlOffset::GetInstance().getBytesAlloc(p->ident_);
    if(bytes > 0)
    {
       FileSaver::GetInstance().OneLine("  subl $" + std::to_string(bytes) +", \%esp\n");
    }

    p->type_->accept(this);
    visitIdent(p->ident_);
    p->listarg_->accept(this);
    p->block_->accept(this);
    if (InformationSaver::GetInstance().getFuncType(p->ident_) == Helper::voidName)
    {
       FileSaver::GetInstance().OneLine("  leave\n" "  ret\n");
    }
}
void CreateOutput::visitSExpParen(SExpParen *s_exp_paren)
{
    /* Code For SExpParen Goes Here */

    s_exp_paren->expr_->accept(this);

}

void CreateOutput::visitClsDef(ClsDef *cls_def)
{
    cls_def->listclsfld_->accept(this);

}

void CreateOutput::visitInhClsDef(InhClsDef *inh_cls_def)
{
    /* Code For InhClsDef Goes Here */

    inh_cls_def->listclsfld_->accept(this);

}

void CreateOutput::visitVarDef(VarDef *var_def)
{
}

void CreateOutput::visitMetDef(MetDef *p)
{
    /* Codxe For MetDef Goes Here */
   FileSaver::GetInstance().OneLine("\n" + p->owner_ + "." + p->ident_ + ":\n" "  pushl \%ebp\n" "  movl \%esp, \%ebp\n");
    auto bytes = ControlOffset::GetInstance().getBytesAlloc(p->owner_ + "." + p->ident_);
    if(bytes > 0)
    {
       FileSaver::GetInstance().OneLine("  subl $" + std::to_string(bytes) +", \%esp\n");
    }
    p->type_->accept(this);
    visitIdent(p->ident_);
    p->listarg_->accept(this);
    p->block_->accept(this);
    if (InformationSaver::GetInstance().getFuncType(p->owner_ + "." + p->ident_) == Helper::voidName)
    {
       FileSaver::GetInstance().OneLine("  leave\n" "  ret\n");
    }
}

void CreateOutput::visitAr(Ar *ar)
{
    /* Code For Ar Goes Here */

    ar->type_->accept(this);
    visitIdent(ar->ident_);

}

void CreateOutput::visitBlk(Blk *blk)
{
    /* Code For Blk Goes Here */

    blk->liststmt_->accept(this);

}

void CreateOutput::visitEmpty(Empty *empty)
{
    /* Code For Empty Goes Here */


}

void CreateOutput::visitBStmt(BStmt *b_stmt)
{
    /* Code For BStmt Goes Here */

    b_stmt->block_->accept(this);

}

void CreateOutput::visitDecl(Decl *decl)
{
    /* Code For Decl Goes Here */

    decl->type_->accept(this);
    decl->listitem_->accept(this);

}

void CreateOutput::visitAss(Ass *p)
{
    /* Code For Ass Goes Here */
    CreateOutput *newCOut = new CreateOutput(true);
    p->expr_1->accept(newCOut);
    delete newCOut;
    if(p->expr_2->type_ == Helper::boolName && (p->expr_2->is_always_false_ || p->expr_2->is_always_true_))
    {
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
        if (p->expr_2->is_always_false_) {
           FileSaver::GetInstance().OneLine("  movl $0, (\%eax)\n");
        }
        else
        {
           FileSaver::GetInstance().OneLine("  movl $-1, (\%eax)\n");
        }
    }
    else if(p->expr_2->type_ == Helper::intName && p->expr_2->has_value_)
    {
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_2->value_) + ", (\%eax)\n");
    }
    else
    {
        p->expr_2->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  popl \%ecx\n");
       FileSaver::GetInstance().OneLine("  movl \%eax, (\%ecx)\n");
    }

}

void CreateOutput::visitIncr(Incr *p)
{
    CreateOutput *newCOut = new CreateOutput(true);
    p->expr_->accept(newCOut);
    delete newCOut;
   FileSaver::GetInstance().OneLine("  popl \%ecx\n");
   FileSaver::GetInstance().OneLine("  incl (\%ecx)\n");

}

void CreateOutput::visitDecr(Decr *p)
{
    CreateOutput *newCOut = new CreateOutput(true);
    p->expr_->accept(newCOut);
    delete newCOut;
   FileSaver::GetInstance().OneLine("  popl \%ecx\n");
   FileSaver::GetInstance().OneLine("  decl (\%ecx)\n");

}

void CreateOutput::visitRet(Ret *p)
{
    if (p->expr_->type_ == Helper::boolName && (p->expr_->is_always_false_ || p->expr_->is_always_true_))
    {
        if (p->expr_->is_always_false_)
           FileSaver::GetInstance().OneLine("  movl $0, \%eax\n");
        else
           FileSaver::GetInstance().OneLine("  movl $-1, \%eax\n");
    }
    else if (p->expr_->type_ == Helper::intName && p->expr_->has_value_)
    {
       FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", \%eax\n");
    }
    else
    {
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
    }
   FileSaver::GetInstance().OneLine("  leave\n" "  ret\n");

}

void CreateOutput::visitVRet(VRet *v_ret)
{
   FileSaver::GetInstance().OneLine("  leave\n" "  ret\n");


}

void CreateOutput::visitCond(Cond *p)
{
    /* Code For Cond Goes Here */
    if (!p->expr_->is_always_false_ && !p->expr_->is_always_true_)
    {
        auto label  = InformationSaver::GetInstance().newLabel();
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jz " + label + "\n");
        p->stmt_->accept(this);
       FileSaver::GetInstance().OneLine(label + ":\n");
    }
    else if (p->expr_->is_always_true_)
    {
        p->stmt_->accept(this);
    }

}

void CreateOutput::visitCondElse(CondElse *p)
{
    /* Code For CondElse Goes Here */
    if (!p->expr_->is_always_false_ && !p->expr_->is_always_true_)
    {
        auto elseifLabel = InformationSaver::GetInstance().newLabel();
        auto label = InformationSaver::GetInstance().newLabel();
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jz " + elseifLabel + "\n");
        p->stmt_1->accept(this);
       FileSaver::GetInstance().OneLine("  jmp " + label + "\n");
       FileSaver::GetInstance().OneLine(elseifLabel + ":\n");
        p->stmt_2->accept(this);
       FileSaver::GetInstance().OneLine(label + ":\n");
    }
    else if (p->expr_->is_always_true_)
    {
        p->stmt_1->accept(this);
    }
    else if (p->expr_->is_always_false_)
    {
        p->stmt_2->accept(this);
    }

}

void CreateOutput::visitWhile(While *p)
{
    /* Code For While Goes Here */
    if (!p->expr_->is_always_false_ && !p->expr_->is_always_true_)
    {
        auto whileifLabel = InformationSaver::GetInstance().newLabel();
        auto whilebodyLabel = InformationSaver::GetInstance().newLabel();
       FileSaver::GetInstance().OneLine("  jmp " + whileifLabel + "\n");
       FileSaver::GetInstance().OneLine(whilebodyLabel + ":\n");
        p->stmt_->accept(this);
       FileSaver::GetInstance().OneLine(whileifLabel + ":\n");
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jnz " + whilebodyLabel + "\n");
    }
    else if (p->expr_->is_always_true_)
    {
        auto while_body = InformationSaver::GetInstance().newLabel();
       FileSaver::GetInstance().OneLine(while_body + ":\n");
        p->stmt_->accept(this);
       FileSaver::GetInstance().OneLine("  jmp " + while_body + "\n");
    }

}

void CreateOutput::visitForEach(ForEach *p)
{
    auto forifLabel = InformationSaver::GetInstance().newLabel();
    auto forifbodyLabel = InformationSaver::GetInstance().newLabel();

    FileSaver::GetInstance().OneLine("  pushl \%ebx\n");
    p->type_->accept(this);

    p->expr_->accept(this);

     FileSaver::GetInstance().OneLine("  popl \%ebx\n");
     FileSaver::GetInstance().OneLine("  movl \%ebx, " +
                                              std::to_string(ControlOffset::GetInstance().getPtr(
                                                      p->function_name_, p->ident_, p->index_)) +
                                              "(\%ebp)\n");
     FileSaver::GetInstance().OneLine("  movl (\%ebx), \%ebx\n"); // length of array
     FileSaver::GetInstance().OneLine("  jmp " + forifLabel + "\n");

     FileSaver::GetInstance().OneLine(forifbodyLabel + ":\n");

    p->stmt_->accept(this);

     FileSaver::GetInstance().OneLine("  decl \%ebx\n"); // --length
     FileSaver::GetInstance().OneLine(forifLabel + ":\n");
     FileSaver::GetInstance().OneLine("  addl $4, " +
                                              std::to_string(ControlOffset::GetInstance().getPtr(
                                                      p->function_name_, p->ident_, p->index_)) +
                                              "(\%ebp)\n"); // ++ptr
     FileSaver::GetInstance().OneLine("  test \%ebx, \%ebx\n");
     FileSaver::GetInstance().OneLine("  jnz " + forifbodyLabel + "\n");

     FileSaver::GetInstance().OneLine("  popl \%ebx\n");

}

void CreateOutput::visitSExp(SExp *p)
{
    if (p->expr_->type_ == Helper::boolName && (p->expr_->is_always_false_ || p->expr_->is_always_true_))
    {
        return;
    }
    else if (p->expr_->type_ == Helper::intName && p->expr_->has_value_)
    {
        return;
    }
    else
    {
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
    }

}

void CreateOutput::visitNoInit(NoInit *p)
{
  if(p->type_ != Helper::stringName)
  {
      FileSaver::GetInstance().OneLine("  movl $0, " + std::to_string(
            ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp)\n");
  }
  else
  {
      FileSaver::GetInstance().OneLine("   movl $loc_str_val$0, " + std::to_string(
              ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp)\n");
  }

}

void CreateOutput::visitInit(Init *p)
{
    if (p->expr_->type_ == Helper::boolName && (p->expr_->is_always_false_ || p->expr_->is_always_true_))
    {
        if (p->expr_->is_always_false_) {
           FileSaver::GetInstance().OneLine("  movl $0, " + std::to_string(ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp)\n");
        }
        else {
           FileSaver::GetInstance().OneLine("  movl $-1, " + std::to_string(ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp)\n");
        }
    }
    else if (p->expr_->type_ == Helper::intName && p->expr_->has_value_)
    {
       FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", " + std::to_string(ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp)\n");
    }
    else
    {
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  movl \%eax, " + std::to_string(ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp)\n");
    }

}

void CreateOutput::visitInt(Int *int_)
{
    /* Code For Int Goes Here */


}

void CreateOutput::visitStr(Str *str)
{
    /* Code For Str Goes Here */


}

void CreateOutput::visitBool(Bool *bool_)
{
    /* Code For Bool Goes Here */


}

void CreateOutput::visitVoid(Void *void_)
{
    /* Code For Void Goes Here */


}

void CreateOutput::visitSimpleVarType(SimpleVarType *simple_var_type)
{
    /* Code For SimpleVarType Goes Here */

    simple_var_type->simpletype_->accept(this);

}

void CreateOutput::visitSimpleArrType(SimpleArrType *simple_arr_type)
{
    /* Code For SimpleArrType Goes Here */

    simple_arr_type->simpletype_->accept(this);

}

void CreateOutput::visitVarType(VarType *var_type)
{
    /* Code For VarType Goes Here */

    visitIdent(var_type->ident_);

}

void CreateOutput::visitArrType(ArrType *arr_type)
{
    /* Code For ArrType Goes Here */

    visitIdent(arr_type->ident_);

}

void CreateOutput::visitFun(Fun *fun)
{
    /* Code For Fun Goes Here */

    fun->type_->accept(this);
    fun->listtype_->accept(this);

}

void CreateOutput::visitEVar(EVar *p)
{
    /* Code For EVar Goes Here */
    visitIdent(p->ident_);
    if((!this->ptr && !p->is_reference_) || (this->ptr && p->is_reference_))
    {
       FileSaver::GetInstance().OneLine("  pushl " + std::to_string(
                ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) + "(\%ebp)\n");
    }
    else if (this->ptr && !p->is_reference_)
    {
       FileSaver::GetInstance().OneLine("  leal " + std::to_string(ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp), \%eax\n");
       FileSaver::GetInstance().OneLine("  pushl \%eax\n");
    }
    else if (!this->ptr && p->is_reference_)
    {
       FileSaver::GetInstance().OneLine("  movl " + std::to_string(ControlOffset::GetInstance().getPtr(p->function_name_, p->ident_, p->index_)) +"(\%ebp), \%eax\n");
       FileSaver::GetInstance().OneLine("  pushl (\%eax)\n");
    }


}

void CreateOutput::visitEClsVar(EClsVar *p)
{
    /* Code For EClsVar Goes Here */

    CreateOutput *newCOut = new CreateOutput(false);
    p->expr_->accept(newCOut);
    delete newCOut;
    if (p->expr_->type_.length() > 2 && p->expr_->type_.substr(p->expr_->type_.length() - 2) == Helper::tableName)
    {
        if (p->ident_ == Helper::lengthName)
        {
           FileSaver::GetInstance().OneLine("  popl \%eax\n");
           FileSaver::GetInstance().OneLine("  pushl (\%eax)\n");
        }
    }
    else
    {
        auto className = p->expr_->type_;
        auto classOffset = ControlOffset::GetInstance().getClassOffset(className, p->ident_);
        if (this->ptr)
        {
           FileSaver::GetInstance().OneLine("  popl \%eax\n");
           FileSaver::GetInstance().OneLine("  leal " + std::to_string(classOffset) + "(\%eax), \%eax\n");
           FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        }
        else
        {
           FileSaver::GetInstance().OneLine("  popl \%eax\n");
           FileSaver::GetInstance().OneLine("  pushl " + std::to_string(classOffset) + "(\%eax)\n");
        }
    }

}

void CreateOutput::visitEArrVar(EArrVar *e_arr_var)
{
    /* Code For EArrVar Goes Here */
    CreateOutput *newCOut = new CreateOutput(false);
    e_arr_var->expr_1->accept(newCOut);
    e_arr_var->expr_2->accept(newCOut);
    delete newCOut;
   FileSaver::GetInstance().OneLine("  popl \%eax\n");
   FileSaver::GetInstance().OneLine("  popl \%ecx\n");
    if (!this->ptr)
    {
       FileSaver::GetInstance().OneLine("  movl 4(\%ecx, \%eax, 4), \%eax\n");
    }
    else
    {
       FileSaver::GetInstance().OneLine("  leal 4(\%ecx, \%eax, 4), \%eax\n");
    }
   FileSaver::GetInstance().OneLine("  pushl \%eax\n");

}

void CreateOutput::visitELitInt(ELitInt *p)
{
    /* Code For ELitInt Goes Here */

    visitInteger(p->integer_);
   FileSaver::GetInstance().OneLine("  pushl $" + std::to_string(p->integer_) + "\n");

}

void CreateOutput::visitEString(EString *p)
{
    /* Code For EString Goes Here */

    visitString(p->string_);
   FileSaver::GetInstance().OneLine("  pushl $" +InformationSaver::GetInstance().getStringName(p->string_) + "\n");
}

void CreateOutput::visitELitTrue(ELitTrue *e_lit_true)
{
    /* Code For ELitTrue Goes Here */
   FileSaver::GetInstance().OneLine("  pushl $-1\n");

}

void CreateOutput::visitELitFalse(ELitFalse *e_lit_false)
{
    /* Code For ELitFalse Goes Here */
   FileSaver::GetInstance().OneLine("  pushl $0\n");

}

void CreateOutput::visitELitNull(ELitNull *e_lit_null)
{
    /* Code For ELitNull Goes Here */
   FileSaver::GetInstance().OneLine("  pushl $0\n");

}

void CreateOutput::visitEApp(EApp *p)
{
    /* Code For EApp Goes Here */

    visitIdent(p->ident_);
    for (auto it = p->listexpr_->rbegin(); it != p->listexpr_->rend(); ++it)
    {
        if ((*it)->has_value_)
        {
           FileSaver::GetInstance().OneLine("  pushl $" +std::to_string((*it)->value_) + "\n");
        }
        else if ((*it)->is_always_true_)
        {
           FileSaver::GetInstance().OneLine("  pushl $-1\n");
        }
        else if ((*it)->is_always_false_)
        {
           FileSaver::GetInstance().OneLine("  pushl $0\n");
        }
        else
        {
            (*it)->accept(this);
        }
    }
   FileSaver::GetInstance().OneLine("  call " + p->ident_ + "\n");

    if (!p->listexpr_->empty()) {
       FileSaver::GetInstance().OneLine("  addl $" + std::to_string(4 * p->listexpr_->size()) + ", \%esp\n");
    }

   FileSaver::GetInstance().OneLine("  pushl \%eax\n");

}

void CreateOutput::visitEClsApp(EClsApp *p)
{
    /* Code For EClsApp Goes Here */

    visitIdent(p->ident_);
    CreateOutput *newCOut = new CreateOutput(false);
    for (auto it = p->listexpr_->rbegin(); it != p->listexpr_->rend(); ++it)
    {
        if ((*it)->has_value_)
        {
           FileSaver::GetInstance().OneLine("  pushl $" + std::to_string((*it)->value_) + "\n");
        }
        else if ((*it)->is_always_true_)
        {
           FileSaver::GetInstance().OneLine("  pushl $-1\n");
        }
        else if ((*it)->is_always_false_)
        {
           FileSaver::GetInstance().OneLine("  pushl $0\n");
        }
        else
        {
            (*it)->accept(newCOut);
        }
    }
    p->expr_->accept(newCOut);

    delete newCOut;

   FileSaver::GetInstance().OneLine("  call " + p->owner_ + "." + p->ident_ + "\n");
   FileSaver::GetInstance().OneLine("  addl $" + std::to_string(4 * (p->listexpr_->size() + 1)) + ", \%esp\n");
   FileSaver::GetInstance().OneLine("  pushl \%eax\n");
}

void CreateOutput::visitENeg(ENeg *p)
{
    /* Code For ENeg Goes Here */

    if (p->expr_->has_value_)
    {
       FileSaver::GetInstance().OneLine("  pushl $" +std::to_string(-p->expr_->value_) + "\n");
    }
    else
    {
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  negl (\%esp)\n");
    }

}

void CreateOutput::visitENot(ENot *p)
{
    /* Code For ENot Goes Here */
    if (p->expr_->is_always_false_)
    {
       FileSaver::GetInstance().OneLine("  pushl $-1\n");
    }
    else if (p->expr_->is_always_true_)
    {
       FileSaver::GetInstance().OneLine("  pushl $0\n");
    }
    else
    {
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  notl (\%esp)\n");
    }

}

void CreateOutput::visitEVarNew(EVarNew *p)
{
    /* Code For EVarNew Goes Here */
   FileSaver::GetInstance().OneLine("  pushl $" +std::to_string(ControlOffset::GetInstance().getSizeofClass(p->ident_)) + "\n");
   FileSaver::GetInstance().OneLine("  call malloc\n");
   FileSaver::GetInstance().OneLine("  addl $4, \%esp\n");
   FileSaver::GetInstance().OneLine("  pushl \%eax\n");

}

void CreateOutput::visitEVarSimpleNew(EVarSimpleNew *e_var_simple_new)
{
    /* Code For EVarSimpleNew Goes Here */


}

void CreateOutput::visitEArrNew(EArrNew *p)
{
    /* Code For EArrNew Goes Here */

    auto classSize = ControlOffset::GetInstance().getSizeofClass(p->ident_);

    auto whileifLabel = InformationSaver::GetInstance().newLabel();
    auto whilebodyLabel = InformationSaver::GetInstance().newLabel();
    if (p->expr_->has_value_)
    {
       FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", \%eax\n");
       FileSaver::GetInstance().OneLine("  leal 4(, \%eax, 4), \%eax\n");
       FileSaver::GetInstance().OneLine("  pushl \%eax\n");
       FileSaver::GetInstance().OneLine("  call malloc\n");
       FileSaver::GetInstance().OneLine("  addl $4, \%esp\n");
       FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", (\%eax)\n");
       FileSaver::GetInstance().OneLine("  pushl \%ebx\n");
       FileSaver::GetInstance().OneLine("  pushl \%eax\n");
       FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", \%ebx\n");
    }
    else
    {
        p->expr_->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  movl \%eax, \%ecx\n");
       FileSaver::GetInstance().OneLine("  pushl \%ecx\n");
       FileSaver::GetInstance().OneLine("  leal 4(, \%eax, 4), \%eax\n");
       FileSaver::GetInstance().OneLine("  pushl \%eax\n");
       FileSaver::GetInstance().OneLine("  call malloc\n");
       FileSaver::GetInstance().OneLine("  addl $4, \%esp\n");
       FileSaver::GetInstance().OneLine("  popl \%ecx\n");
       FileSaver::GetInstance().OneLine("  movl \%ecx, (\%eax)\n");
       FileSaver::GetInstance().OneLine("  pushl \%ebx\n");
       FileSaver::GetInstance().OneLine("  pushl \%eax\n");
       FileSaver::GetInstance().OneLine("  movl \%ecx, \%ebx\n");
    }
  FileSaver::GetInstance().OneLine("  jmp " + whileifLabel + "\n");
  FileSaver::GetInstance().OneLine(whilebodyLabel + ":\n");
  FileSaver::GetInstance().OneLine("  popl \%edx\n");
  FileSaver::GetInstance().OneLine("  movl $0, (\%edx, \%ebx, 4)\n");
  FileSaver::GetInstance().OneLine("  pushl \%edx\n");
  FileSaver::GetInstance().OneLine("  decl \%ebx\n");
  FileSaver::GetInstance().OneLine(whileifLabel + ":\n");
  FileSaver::GetInstance().OneLine("  test \%ebx, \%ebx\n");
  FileSaver::GetInstance().OneLine("  jnz " + whilebodyLabel + "\n");
  FileSaver::GetInstance().OneLine("  popl \%eax\n");
  FileSaver::GetInstance().OneLine("  popl \%ebx\n");
  FileSaver::GetInstance().OneLine("  pushl \%eax\n");
}

void CreateOutput::visitEArrSimpleNew(EArrSimpleNew *p)
{
    /* Code For EArrSimpleNew Goes Here */

    p->simpletype_->accept(this);
    if (p->expr_->has_value_)
    {
      FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", \%eax\n");
      FileSaver::GetInstance().OneLine("  leal 4(, \%eax, 4), \%eax\n");
      FileSaver::GetInstance().OneLine("  pushl \%eax\n");
      FileSaver::GetInstance().OneLine("  call malloc\n");
      FileSaver::GetInstance().OneLine("  addl $4, \%esp\n");
      FileSaver::GetInstance().OneLine("  movl $" + std::to_string(p->expr_->value_) + ", (\%eax)\n");
      FileSaver::GetInstance().OneLine("  pushl \%eax\n");
    }
    else
    {
        p->expr_->accept(this);
      FileSaver::GetInstance().OneLine("  popl \%ecx\n");
      FileSaver::GetInstance().OneLine("  leal 4(, \%ecx, 4), \%eax\n");
      FileSaver::GetInstance().OneLine("  pushl \%ecx\n");
      FileSaver::GetInstance().OneLine("  pushl \%eax\n");
      FileSaver::GetInstance().OneLine("  call malloc\n");
      FileSaver::GetInstance().OneLine("  addl $4, \%esp\n");
      FileSaver::GetInstance().OneLine("  popl \%ecx\n");
      FileSaver::GetInstance().OneLine("  movl \%ecx, (\%eax)\n");
      FileSaver::GetInstance().OneLine("  pushl \%eax\n");
    }
    if(p->type_ == (Helper::stringName + Helper::tableName))
    {
        auto whileifLabel = InformationSaver::GetInstance().newLabel();
        auto whilebodyLabel = InformationSaver::GetInstance().newLabel();
        FileSaver::GetInstance().OneLine("  movl (%eax), %ecx\n");
        FileSaver::GetInstance().OneLine("  leal 4(%eax), %edx\n");
        FileSaver::GetInstance().OneLine(whileifLabel + ":\n");
        FileSaver::GetInstance().OneLine("  cmpl $0, %ecx\n");
        FileSaver::GetInstance().OneLine("  jle " + whilebodyLabel + "\n");
        FileSaver::GetInstance().OneLine("  movl $loc_str_val$0, (%edx)\n");
        FileSaver::GetInstance().OneLine("  addl $4, %edx\n");
        FileSaver::GetInstance().OneLine("  decl %ecx\n");
        FileSaver::GetInstance().OneLine("  jmp " + whileifLabel + "\n");
        FileSaver::GetInstance().OneLine(whilebodyLabel + ":\n");
    }

}

void CreateOutput::visitEVarCast(EVarCast *e_var_cast)
{
    /* Code For EVarCast Goes Here */

    e_var_cast->expr_->accept(this);

}

void CreateOutput::visitEVarSimpleCast(EVarSimpleCast *e_var_simple_cast)
{
    /* Code For EVarSimpleCast Goes Here */

    e_var_simple_cast->expr_->accept(this);

}

void CreateOutput::visitEArrCast(EArrCast *e_arr_cast)
{
    /* Code For EArrCast Goes Here */

    e_arr_cast->expr_->accept(this);

}

void CreateOutput::visitEArrSimpleCast(EArrSimpleCast *e_arr_simple_cast)
{
    /* Code For EArrSimpleCast Goes Here */
    
    e_arr_simple_cast->expr_->accept(this);

}

void CreateOutput::visitEMul(EMul *e_mul)
{
    /* Code For EMul Goes Here */

    auto mulFlag = dynamic_cast<Times*>(e_mul->mulop_);
    auto divFlag = dynamic_cast<Div*>(e_mul->mulop_);

    if (mulFlag != nullptr)
    {
        if (e_mul->expr_1->has_value_ && e_mul->expr_2->has_value_)
        {
            FileSaver::GetInstance().OneLine("  pushl $" + std::to_string(e_mul->expr_1->value_ * e_mul->expr_2->value_) + "\n");
        }
        else if (e_mul->expr_1->has_value_ && !e_mul->expr_2->has_value_)
        {
            e_mul->expr_2->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  imull $" + std::to_string(e_mul->expr_1->value_) + ", \%eax\n");
            FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        }
        else if (!e_mul->expr_1->has_value_ && e_mul->expr_2->has_value_)
        {
            e_mul->expr_1->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  imull $" + std::to_string(e_mul->expr_2->value_) + ", \%eax\n");
            FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        }
        else
        {
            e_mul->expr_1->accept(this);
            e_mul->expr_2->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  imull (\%esp), \%eax\n");
            FileSaver::GetInstance().OneLine("  movl \%eax, (\%esp)\n");
        }
    }
    else if (divFlag != nullptr)
    {
        if (e_mul->expr_1->has_value_ && e_mul->expr_2->has_value_)
        {
            FileSaver::GetInstance().OneLine("  pushl $" + std::to_string(e_mul->expr_1->value_ / e_mul->expr_2->value_) + "\n");
        }
        else if (e_mul->expr_1->has_value_ && !e_mul->expr_2->has_value_)
        {
            e_mul->expr_2->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%ecx\n");
            FileSaver::GetInstance().OneLine("  movl $" + std::to_string(e_mul->expr_1->value_) + ", \%eax\n");
            FileSaver::GetInstance().OneLine("  cdq\n");
            FileSaver::GetInstance().OneLine("  idivl \%ecx\n");
            FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        }
        else if (!e_mul->expr_1->has_value_ && e_mul->expr_2->has_value_)
        {
            e_mul->expr_1->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  cdq\n");
            FileSaver::GetInstance().OneLine("  movl $" + std::to_string(e_mul->expr_2->value_) + ", \%ecx\n");
            FileSaver::GetInstance().OneLine("  idivl \%ecx\n");
            FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        }
        else
        {
            e_mul->expr_1->accept(this);
            e_mul->expr_2->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%ecx\n");
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  cdq\n");
            FileSaver::GetInstance().OneLine("  idivl \%ecx\n");
            FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        }
    }
    else
    {
        if (e_mul->expr_1->has_value_ && e_mul->expr_2->has_value_)
        {
            FileSaver::GetInstance().OneLine("  pushl $" + std::to_string(e_mul->expr_1->value_ % e_mul->expr_2->value_) + "\n");
        }
        else if (e_mul->expr_1->has_value_ && !e_mul->expr_2->has_value_)
        {
            e_mul->expr_2->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%ecx\n");
            FileSaver::GetInstance().OneLine("  movl $" + std::to_string(e_mul->expr_1->value_) + ", \%eax\n");
            FileSaver::GetInstance().OneLine("  cdq\n");
            FileSaver::GetInstance().OneLine("  idivl \%ecx\n");
            FileSaver::GetInstance().OneLine("  pushl \%edx\n");
        }
        else if (!e_mul->expr_1->has_value_ && e_mul->expr_2->has_value_)
        {
            e_mul->expr_1->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  cdq\n");
            FileSaver::GetInstance().OneLine("  movl $" + std::to_string(e_mul->expr_2->value_) + ", \%ecx\n");
            FileSaver::GetInstance().OneLine("  idivl \%ecx\n");
            FileSaver::GetInstance().OneLine("  pushl \%edx\n");
        }
        else
        {
            e_mul->expr_1->accept(this);
            e_mul->expr_2->accept(this);
            FileSaver::GetInstance().OneLine("  popl \%ecx\n");
            FileSaver::GetInstance().OneLine("  popl \%eax\n");
            FileSaver::GetInstance().OneLine("  cdq\n");
            FileSaver::GetInstance().OneLine("  idivl \%ecx\n");
            FileSaver::GetInstance().OneLine("  pushl \%edx\n");
        }
    }

}

void CreateOutput::visitEAdd(EAdd *p)
{
    /* Code For EAdd Goes Here */

    auto plusFlag = dynamic_cast<Plus*>(p->addop_);
    if (p->expr_1->type_ == Helper::stringName && p->expr_2->type_ == Helper::stringName)
    {
        p->expr_1->accept(this);
        p->expr_2->accept(this);
        FileSaver::GetInstance().OneLine("  popl \%eax\n");
        FileSaver::GetInstance().OneLine("  popl \%ecx\n");
        FileSaver::GetInstance().OneLine("  pushl \%eax\n");
        FileSaver::GetInstance().OneLine("  pushl \%ecx\n");
        FileSaver::GetInstance().OneLine("  call _Latte.addStrings\n");
        FileSaver::GetInstance().OneLine("  addl $8, \%esp\n");
        FileSaver::GetInstance().OneLine("  pushl \%eax\n");
    }
    else if (p->expr_1->type_ == Helper::intName && p->expr_2->type_ == Helper::intName)
    {
        if (plusFlag != nullptr)
        {
            if (p->expr_1->has_value_ && p->expr_2->has_value_)
            {
                FileSaver::GetInstance().OneLine("  pushl $" + std::to_string(p->expr_1->value_ + p->expr_2->value_) + "\n");
            }
            else if (p->expr_1->has_value_ && !p->expr_2->has_value_)
            {
                p->expr_2->accept(this);
                FileSaver::GetInstance().OneLine("  addl $" + std::to_string(p->expr_1->value_) + ", (%esp)\n");
            }
            else if (!p->expr_1->has_value_ && p->expr_2->has_value_)
            {
                p->expr_1->accept(this);
                FileSaver::GetInstance().OneLine("  addl $" + std::to_string(p->expr_2->value_) + ", (%esp)\n");
            }
            else
            {
                p->expr_1->accept(this);
                p->expr_2->accept(this);
                FileSaver::GetInstance().OneLine("  popl \%eax\n");
                FileSaver::GetInstance().OneLine("  addl \%eax, (\%esp)\n");
            }
        }
        else
        {
            if (p->expr_1->has_value_ && p->expr_2->has_value_)
            {
                FileSaver::GetInstance().OneLine("  pushl $" + std::to_string(p->expr_1->value_ - p->expr_2->value_) + "\n");
            }
            else if (p->expr_1->has_value_ && !p->expr_2->has_value_)
            {
                p->expr_2->accept(this);
                FileSaver::GetInstance().OneLine("  subl $" + std::to_string(p->expr_1->value_) + ", (%esp)\n");
                FileSaver::GetInstance().OneLine("  negl (%esp)\n");
            }
            else if (!p->expr_1->has_value_ && p->expr_2->has_value_)
            {
                p->expr_1->accept(this);
                FileSaver::GetInstance().OneLine("  subl $" + std::to_string(p->expr_2->value_) + ", (%esp)\n");
            }
            else
            {
                p->expr_1->accept(this);
                p->expr_2->accept(this);
                FileSaver::GetInstance().OneLine("  popl \%eax\n");
                FileSaver::GetInstance().OneLine("  subl \%eax, (\%esp)\n");
            }
        }
    }

}

void CreateOutput::visitERel(ERel *p)
{
    /* Code For ERel Goes Here */
    if (p->is_always_false_)
    {
       FileSaver::GetInstance().OneLine("  pushl $0\n");
    }
    else if (p->is_always_true_)
    {
       FileSaver::GetInstance().OneLine("  pushl $-1\n");
    }
    else
    {
        p->expr_1->accept(this);
        p->expr_2->accept(this);
        auto equalFlag = dynamic_cast<EQU*>(p->relop_);
        auto neqFlag = dynamic_cast<NE*>(p->relop_);
        auto ltFlag = dynamic_cast<LTH*>(p->relop_);
        auto leFlag = dynamic_cast<LE*>(p->relop_);
        auto gtFlag = dynamic_cast<GTH*>(p->relop_);
        auto geFlag = dynamic_cast<GE*>(p->relop_);
        std::string opLabel = InformationSaver::GetInstance().newLabel();
        std::string negLabel = InformationSaver::GetInstance().newLabel();
        if (p->expr_1->type_ == Helper::stringName && p->expr_2->type_ == Helper::stringName)
        {
           FileSaver::GetInstance().OneLine("  call strcmp\n");
           FileSaver::GetInstance().OneLine("  addl $4, \%esp\n");
           FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");

        }
        else
        {
           FileSaver::GetInstance().OneLine("  popl \%eax\n");
           FileSaver::GetInstance().OneLine("  cmpl \%eax, (\%esp)\n");
        }
        if (equalFlag != nullptr)
        {
           FileSaver::GetInstance().OneLine("  jne " + opLabel + "\n");
        }
        else if (neqFlag != nullptr)
        {
           FileSaver::GetInstance().OneLine("  je " + opLabel + "\n");
        }
        else if (ltFlag != nullptr)
        {
           FileSaver::GetInstance().OneLine("  jge " + opLabel + "\n");
        }
        else if (leFlag != nullptr)
        {
           FileSaver::GetInstance().OneLine("  jg " + opLabel + "\n");
        }
        else if (gtFlag != nullptr)
        {
           FileSaver::GetInstance().OneLine("  jle " + opLabel + "\n");
        }
        else if (geFlag != nullptr)
        {
           FileSaver::GetInstance().OneLine("  jl " + opLabel + "\n");
        }

       FileSaver::GetInstance().OneLine("  movl $-1, (\%esp)\n");
       FileSaver::GetInstance().OneLine("  jmp " + negLabel + "\n");
       FileSaver::GetInstance().OneLine(opLabel + ":\n");
       FileSaver::GetInstance().OneLine("  movl $0, (\%esp)\n");
       FileSaver::GetInstance().OneLine(negLabel + ":\n");
    }

}

void CreateOutput::visitEAnd(EAnd *p)
{
    /* Code For EAnd Goes Here */
    if (p->is_always_false_)
    {
       FileSaver::GetInstance().OneLine("  pushl $0\n");
    }
    else if (p->is_always_true_)
    {
       FileSaver::GetInstance().OneLine("  pushl $-1\n");
    }
    else
    {
        std::string opLabel = InformationSaver::GetInstance().newLabel();
        std::string negLabel = InformationSaver::GetInstance().newLabel();

        p->expr_1->accept(this);

       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jz " + opLabel + "\n");

        p->expr_2->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jz " + opLabel + "\n");

       FileSaver::GetInstance().OneLine("  pushl $-1\n");
       FileSaver::GetInstance().OneLine("  jmp " + negLabel + "\n");
       FileSaver::GetInstance().OneLine(opLabel + ":\n");
       FileSaver::GetInstance().OneLine("  pushl $0\n");
       FileSaver::GetInstance().OneLine(negLabel + ":\n");
    }

}

void CreateOutput::visitEOr(EOr *p)
{
    /* Code For EOr Goes Here */
    if (p->is_always_false_)
    {
       FileSaver::GetInstance().OneLine("  pushl $0\n");
    }
    else if (p->is_always_true_)
    {
       FileSaver::GetInstance().OneLine("  pushl $-1\n");
    }
    else
    {
        std::string trueLabel = InformationSaver::GetInstance().newLabel();
        std::string negLabel = InformationSaver::GetInstance().newLabel();
        p->expr_1->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jnz " + trueLabel + "\n");
        p->expr_2->accept(this);
       FileSaver::GetInstance().OneLine("  popl \%eax\n");
       FileSaver::GetInstance().OneLine("  test \%eax, \%eax\n");
       FileSaver::GetInstance().OneLine("  jnz " + trueLabel + "\n");
       FileSaver::GetInstance().OneLine("  pushl $0\n");
       FileSaver::GetInstance().OneLine("  jmp " + negLabel + "\n");
       FileSaver::GetInstance().OneLine(trueLabel + ":\n");
       FileSaver::GetInstance().OneLine("  pushl $-1\n");
       FileSaver::GetInstance().OneLine(negLabel + ":\n");
    }

}

void CreateOutput::visitPlus(Plus *plus)
{
    /* Code For Plus Goes Here */


}

void CreateOutput::visitMinus(Minus *minus)
{
    /* Code For Minus Goes Here */


}

void CreateOutput::visitTimes(Times *times)
{
    /* Code For Times Goes Here */


}

void CreateOutput::visitDiv(Div *div)
{
    /* Code For Div Goes Here */


}

void CreateOutput::visitMod(Mod *mod)
{
    /* Code For Mod Goes Here */


}

void CreateOutput::visitLTH(LTH *lth)
{
    /* Code For LTH Goes Here */


}

void CreateOutput::visitLE(LE *le)
{
    /* Code For LE Goes Here */


}

void CreateOutput::visitGTH(GTH *gth)
{
    /* Code For GTH Goes Here */


}

void CreateOutput::visitGE(GE *ge)
{
    /* Code For GE Goes Here */


}

void CreateOutput::visitEQU(EQU *equ)
{
    /* Code For EQU Goes Here */


}

void CreateOutput::visitNE(NE *ne)
{
    /* Code For NE Goes Here */


}


void CreateOutput::visitListClsFld(ListClsFld *list_cls_fld)
{
    for (ListClsFld::iterator i = list_cls_fld->begin() ; i != list_cls_fld->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CreateOutput::visitListTopDef(ListTopDef *list_top_def)
{
    for (ListTopDef::iterator i = list_top_def->begin() ; i != list_top_def->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CreateOutput::visitListIdent(ListIdent *list_ident)
{
    for (ListIdent::iterator i = list_ident->begin() ; i != list_ident->end() ; ++i)
    {
        visitIdent(*i) ;
    }
}

void CreateOutput::visitListArg(ListArg *list_arg)
{
    for (ListArg::iterator i = list_arg->begin() ; i != list_arg->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CreateOutput::visitListStmt(ListStmt *list_stmt)
{
    for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CreateOutput::visitListItem(ListItem *list_item)
{
    for (ListItem::iterator i = list_item->begin() ; i != list_item->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CreateOutput::visitListType(ListType *list_type)
{
    for (ListType::iterator i = list_type->begin() ; i != list_type->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CreateOutput::visitListExpr(ListExpr *list_expr)
{
    for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
    {
        (*i)->accept(this);
    }
}


void CreateOutput::visitInteger(Integer x)
{
    /* Code for Integer Goes Here */
}

void CreateOutput::visitChar(Char x)
{
    /* Code for Char Goes Here */
}

void CreateOutput::visitDouble(Double x)
{
    /* Code for Double Goes Here */
}

void CreateOutput::visitString(String x)
{
    /* Code for String Goes Here */
}

void CreateOutput::visitIdent(Ident x)
{
    /* Code for Ident Goes Here */
}



