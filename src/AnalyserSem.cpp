/*** BNFC-Generated Visitor Design Pattern AnalyserSem. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "AnalyserSem.h"
#include <iostream>
using namespace std;

void AnalyserSem::visitProgram(Program *t) {
    t->accept(this);
} //abstract class
void AnalyserSem::visitTopDef(TopDef *t) {} //abstract class
void AnalyserSem::visitClsFld(ClsFld *t) {} //abstract class
void AnalyserSem::visitArg(Arg *t) {} //abstract class
void AnalyserSem::visitBlock(Block *t) {} //abstract class
void AnalyserSem::visitStmt(Stmt *t) {} //abstract class
void AnalyserSem::visitItem(Item *t) {} //abstract class
void AnalyserSem::visitSimpleType(SimpleType *t) {} //abstract class
void AnalyserSem::visitType(Type *t) {} //abstract class
void AnalyserSem::visitExpr(Expr *t) {} //abstract class
void AnalyserSem::visitAddOp(AddOp *t) {} //abstract class
void AnalyserSem::visitMulOp(MulOp *t) {} //abstract class
void AnalyserSem::visitRelOp(RelOp *t) {} //abstract class

void AnalyserSem::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */
  cout << "Tutaj3" << endl;
  prog->listtopdef_->accept(this);

}

void AnalyserSem::visitFnDef(FnDef *p)
{
  /* Code For FnDef Goes Here */
  cout << "Tutaj4" << endl;
  InformationSaver::GetInstance().restart();
  InformationSaver::GetInstance().BlkEntry();
  p->type_->accept(this);
  if(!InformationSaver::GetInstance().checkType(p->type_->get()))
  {
    std::string str = p->type_->get() + " is not a valid type name";
    FileSaver::GetInstance().addError(str,p->type_->line);
  }
  ControlFlow::getInstance().newFunc(p->ident_,p->type_->get(),p->line);
  visitIdent(p->ident_);
  p->listarg_->accept(this);
  p->block_->accept(this);
  InformationSaver::GetInstance().BlkExit();
}

void AnalyserSem::visitClsDef(ClsDef *p)
{
  /* Code For ClsDef Goes Here */
    cout << "Tutaj5" << endl;
  ControlFlow::getInstance().setClass(p->ident_);
  p->listclsfld_->accept(this);
}

void AnalyserSem::visitInhClsDef(InhClsDef *p)
{
  /* Code For InhClsDef Goes Here */
    cout << "Tutaj6" << endl;
  ControlFlow::getInstance().setClass(p->ident_1);
  p->listclsfld_->accept(this);
}

void AnalyserSem::visitVarDef(VarDef *var_def)
{
  /* Code For VarDef Goes Here */
    cout << "Tutaj7" << endl;

}

void AnalyserSem::visitMetDef(MetDef *p)
{
  /* Code For MetDef Goes Here */
    cout << "Tutaj8" << endl;
  InformationSaver::GetInstance().restart();
  InformationSaver::GetInstance().BlkEntry();
  p->type_->accept(this);
  if(!InformationSaver::GetInstance().checkType(p->type_->get()))
  {
      std::string str = p->type_->get() + " is not a valid type name";
      FileSaver::GetInstance().addError(str,p->type_->line);
  }
  auto className = ControlFlow::getInstance().getCurClass();
  ControlFlow::getInstance().newFunc(className +"." + p->ident_,p->type_->get(),p->line);
  visitIdent(p->ident_);
  p->listarg_->accept(this);
  p->block_->accept(this);
  p->owner_ = className;
  InformationSaver::GetInstance().BlkExit();
}
void AnalyserSem::visitSExpParen(SExpParen *s_exp_paren)
{
    /* Code For SExpParen Goes Here */

    s_exp_paren->expr_->accept(this);

}
void AnalyserSem::visitAr(Ar *p)
{
  /* Code For Ar Goes Here */
    cout << "Tutaj10" << endl;
  p->type_->accept(this);
  visitIdent(p->ident_);
  if(!InformationSaver::GetInstance().checkType(p->type_->get()))
  {
      std::string str = p->type_->get() + " is not a valid type name";
      FileSaver::GetInstance().addError(str,p->type_->line);
  }
   if(p->type_->get().substr(0,4) == Helper::voidName)
  {
      std::string str = "Can't declare variable with 'void' type";
      FileSaver::GetInstance().addError(str,p->type_->line);
  }

  if(!InformationSaver::GetInstance().newSym(p->ident_,p->type_->get()))
  {
      std::string str = p->ident_ + " previously declared.";
      FileSaver::GetInstance().addError(str,p->line);
  }
  auto funcName = ControlFlow::getInstance().getCurFunName();
  int indx;
  try
  {
      indx = InformationSaver::GetInstance().getSymIndex(p->ident_);
  }
  catch(const std::invalid_argument &e)
  {
      FileSaver::GetInstance().addError(e.what(),p->type_->line);
  }
  if(!InformationSaver::GetInstance().newParam(funcName,p->ident_,p->type_->get(),indx))
  {
      std::string str = funcName + " not found";
      FileSaver::GetInstance().addError(str,p->line);
  }
  p->index_ = indx;
  p->function_name_ = funcName;
}

void AnalyserSem::visitBlk(Blk *blk)
{
  /* Code For Blk Goes Here */
    cout << "Tutaj11" << endl;
  InformationSaver::GetInstance().BlkEntry();
  blk->liststmt_->accept(this);
  InformationSaver::GetInstance().BlkExit();
}

void AnalyserSem::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */
    cout << "Tutaj12" << endl;

}

void AnalyserSem::visitBStmt(BStmt *b_stmt)
{
  /* Code For BStmt Goes Here */
    cout << "Tutaj13" << endl;
  b_stmt->block_->accept(this);

}

void AnalyserSem::visitDecl(Decl *p)
{
  /* Code For Decl Goes Here */
  cout << "Tutaj14" << endl;
  p->type_->accept(this);
  if(!InformationSaver::GetInstance().checkType(p->type_->get()))
  {
      std::string str = "Variable \"" + p->type_->get() +"\" has a bad type.";
      FileSaver::GetInstance().addError(str,p->type_->line);
  }
  p->listitem_->type_ = p->type_->get();
  p->listitem_->accept(this);
}

void AnalyserSem::visitAss(Ass *p)
{
  /* Code For Ass Goes Here */
  cout << "Tutaj15" << endl;
  p->expr_1->accept(this);
  p->expr_2->accept(this);

  if(p->expr_2->type_ != p->expr_1->type_ && (!InformationSaver::GetInstance().classPar(p->expr_1->type_,p->expr_2->type_) && !InformationSaver::GetInstance().classPar(p->expr_1->type_,Helper::nullName)) && p->expr_1->is_lvalue_)
  {
      std::string str = "Type: " + (p->expr_1->type_.size() ?  p->expr_1->type_ : "undefined" ) + " doesn't match type: " +  p->expr_2->type_ ;
      FileSaver::GetInstance().addError(str,p->expr_1->line);
  }
  if (!p->expr_1->is_lvalue_)
  {
      std::string str = "Assignment can be done only for lvalues!";
      FileSaver::GetInstance().addError(str,p->expr_1->line);
  }
}

void AnalyserSem::visitIncr(Incr *p)
{
  /* Code For Incr Goes Here */
    cout << "Tutaj16" << endl;
  p->expr_->accept(this);
  if(p->expr_->type_ != Helper::intName)
  {
      std::string str = "Variable is not integer, so it can't be incremented.";
      FileSaver::GetInstance().addError(str,p->expr_->line);
  }
  if (!p->expr_->is_lvalue_)
  {
      std::string str = "Incrementing can be done only for lvalues!";
      FileSaver::GetInstance().addError(str,p->expr_->line);
  }
}

void AnalyserSem::visitDecr(Decr *p)
{
    cout << "Tutaj17" << endl;
    p->expr_->accept(this);
    if(p->expr_->type_ != Helper::intName)
    {
        std::string str = "Variable is not integer, so it can't be decremented.";
        FileSaver::GetInstance().addError(str,p->expr_->line);
    }
    if (!p->expr_->is_lvalue_)
    {
        std::string str = "Decrementing can be done only for lvalues!";
        FileSaver::GetInstance().addError(str,p->expr_->line);
    }
}

void AnalyserSem::visitRet(Ret *p)
{
  /* Code For Ret Goes Here */
    cout << "Tutaj18" << endl;
  p->expr_->accept(this);
  if(p->expr_->type_ == Helper::voidName)
  {
      std::string str = "Function should have non-void return.";
      FileSaver::GetInstance().addError(str,p->expr_->line);
  }
  if (!ControlFlow::getInstance().term(p->expr_->type_))
  {
      std::string str = "Function and return types are different.";
      FileSaver::GetInstance().addError(str,p->expr_->line);
  }
}

void AnalyserSem::visitVRet(VRet *p)
{
  /* Code For VRet Goes Here */
    cout << "Tutaj19" << endl;
    if (!ControlFlow::getInstance().term(Helper::voidName))
    {
        std::string str = "Function and return types are different.";
        FileSaver::GetInstance().addError(str,p->line);
    }
}

void AnalyserSem::visitCond(Cond *p)
{
  /* Code For Cond Goes Here */
  std::cout << "TUTAJ69" << std::endl;
  p->expr_->accept(this);
  if(p->expr_->type_ != Helper::boolName)
  {
      std::string str = "Condition of if should be bool.";
      FileSaver::GetInstance().addError(str,p->expr_->line);
  }
  if(!p->expr_->is_always_false_ && !p->expr_->is_always_true_)
  {
      std::cout << "TUTAJ2" << std::endl;
      InformationSaver::GetInstance().BlkEntry();
      auto par = ControlFlow::getInstance().getCurrBlk();

      ControlFlow::getInstance().newBlk();
      auto ifBlk = ControlFlow::getInstance().getCurrBlk();
      ControlFlow::getInstance().addNewNode(par,ifBlk);
      p->stmt_->accept(this);
      auto ifPar = ControlFlow::getInstance().getCurrBlk();
      ControlFlow::getInstance().newBlk();
      auto ifAfter = ControlFlow::getInstance().getCurrBlk();
      ControlFlow::getInstance().addNewNode(par,ifAfter);
      ControlFlow::getInstance().addNewNode(ifPar,ifAfter);
      InformationSaver::GetInstance().BlkExit();
  }
  else if(p->expr_->is_always_true_)
  {
      InformationSaver::GetInstance().BlkEntry();
      p->stmt_->accept(this);
      InformationSaver::GetInstance().BlkExit();
  }
  else if(p->expr_->is_always_false_)
  {
      delete p->stmt_;
  }
}

void AnalyserSem::visitCondElse(CondElse *p)
{
  /* Code For CondElse Goes Here */
    cout << "Tutaj20" << endl;
    p->expr_->accept(this);
    if(p->expr_->type_ != Helper::boolName)
    {
        std::string str = "Condition of if should be bool.";
        FileSaver::GetInstance().addError(str,p->expr_->line);
    }
    if(!p->expr_->is_always_false_ && !p->expr_->is_always_true_)
    {
        auto par = ControlFlow::getInstance().getCurrBlk();
        ControlFlow::getInstance().newBlk();
        auto ifBlk = ControlFlow::getInstance().getCurrBlk();
        cout << "par,ifBlok: " <<  par << " " << ifBlk << endl;
        ControlFlow::getInstance().addNewNode(par,ifBlk);
        p->stmt_1->accept(this);
        auto ifPar = ControlFlow::getInstance().getCurrBlk();
        ControlFlow::getInstance().newBlk();
        auto elseBlock = ControlFlow::getInstance().getCurrBlk();
        ControlFlow::getInstance().addNewNode(par,elseBlock);
        cout << "par,elseBlock: " <<  par << " " << ifBlk << endl;
        p->stmt_2->accept(this);
        auto elsePar = ControlFlow::getInstance().getCurrBlk();
        ControlFlow::getInstance().newVirtBlock(elsePar,ifPar);
        auto ifAfter = ControlFlow::getInstance().getCurrBlk();
        ControlFlow::getInstance().addNewNode(par,ifAfter);
        ControlFlow::getInstance().addNewNode(ifPar,ifAfter);
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

void AnalyserSem::visitWhile(While *p)
{
  /* Code For While Goes Here */
    cout << "Tutaj21" << endl;
  p->expr_->accept(this);
  if(p->expr_->type_ != Helper::boolName)
  {
      std::string str = "Condition of while should be bool.";
      FileSaver::GetInstance().addError(str,p->expr_->line);
  }
  if(p->expr_->is_always_true_)
  {
     ControlFlow::getInstance().newInfLoop();
  }
  else if ( p->expr_->is_always_false_)
  {
      cout << "Tutaj71" << endl;
      return;
  }
  p->stmt_->accept(this);
  if(p->expr_->is_always_true_)
  {
      ControlFlow::getInstance().endInfLoop();
  }
}

void AnalyserSem::visitForEach(ForEach *p)
{
  /* Code For ForEach Goes Here */
    cout << "Tutaj22" << endl;
  InformationSaver::GetInstance().BlkEntry();
  p->type_->accept(this);
  visitIdent(p->ident_);
  p->expr_->accept(this);
  if(p->ident_ == Helper::selfName)
  {
        std::string str = "Can't declare variable named 'self'";
        FileSaver::GetInstance().addError(str,p->line );
  }
  else if(!InformationSaver::GetInstance().newSym(p->ident_,p->type_->get(),true))
  {
      std::string str =  p->ident_ + " previously declared.";;
      FileSaver::GetInstance().addError(str,p->line );
  }
  else if(p->expr_->type_.length() <= 2)
  {
      std::string str = "Type of iterator loop doesn't match type of array";
      FileSaver::GetInstance().addError(str,p->type_->line );
  }
  else if(p->type_->get() + Helper::tableName != p->expr_->type_ && !InformationSaver::GetInstance().classPar(p->type_->get(),p->expr_->type_.substr(0, p->expr_->type_.length() - 2)))
  {
      std::string str = "Type of iterator loop doesn't match type of array";
      FileSaver::GetInstance().addError(str,p->type_->line );
  }
  auto funName = ControlFlow::getInstance().getCurFunName();
  int indx;
  try
  {
      indx = InformationSaver::GetInstance().getSymIndex((p->ident_));
  }
  catch ( const std::invalid_argument &e)
  {
      FileSaver::GetInstance().addError(e.what(),p->line );
  }
  if(!InformationSaver::GetInstance().newParamLocal(funName,p->ident_,p->type_->get(),indx))
  {
      std::string str =  "Function not found";
      FileSaver::GetInstance().addError(str,p->line );
  }
  p->index_ = indx;
  p->function_name_ = funName;
  p->stmt_->accept(this);
  InformationSaver::GetInstance().BlkExit();
}

void AnalyserSem::visitSExp(SExp *s_exp)
{
  /* Code For SExp Goes Here */
    cout << "Tutaj23" << endl;
  s_exp->expr_->accept(this);

}

void AnalyserSem::visitNoInit(NoInit *p)
{
  /* Code For NoInit Goes Here */
    cout << "Tutaj24" << endl;
    if(p->type_.substr(0,4) == Helper::voidName)
    {

        std::string str = "Can't declare variable with 'void' type";
        FileSaver::GetInstance().addError(str,p->line );
    }
    if(p->ident_ == Helper::selfName)
    {
        std::string str = "Can't declare variable named 'self'";
        FileSaver::GetInstance().addError(str,p->line );
    }
    if(!InformationSaver::GetInstance().newSym(p->ident_,p->type_))
    {
        std::string str =  p->ident_ + " previously declared.";;
        FileSaver::GetInstance().addError(str,p->line );
    }
    auto funName = ControlFlow::getInstance().getCurFunName();
    int indx;
    try
    {
        indx = InformationSaver::GetInstance().getSymIndex(p->ident_);
    }
    catch ( const std::invalid_argument &e)
    {
        FileSaver::GetInstance().addError(e.what(),p->line );

    }
    if(!InformationSaver::GetInstance().newParamLocal(funName,p->ident_,p->type_,indx))
    {
        std::string str =  "Function not found";
        FileSaver::GetInstance().addError(str,p->line );
    }
    p->index_ = indx;
    p->function_name_ = funName;
}

void AnalyserSem::visitInit(Init *p)
{
  /* Code For Init Goes Here */
    cout << "Tutaj25" << endl;
  p->expr_->accept(this);
  if(p->type_.substr(0,4) == Helper::voidName)
  {
      std::string str = "Can't declare variable with 'void' type";
      FileSaver::GetInstance().addError(str,p->line );
  }

   if(p->ident_ == Helper::selfName)
  {
      std::string str = "Can't declare variable named 'self'";
      FileSaver::GetInstance().addError(str,p->line );
  }
   if(p->expr_->type_ != p->type_ && !InformationSaver::GetInstance().classPar(p->type_,p->expr_->type_) && !InformationSaver::GetInstance().classPar(p->type_,Helper::nullName))
  {
      std::string str = "Declaration and Assignment types do not match.";
      FileSaver::GetInstance().addError(str,p->expr_->line );
  }

   if(!InformationSaver::GetInstance().newSym(p->ident_,p->type_))
  {
      std::string str =  p->ident_ + " previously declared.";;
      FileSaver::GetInstance().addError(str,p->line );
  }

  auto funName = ControlFlow::getInstance().getCurFunName();
  int indx;
  try
  {
    indx = InformationSaver::GetInstance().getSymIndex(p->ident_);
  }
  catch ( const std::invalid_argument &e)
  {
      FileSaver::GetInstance().addError(e.what(),p->line );
  }

  if(!InformationSaver::GetInstance().newParamLocal(funName,p->ident_,p->type_,indx))
  {
      std::string str =  "Function not found";
      FileSaver::GetInstance().addError(str,p->line );
  }
  p->index_ = indx;
  p->function_name_ = funName;
}

void AnalyserSem::visitInt(Int *int_)
{
  /* Code For Int Goes Here */


}

void AnalyserSem::visitStr(Str *str)
{
  /* Code For Str Goes Here */


}

void AnalyserSem::visitBool(Bool *bool_)
{
  /* Code For Bool Goes Here */


}

void AnalyserSem::visitVoid(Void *void_)
{
  /* Code For Void Goes Here */


}

void AnalyserSem::visitSimpleVarType(SimpleVarType *simple_var_type)
{
  /* Code For SimpleVarType Goes Here */
    cout << "Tutaj26" << endl;
  simple_var_type->simpletype_->accept(this);

}

void AnalyserSem::visitSimpleArrType(SimpleArrType *simple_arr_type)
{
  /* Code For SimpleArrType Goes Here */
    cout << "Tutaj27" << endl;
  simple_arr_type->simpletype_->accept(this);

}

void AnalyserSem::visitVarType(VarType *var_type)
{
  /* Code For VarType Goes Here */
    cout << "Tutaj28" << endl;
  visitIdent(var_type->ident_);

}

void AnalyserSem::visitArrType(ArrType *arr_type)
{
  /* Code For ArrType Goes Here */
    cout << "Tutaj29" << endl;
  visitIdent(arr_type->ident_);

}

void AnalyserSem::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */
    cout << "Tutaj30" << endl;
  fun->type_->accept(this);
  fun->listtype_->accept(this);

}

void AnalyserSem::visitEVar(EVar *p)
{
    cout << "Tutaj31" << endl;
  /* Code For EVar Goes Here */
  auto funcName = ControlFlow::getInstance().getCurFunName();
  int indx;
  bool ref;

  try
  {
      p->type_ = InformationSaver::GetInstance().getSymType(p->ident_);

    indx = InformationSaver::GetInstance().getSymIndex(p->ident_);
    ref = InformationSaver::GetInstance().isSymReference(p->ident_);

  }
  catch(std::invalid_argument &e)
  {
      FileSaver::GetInstance().addError(e.what(),p->line );

  }

    visitIdent(p->ident_);
  p->is_lvalue_ = true;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->has_value_ = false;
  p->is_null_ = false;

  p->index_ = indx;
  p->function_name_ = funcName;
  p->is_reference_ = ref;

}

void AnalyserSem::visitEClsVar(EClsVar *p)
{
  /* Code For EClsVar Goes Here */
    cout << "Tutaj32" << endl;
  p->expr_->accept(this);

  if (p->expr_->type_.length() > 2 && p->expr_->type_.substr(p->expr_->type_.length() - 2) == Helper::tableName)
  {
      if (p->ident_ != Helper::lengthName)
      {
          std::string str = "Variable length not found";
          FileSaver::GetInstance().addError(str,p->line );
      }
      p->type_ = Helper::intName;
      p->is_null_ = false;
      p->is_lvalue_ = false;
      p->is_always_false_ = false;
      p->is_always_true_ = false;
      p->has_value_ = false;
  }
  else
  {
      try
      {
          p->type_ = InformationSaver::GetInstance().getVarinClassType(p->expr_->type_,p->ident_);
      }
      catch(const std::invalid_argument &e)
      {
          FileSaver::GetInstance().addError(e.what(),p->line );
      }
      p->is_null_ = false;
      p->is_lvalue_ = p->expr_->is_lvalue_;
      p->is_always_false_ = false;
      p->is_always_true_ = false;
      p->has_value_ = false;
  }
}

void AnalyserSem::visitEArrVar(EArrVar *p)
{
  /* Code For EArrVar Goes Here */
    cout << "Tutaj33" << endl;
  p->expr_1->accept(this);
  p->expr_2->accept(this);
  std::string str;
  if(p->expr_2->type_ != Helper::intName)
  {
      str = "operation " + Helper::tableName + " can be only done with int parameter";
  }
  else if(p->expr_1->type_.length() > 2 && p->expr_1->type_.substr(p->expr_1->type_.length() - 2) != Helper::tableName)
  {
      str = Helper::tableName + " can be only done with array types";
  }
  if(str.size())
  {
      FileSaver::GetInstance().addError(str,p->expr_1->line );
  }
  p->type_ = p->expr_1->type_.substr(0, p->expr_1->type_.length() - 2);
  p->is_lvalue_ = p->expr_1->is_lvalue_;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->has_value_ = false;
  p->is_null_ = false;
}

void AnalyserSem::visitELitInt(ELitInt *p)
{
  /* Code For ELitInt Goes Here */
    cout << "Tutaj34" << endl;
  visitInteger(p->integer_);
  p->type_ = Helper::intName;
  p->is_lvalue_ = false;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->has_value_ = true;
  p->is_null_ = false;
  p->value_ = p->integer_;

}

void AnalyserSem::visitEString(EString *p)
{
  /* Code For EString Goes Here */
    cout << "Tutaj35" << endl;
  visitString(p->string_);
  p->type_ = Helper::stringName;
  p->is_lvalue_ = false;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->has_value_ = false;
  p->is_null_ = false;
}

void AnalyserSem::visitELitTrue(ELitTrue *p)
{
    cout << "Tutaj37" << endl;
    p->type_ = Helper::boolName;
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = true;
    p->has_value_ = false;
    p->is_null_ = false;

}

void AnalyserSem::visitELitFalse(ELitFalse *p)
{
  /* Code For ELitFalse Goes Here */
    cout << "Tutaj38" << endl;
    p->type_ = Helper::boolName;
    p->is_lvalue_ = false;
    p->is_always_false_ = true;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;

}

void AnalyserSem::visitELitNull(ELitNull *p)
{
  /* Code For ELitNull Goes Here */
    cout << "Tutaj39" << endl;
    p->type_ = Helper::nullName;
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = true;
}

void AnalyserSem::visitEApp(EApp *p)
{
  /* Code For EApp Goes Here */
    cout << "Tutaj40" << endl;
    try
    {

        p->type_ = InformationSaver::GetInstance().getFuncType(p->ident_);

    }
    catch ( const std::invalid_argument &e)
    {
        std::string str = "Function not found";
        FileSaver::GetInstance().addError(str,p->line );
    }
    visitIdent(p->ident_);
    p->listexpr_->accept(this);
    auto ar = InformationSaver::GetInstance().getFuncAr(p->ident_);
    if(p->listexpr_->size() != ar->size())
    {
        std::string str = p->ident_ + " function needs " + std::to_string(ar->size() ) + " arguments, but it gets " + std::to_string(p->listexpr_->size());
        FileSaver::GetInstance().addError(str,p->listexpr_->line );
    }
    for(int i = 0; i < min(ar->size(),p->listexpr_->size()); i++)
    {

        if(p->listexpr_->at(i)->type_ != ar->at(i)->getType() && !InformationSaver::GetInstance().classPar(ar->at(i)->getType(),p->listexpr_->at(i)->type_))
        {
            std::string str = p->ident_ +  " function's " + std::to_string(i+1) + " argument should be " + ar->at(i)->getType() + ", but it is " + p->listexpr_->at(i)->type_;

            FileSaver::GetInstance().addError(str,p->listexpr_->at(i)->line );
        }
    }
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;
    if(p->ident_ == Helper::errorName)
    {
        ControlFlow::getInstance().term(ControlFlow::getInstance().getCurFunType());
    }
}

void AnalyserSem::visitEClsApp(EClsApp *p)
{
  /* Code For EClsApp Goes Here */
    cout << "Tutaj41" << endl;
  p->expr_->accept(this);
  try
  {
      p->type_ = InformationSaver::GetInstance().getMethodType(p->expr_->type_,p->ident_);

      p->owner_ = InformationSaver::GetInstance().getinWhichClassisMethod(p->expr_->type_,p->ident_);
  }
  catch (const std::invalid_argument &e)
  {
      std::string str = "Function not found";
      FileSaver::GetInstance().addError(str,p->line );
  }
  visitIdent(p->ident_);
  p->listexpr_->accept(this);
  auto ar = InformationSaver::GetInstance().getMethodAr(p->expr_->type_,p->ident_);
  if(p->listexpr_->size() != ar->size() -1)
  {
      std::string str = p->ident_ + " function needs " + std::to_string(ar->size() -1 ) + " arguments, but it only gets " + std::to_string(p->listexpr_->size());
      FileSaver::GetInstance().addError(str,p->listexpr_->line );

  }

  for(int i = 1; i < min(ar->size(),p->listexpr_->size()+1); i++)
  {
      if(p->listexpr_->at(i-1)->type_ != ar->at(i)->getType() && !InformationSaver::GetInstance().classPar(ar->at(i)->getType(),p->listexpr_->at(i-1)->type_))
      {
          std::string str = p->ident_ + " function's " + std::to_string(i) + " argument should be " + ar->at(i)->getType() + ", but it is" + p->listexpr_->at(i-1)->type_;

          FileSaver::GetInstance().addError(str,p->listexpr_->at(i-1)->line );
      }
  }
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;
}

void AnalyserSem::visitENeg(ENeg *p)
{
  /* Code For ENeg Goes Here */
    cout << "Tutaj42" << endl;
  p->expr_->accept(this);
  p->type_ = Helper::intName;
  if(p->expr_->type_ != Helper::intName)
  {
      std::string str = "Expressions should be of type int, if we use 'neg' operator";
      FileSaver::GetInstance().addError(str,p->expr_->line );
  }
  p->is_lvalue_ = false;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->has_value_ = p->expr_->has_value_;
  p->value_ = -p->expr_->value_;
  p->is_null_ = false;
}

void AnalyserSem::visitENot(ENot *p)
{
  /* Code For ENot Goes Here */
    cout << "Tutaj43" << endl;
  p->expr_->accept(this);
  p->type_ = Helper::boolName;
  if(p->expr_->type_ != Helper::boolName)
  {

      std::string str = "Expressions should be of type bool, if we use 'not' operator";
      FileSaver::GetInstance().addError(str,p->expr_->line );
  }
  p->is_lvalue_ = false;
  if (p->expr_->is_always_false_)
  {
      p->is_always_false_ = false;
      p->is_always_true_ = true;
  }
  else if (p->expr_->is_always_true_)
  {
      p->is_always_false_ = true;
      p->is_always_true_ = false;
  }
  else
  {
      p->is_always_false_ = false;
      p->is_always_true_ = false;
  }
  p->has_value_ = false;
  p->is_null_ = false;
}

void AnalyserSem::visitEVarNew(EVarNew *p)
{
  /* Code For EVarNew Goes Here */
    cout << "Tutaj44" << endl;
    if(!InformationSaver::GetInstance().checkType(p->ident_))
    {
        std::string str = "Variable \"" + p->ident_ +"\" has a bad type.";
        FileSaver::GetInstance().addError(str,p->line );
    }

    p->type_ = p->ident_;

    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;
}

void AnalyserSem::visitEVarSimpleNew(EVarSimpleNew *p)
{
  /* Code For EVarSimpleNew Goes Here */
    cout << "Tutaj45" << endl;
  std::string str = "operation new can be only done for arrays and structs/classes";
    FileSaver::GetInstance().addError(str,p->line );
    p->type_ = p->simpletype_->get();
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;
}

void AnalyserSem::visitEArrNew(EArrNew *p)
{
  /* Code For EArrNew Goes Here */
    cout << "Tutaj46" << endl;
    p->expr_->accept(this);
    if(p->expr_->type_ != Helper::intName)
    {
        std::string str = "operation new can be only done with int parameter";
        FileSaver::GetInstance().addError(str,p->expr_->line );
    }
    if(!InformationSaver::GetInstance().checkType(p->ident_))
    {
        std::string str = "Variable \"" + p->ident_ +"\" has a bad type.";
        FileSaver::GetInstance().addError(str,p->line );
    }
    p->type_ = p->ident_ + Helper::tableName;
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;
}

void AnalyserSem::visitEArrSimpleNew(EArrSimpleNew *p) {

    /* Code For EArrSimpleNew Goes Here */
    cout << "Tutaj47" << endl;
    p->simpletype_->accept(this);
    p->expr_->accept(this);
    if (p->expr_->type_ != Helper::intName) {
        std::string str = "operation new can be only done with int parameter";
        FileSaver::GetInstance().addError(str, p->expr_->line);
    }
    p->type_ = p->simpletype_->get() + Helper::tableName;
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = false;
}

void AnalyserSem::visitEVarCast(EVarCast *p)
{
  /* Code For EVarCast Goes Here */
    cout << "Tutaj48" << endl;
    if(!InformationSaver::GetInstance().checkType(p->ident_))
    {
        std::string str = "Variable \"" + p->ident_ +"\" has a bad type.";
        FileSaver::GetInstance().addError(str,p->line );
    }
    p->expr_->accept(this);
    if(!p->expr_->is_null_)
    {
        std::string str = "Casting not null value is not allowed";
        FileSaver::GetInstance().addError(str,p->line );
    }
    p->type_ = p->ident_;
    p->is_lvalue_ = false;
    p->is_always_false_ = false;
    p->is_always_true_ = false;
    p->has_value_ = false;
    p->is_null_ = true;
}

void AnalyserSem::visitEVarSimpleCast(EVarSimpleCast *p)
{
  /* Code For EVarSimpleCast Goes Here */
    cout << "Tutaj49" << endl;
  std::string str = "Cast operation is only allowed for classes";
  FileSaver::GetInstance().addError(str,p->line );

}

void AnalyserSem::visitEArrCast(EArrCast *p)
{
  /* Code For EArrCast Goes Here */
    cout << "Tutaj50" << endl;
  std::string str = "Cast operation is only allowed for classes";
  FileSaver::GetInstance().addError(str,p->line );

}

void AnalyserSem::visitEArrSimpleCast(EArrSimpleCast *p)
{
  /* Code For EArrSimpleCast Goes Here */
    cout << "Tutaj51" << endl;
  std::string str = "Cast operation is only allowed for classes";
  FileSaver::GetInstance().addError(str,p->line );


}

void AnalyserSem::visitEMul(EMul *p)
{
  /* Code For EMul Goes Here */
    cout << "Tutaj52" << endl;
  p->expr_1->accept(this);
  p->mulop_->accept(this);
  p->expr_2->accept(this);
  if (p->expr_1->type_ != Helper::intName || p->expr_2->type_ != Helper::intName)
  {
        std::string str = "Expressions should be of type int, if we use 'mul' operator";
        FileSaver::GetInstance().addError(str,p->expr_1->line );
  }
  p->type_ = Helper::intName;
  p->is_lvalue_ = false;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->is_null_ = false;
  auto mulFlag = dynamic_cast<Times*>(p->mulop_);
  auto divFlag = dynamic_cast<Div*>(p->mulop_);
  auto modFlag = dynamic_cast<Mod*>(p->mulop_);
  p->has_value_ = p->expr_1->has_value_ && p->expr_2->has_value_;
  if (mulFlag != nullptr && p->has_value_)
  {
       p->value_ = p->expr_1->value_ * p->expr_2->value_;
  }
  else if (modFlag != nullptr && p->has_value_)
  {
      p->value_ = p->expr_1->value_ % p->expr_2->value_;
  }
  else if(divFlag != nullptr && p->has_value_)
  {
      cout << "Tutaj72" << endl;
      cout << p->expr_2->value_ << endl;
      if(!p->expr_2->value_)
      {
          std::string str = "Divison by 0 is not allowed";
          FileSaver::GetInstance().addError(str,p->expr_1->line );
          return;
      }
      p->value_ = p->expr_1->value_ / p->expr_2->value_;
  }
}

void AnalyserSem::visitEAdd(EAdd *p)
{
  /* Code For EAdd Goes Here */
    cout << "Tutaj54" << endl;
  p->expr_1->accept(this);
  p->addop_->accept(this);
  p->expr_2->accept(this);
  auto plusFlag = dynamic_cast<Plus*>(p->addop_);
  if(p->expr_1->type_ == Helper::stringName && p->expr_2->type_ == Helper::stringName && plusFlag != nullptr)
  {
      p->type_ = Helper::stringName;
  }
  else if(p->expr_1->type_ == Helper::intName && p->expr_2->type_ == Helper::intName)
  {
      p->type_ = Helper::intName;
  }
  else
  {
        if(plusFlag != nullptr)
        {
            std::string str  = "Expressions should be of type string or int, if we use 'add' operator";
            FileSaver::GetInstance().addError(str,p->expr_1->line);
        }
        else
        {
            std::string str  = "Expressions should be of type int, if we use 'sub' operator";
            FileSaver::GetInstance().addError(str,p->expr_1->line);
        }
  }
  p->is_lvalue_ = false;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  p->is_null_ = false;
  p->has_value_ = p->expr_1->has_value_ && p->expr_2->has_value_;

  if ( plusFlag != nullptr)
  {
      p->value_ = p->expr_1->value_ + p->expr_2->value_;
  }
  else
  {
      p->value_ = p->expr_1->value_ - p->expr_2->value_;
  }
}

void AnalyserSem::visitERel(ERel *p)
{
  /* Code For ERel Goes Here */
    cout << "Tutaj55" << endl;
  p->expr_1->accept(this);
  p->relop_->accept(this);
  p->expr_2->accept(this);
  auto eqFlag = dynamic_cast<EQU*>(p->relop_);
  auto neqFlag = dynamic_cast<NE*>(p->relop_);
  auto ltFlag = dynamic_cast<LTH*>(p->relop_);
  auto leFlag = dynamic_cast<LE*>(p->relop_);
  auto gtFlag = dynamic_cast<GTH*>(p->relop_);
  auto geFlag = dynamic_cast<GE*>(p->relop_);
  bool check = false;
  p->is_always_false_ = false;
  p->is_always_true_ = false;
  if(eqFlag != nullptr || neqFlag != nullptr)
  {
    cout << p->expr_1->type_ << " " << p->expr_2->type_ << endl;
    if(p->expr_1->type_ == p->expr_2->type_ && (p->expr_1->is_null_ || p->expr_2->is_null_))
      {
          check = true;
      }
      if (p->expr_1->type_ == Helper::intName &&p->expr_2->type_ == Helper::intName)
      {
		  check = true;
          if (p->expr_1->has_value_ && p->expr_2->has_value_)
          {

            if (eqFlag != nullptr)
              {
                  if (p->expr_1->value_ == p->expr_2->value_)
                  {
                      p->is_always_false_ = false;
                      p->is_always_true_ = true;
                  }
                  else
                  {
                      p->is_always_false_ = true;
                      p->is_always_true_ = false;
                  }
              }
              else
              {
                  if (p->expr_1->value_ == p->expr_2->value_)
                  {
                      p->is_always_false_ = true;
                      p->is_always_true_ = false;
                  }
                  else
                  {
                      p->is_always_false_ = false;
                      p->is_always_true_ = true;
                  }
              }
          }
      }
      else if (p->expr_1->type_ == Helper::boolName && p->expr_2->type_ == Helper::boolName)
      {
          check = true;
          if (eqFlag != nullptr)
          {
              if ((p->expr_1->is_always_true_ && p->expr_2->is_always_true_) || (p->expr_1->is_always_false_ && p->expr_2->is_always_false_))
              {
                  p->is_always_false_ = false;
                  p->is_always_true_ = true;
              }
              else if ((p->expr_1->is_always_true_ && p->expr_2->is_always_false_) || (p->expr_1->is_always_false_ && p->expr_2->is_always_true_))
              {
                  p->is_always_false_ = true;
                  p->is_always_true_ = false;
              }
          }

          if (neqFlag != nullptr)
          {
              if ((p->expr_1->is_always_true_ && p->expr_2->is_always_true_) ||(p->expr_1->is_always_false_ && p->expr_2->is_always_false_))
              {
                  p->is_always_false_ = true;
                  p->is_always_true_ = false;
              }
              else if ((p->expr_1->is_always_true_ && p->expr_2->is_always_false_) || (p->expr_1->is_always_false_ && p->expr_2->is_always_true_))
              {
                  p->is_always_false_ = false;
                  p->is_always_true_ = true;
              }
          }
      }
      else if (p->expr_1->type_ == Helper::stringName && p->expr_2->type_ == Helper::stringName)
      {
          check = true;
      }
      else if (p->expr_1->type_ == p->expr_2->type_)
        {
        	check = true;
        }
      if(!check)
      {
          std::string str = "Expressions should be the same type, if we compare them, but they are: " + p->expr_1->type_ + " and " + p->expr_2->type_;
          FileSaver::GetInstance().addError(str,p->expr_1->line);
      }
  }
  else if(p->expr_1->type_ == Helper::intName && p->expr_2->type_ == Helper::intName)
  {
      check = true;
      if(p->expr_1->has_value_ && p->expr_2->has_value_)
      {
        //cout <<  p->expr_1->value_ << " "
        if(ltFlag != nullptr)
          {
              if (p->expr_1->value_ < p->expr_2->value_)
              {
                  p->is_always_false_ = false;
                  p->is_always_true_ = true;
              }
              else
              {
                  p->is_always_false_ = true;
                  p->is_always_true_ = false;
              }
          }
          else if (leFlag != nullptr)
          {
              if (p->expr_1->value_ <= p->expr_2->value_)
              {
                  p->is_always_false_ = false;
                  p->is_always_true_ = true;
              }
              else
              {
                  p->is_always_false_ = true;
                  p->is_always_true_ = false;
              }
          }
          else if (gtFlag != nullptr)
          {
            cout << "TUTAJ XD" << endl;
            if (p->expr_1->value_ > p->expr_2->value_)
              {
                  p->is_always_false_ = false;
                  p->is_always_true_ = true;
              }
              else
              {
                  p->is_always_false_ = true;
                  p->is_always_true_ = false;
              }
          }
          else if (geFlag != nullptr)
          {
              if (p->expr_1->value_ >= p->expr_2->value_)
              {
                  p->is_always_false_ = false;
                  p->is_always_true_ = true;
              }
              else
              {
                  p->is_always_false_ = true;
                  p->is_always_true_ = false;
              }
          }
      }
  }
 if (!check && eqFlag == nullptr && neqFlag == nullptr)
 {
     std::string str = "Expressions should be of type int, if we use 'rel' operator";
     FileSaver::GetInstance().addError(str,p->expr_1->line);
 }
 p->type_ = Helper::boolName;
 p->is_lvalue_ = false;
 p->has_value_ = false;
 p->is_null_ = false;
}

void AnalyserSem::visitEAnd(EAnd *p)
{
  /* Code For EAnd Goes Here */
    cout << "Tutaj56" << endl;
  p->expr_1->accept(this);
  p->expr_2->accept(this);
  if(p->expr_1->type_ != Helper::boolName || p->expr_2->type_ != Helper::boolName)
  {
      std::string str = "Expressions should be of type bool, if we use 'and' operator";
      FileSaver::GetInstance().addError(str,p->expr_1->line);
  }
  p->type_ = Helper::boolName;
  p->is_lvalue_ = false;
  if (p->expr_1->is_always_false_ && p->expr_2->is_always_false_)
  {
      p->is_always_false_ = true;
      p->is_always_true_ = false;
  }
  else if (p->expr_1->is_always_true_ && p->expr_2->is_always_true_)
  {
      p->is_always_false_ = false;
      p->is_always_true_ = true;
  }
  else
  {
      p->is_always_false_ = false;
      p->is_always_true_ = false;
  }
  p->has_value_ = false;
  p->is_null_ = false;
}

void AnalyserSem::visitEOr(EOr *p)
{
  /* Code For EOr Goes Here */
    cout << "Tutaj57" << endl;
  p->expr_1->accept(this);
  p->expr_2->accept(this);
  if(p->expr_1->type_ != Helper::boolName || p->expr_2->type_ != Helper::boolName)
  {
      std::string str = "Expressions should be of type bool, if we use 'or' operator";
      FileSaver::GetInstance().addError(str,p->expr_1->line);
  }
  p->type_ = Helper::boolName;
  p->is_lvalue_ = false;
    if (p->expr_1->is_always_true_ && p->expr_2->is_always_true_)
    {
        p->is_always_false_ = false;
        p->is_always_true_ = true;
    }
    else if (p->expr_1->is_always_false_ && p->expr_2->is_always_false_)
    {
        p->is_always_false_ = true;
        p->is_always_true_ = false;
    }
    else
    {
        p->is_always_false_ = false;
        p->is_always_true_ = false;
    }

    p->has_value_ = false;
    p->is_null_ = false;
}

void AnalyserSem::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void AnalyserSem::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void AnalyserSem::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void AnalyserSem::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void AnalyserSem::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void AnalyserSem::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void AnalyserSem::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void AnalyserSem::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void AnalyserSem::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void AnalyserSem::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void AnalyserSem::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void AnalyserSem::visitListClsFld(ListClsFld *list_cls_fld)
{
  for (ListClsFld::iterator i = list_cls_fld->begin() ; i != list_cls_fld->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void AnalyserSem::visitListTopDef(ListTopDef *list_top_def)
{
  for (ListTopDef::iterator i = list_top_def->begin() ; i != list_top_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void AnalyserSem::visitListIdent(ListIdent *list_ident)
{
  for (ListIdent::iterator i = list_ident->begin() ; i != list_ident->end() ; ++i)
  {
    visitIdent(*i) ;
  }
}

void AnalyserSem::visitListArg(ListArg *list_arg)
{
  for (ListArg::iterator i = list_arg->begin() ; i != list_arg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void AnalyserSem::visitListStmt(ListStmt *list_stmt)
{
    cout << "Tutaj58" << endl;
    for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
  {
      if(ControlFlow::getInstance().getIsIf())
      {
          ControlFlow::getInstance().addMissBlk();
      }
      (*i)->accept(this);
  }
}

void AnalyserSem::visitListItem(ListItem *p)
{
    cout << "Tutaj59" << endl;
    for (ListItem::iterator i = p->begin() ; i != p->end() ; ++i)
  {
      (*i)->type_ = p->type_;
      (*i)->accept(this);
  }
}

void AnalyserSem::visitListType(ListType *list_type)
{
    cout << "Tutaj60" << endl;
  for (ListType::iterator i = list_type->begin() ; i != list_type->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void AnalyserSem::visitListExpr(ListExpr *list_expr)
{
  for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void AnalyserSem::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void AnalyserSem::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void AnalyserSem::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void AnalyserSem::visitString(String x)
{
    cout << "Tutaj61" << endl;
    InformationSaver::GetInstance().newString(x);
}

void AnalyserSem::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



