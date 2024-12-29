/*** BNFC-Generated Visitor Design Pattern Analyser. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Analyser.h"



void Analyser::visitProgram(Program *t)
{
    t->accept(this);
}
void Analyser::visitTopDef(TopDef *t) {} //abstract class
void Analyser::visitClsFld(ClsFld *t) {} //abstract class
void Analyser::visitArg(Arg *t) {} //abstract class
void Analyser::visitBlock(Block *t) {} //abstract class
void Analyser::visitStmt(Stmt *t) {} //abstract class
void Analyser::visitItem(Item *t) {} //abstract class
void Analyser::visitSimpleType(SimpleType *t) {} //abstract class
void Analyser::visitType(Type *t) {} //abstract class
void Analyser::visitExpr(Expr *t) {} //abstract class
void Analyser::visitAddOp(AddOp *t) {} //abstract class
void Analyser::visitMulOp(MulOp *t) {} //abstract class
void Analyser::visitRelOp(RelOp *t) {} //abstract class

void Analyser::visitProg(Prog *p)
{
  /* Code For Prog Goes Here */

  p->listtopdef_->accept(this);

}

void Analyser::visitFnDef(FnDef *p)
{
  /* Code For FnDef Goes Here */


}

void Analyser::visitClsDef(ClsDef *p)
{
  /* Code For ClsDef Goes Here */

  if(!InformationSaver::GetInstance().ifClassExists(p->ident_))
  {
      ControlFlow::getInstance().setClass(p->ident_);
      p->listclsfld_->accept(this);
      InformationSaver::GetInstance().newClassExists(p->ident_);
  }

}
void Analyser::visitSExpParen(SExpParen *s_exp_paren)
{
    /* Code For SExpParen Goes Here */

    s_exp_paren->expr_->accept(this);

}
void Analyser::visitInhClsDef(InhClsDef *p)
{
  /* Code For InhClsDef Goes Here */
  if(!InformationSaver::GetInstance().ifClassExists(p->ident_1) && InformationSaver::GetInstance().ifClassExists(p->ident_2))
  {

      ControlFlow::getInstance().setClass(p->ident_1);
      InformationSaver::GetInstance().addSymbFromParent(p->ident_1,p->ident_2);
      p->listclsfld_->accept(this);
      InformationSaver::GetInstance().newClassExists(p->ident_1);

  }
}

void Analyser::visitVarDef(VarDef *p)
{
  /* Code For VarDef Goes Here */
  if(!InformationSaver::GetInstance().checkType(p->type_->get()))
  {
      std::string str = p->type_->get() + " is not a valid type name";
      FileSaver::GetInstance().addError(str,p->type_->line);
  }

  if(p->type_->get().substr(0,4) == Helper::voidName)
  {
      std::string str = "Type shouldn't be void";
      FileSaver::GetInstance().addError(str,p->type_->line);
  }
  auto name = ControlFlow::getInstance().getCurClass();

  for (const auto & ident : *(p->listident_))
  {
      if(!InformationSaver::GetInstance().newClassVar(name,ident,p->type_->get()))
      {
          std::string str = "\"" + ident +"\" was declared previously";
          FileSaver::GetInstance().addError(str,p->line);
      }
  }
}

void Analyser::visitMetDef(MetDef *p)
{
  /* Code For MetDef Goes Here */

  std::string name = ControlFlow::getInstance().getCurClass();
  visitIdent(p->ident_);
  p->listarg_->insert(p->listarg_->begin(), new Ar(new VarType(name), "self"));
  if(!InformationSaver::GetInstance().newClassMethod(name,p->ident_,p->type_,p->listarg_))
  {
    std:: string str = "Method \"" + p->ident_ +"\"" +" was declared previously";
    FileSaver::GetInstance().addError(str,p->line);

  }
 if(!InformationSaver::GetInstance().newFunc(name +"." + p->ident_,p->type_,p->listarg_))
 {
    std:: string str = "Method \"" + p->ident_ +"\"" +" was declared previously";
    FileSaver::GetInstance().addError(str,p->line);
 }

  p->listarg_->accept(this);
  p->block_->accept(this);

}

void Analyser::visitAr(Ar *p)
{
  /* Code For Ar Goes Here */
  InformationSaver::GetInstance().newMethodLocal(p->ident_);

}

void Analyser::visitBlk(Blk *blk)
{
  /* Code For Blk Goes Here */

  blk->liststmt_->accept(this);

}

void Analyser::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void Analyser::visitBStmt(BStmt *b_stmt)
{
  /* Code For BStmt Goes Here */

  b_stmt->block_->accept(this);

}

void Analyser::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */

  decl->type_->accept(this);
  decl->listitem_->accept(this);

}

void Analyser::visitAss(Ass *p)
{
  /* Code For Ass Goes Here */
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);
  p->expr_1->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitIncr(Incr *p)
{
  /* Code For Incr Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitDecr(Decr *p)
{
  /* Code For Decr Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitRet(Ret *p)
{
  /* Code For Ret Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitVRet(VRet *v_ret)
{
  /* Code For VRet Goes Here */


}

void Analyser::visitCond(Cond *p)
{
  /* Code For Cond Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);
  p->stmt_->accept(this);

}

void Analyser::visitCondElse(CondElse *p)
{
  /* Code For CondElse Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);
  p->stmt_1->accept(this);
  p->stmt_2->accept(this);

}

void Analyser::visitWhile(While *p)
{
  /* Code For While Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);
  p->stmt_->accept(this);

}

void Analyser::visitForEach(ForEach *p)
{
  /* Code For ForEach Goes Here */

  p->type_->accept(this);
  visitIdent(p->ident_);
  InformationSaver::GetInstance().newMethodLocal(p->ident_);
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);
  p->stmt_->accept(this);

}

void Analyser::visitSExp(SExp *p)
{
  /* Code For SExp Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitNoInit(NoInit *p)
{
  /* Code For NoInit Goes Here */

  InformationSaver::GetInstance().newMethodLocal(p->ident_);

}

void Analyser::visitInit(Init *p)
{
  /* Code For Init Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);
  InformationSaver::GetInstance().newMethodLocal(p->ident_);
}

void Analyser::visitInt(Int *int_)
{
  /* Code For Int Goes Here */


}

void Analyser::visitStr(Str *str)
{
  /* Code For Str Goes Here */


}

void Analyser::visitBool(Bool *bool_)
{
  /* Code For Bool Goes Here */


}

void Analyser::visitVoid(Void *void_)
{
  /* Code For Void Goes Here */


}

void Analyser::visitSimpleVarType(SimpleVarType *simple_var_type)
{
  /* Code For SimpleVarType Goes Here */

  simple_var_type->simpletype_->accept(this);

}

void Analyser::visitSimpleArrType(SimpleArrType *simple_arr_type)
{
  /* Code For SimpleArrType Goes Here */

  simple_arr_type->simpletype_->accept(this);

}

void Analyser::visitVarType(VarType *var_type)
{
  /* Code For VarType Goes Here */

  visitIdent(var_type->ident_);

}

void Analyser::visitArrType(ArrType *arr_type)
{
  /* Code For ArrType Goes Here */

  visitIdent(arr_type->ident_);

}

void Analyser::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  fun->type_->accept(this);
  fun->listtype_->accept(this);

}

void Analyser::visitEVar(EVar *e_var)
{
  /* Code For EVar Goes Here */


}

void Analyser::visitEClsVar(EClsVar *p)
{
  /* Code For EClsVar Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);


}

void Analyser::visitEArrVar(EArrVar *p)
{
  /* Code For EArrVar Goes Here */
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);
  p->expr_1->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitELitInt(ELitInt *e_lit_int)
{
  /* Code For ELitInt Goes Here */


}

void Analyser::visitEString(EString *e_string)
{
  /* Code For EString Goes Here */


}

void Analyser::visitELitTrue(ELitTrue *e_lit_true)
{
  /* Code For ELitTrue Goes Here */


}

void Analyser::visitELitFalse(ELitFalse *e_lit_false)
{
  /* Code For ELitFalse Goes Here */


}

void Analyser::visitELitNull(ELitNull *e_lit_null)
{
  /* Code For ELitNull Goes Here */


}

void Analyser::visitEApp(EApp *e_app)
{
  /* Code For EApp Goes Here */

  visitIdent(e_app->ident_);
  e_app->listexpr_->accept(this);

}

void Analyser::visitEClsApp(EClsApp *p)
{
  /* Code For EClsApp Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->listexpr_->accept(this);

}

void Analyser::visitENeg(ENeg *p)
{
  /* Code For ENeg Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitENot(ENot *p)
{
  /* Code For ENot Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitEVarNew(EVarNew *e_var_new)
{
  /* Code For EVarNew Goes Here */


}

void Analyser::visitEVarSimpleNew(EVarSimpleNew *e_var_simple_new)
{
  /* Code For EVarSimpleNew Goes Here */


}

void Analyser::visitEArrNew(EArrNew *p)
{
  /* Code For EArrNew Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitEArrSimpleNew(EArrSimpleNew *p)
{
  /* Code For EArrSimpleNew Goes Here */
  p->expr_ = findExpression(p->expr_);
  p->simpletype_->accept(this);
  p->expr_->accept(this);

}

void Analyser::visitEVarCast(EVarCast *p)
{
  /* Code For EVarCast Goes Here */

  p->expr_ = findExpression(p->expr_);
  p->expr_->accept(this);

}

void Analyser::visitEVarSimpleCast(EVarSimpleCast *e_var_simple_cast)
{
  /* Code For EVarSimpleCast Goes Here */


}

void Analyser::visitEArrCast(EArrCast *e_arr_cast)
{
  /* Code For EArrCast Goes Here */


}

void Analyser::visitEArrSimpleCast(EArrSimpleCast *e_arr_simple_cast)
{
  /* Code For EArrSimpleCast Goes Here */
}

void Analyser::visitEMul(EMul *p)
{
  /* Code For EMul Goes Here */
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);
  p->expr_1->accept(this);
  p->mulop_->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitEAdd(EAdd *p)
{
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);

  p->expr_1->accept(this);
  p->addop_->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitERel(ERel *p)
{
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);

  p->expr_1->accept(this);
  p->relop_->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitEAnd(EAnd *p)
{
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);

  p->expr_1->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitEOr(EOr *p)
{
  p->expr_1 = findExpression(p->expr_1);
  p->expr_2 = findExpression(p->expr_2);
  p->expr_1->accept(this);
  p->expr_2->accept(this);

}

void Analyser::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void Analyser::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void Analyser::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void Analyser::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void Analyser::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void Analyser::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void Analyser::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void Analyser::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void Analyser::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void Analyser::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void Analyser::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void Analyser::visitListClsFld(ListClsFld *list_cls_fld)
{
  for (ListClsFld::iterator i = list_cls_fld->begin() ; i != list_cls_fld->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Analyser::visitListTopDef(ListTopDef *list_top_def)
{
  for (ListTopDef::iterator i = list_top_def->begin() ; i != list_top_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Analyser::visitListIdent(ListIdent *list_ident)
{
  for (ListIdent::iterator i = list_ident->begin() ; i != list_ident->end() ; ++i)
  {
    visitIdent(*i) ;
  }
}

void Analyser::visitListArg(ListArg *list_arg)
{
  for (ListArg::iterator i = list_arg->begin() ; i != list_arg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Analyser::visitListStmt(ListStmt *list_stmt)
{
  for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Analyser::visitListItem(ListItem *list_item)
{
  for (ListItem::iterator i = list_item->begin() ; i != list_item->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Analyser::visitListType(ListType *list_type)
{
  for (ListType::iterator i = list_type->begin() ; i != list_type->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Analyser::visitListExpr(ListExpr *list_expr)
{
  for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
  {
        *(i) = findExpression(*i);
      (*i)->accept(this);
  }
}


void Analyser::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Analyser::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Analyser::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Analyser::visitString(String x)
{
  /* Code for String Goes Here */
}

void Analyser::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}

Expr* Analyser::findExpression(Expr * p)
{
    EVar * eVar = dynamic_cast<EVar *>(p);
    EApp * eApp = dynamic_cast<EApp *>(p);
    Expr * tempExpr = p;
    if(eVar != nullptr)
    {

        if(!InformationSaver::GetInstance().funLocalifExists(eVar->ident_))
        {

            tempExpr = new EClsVar(new EVar("self"),eVar->ident_);

            delete p;
            return tempExpr;
        }
    }
    if(eApp != nullptr)
    {
        try
        {

            InformationSaver::GetInstance().getFuncType(eApp->ident_);
        }
        catch (const std::invalid_argument &e)
        {

            tempExpr = new EClsApp(new EVar("self"),eApp->ident_,eApp->listexpr_->clone());
            delete p;
            return tempExpr;
        }
    }
    return tempExpr;
}

