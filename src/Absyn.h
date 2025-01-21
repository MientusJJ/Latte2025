#ifndef ABSYN_HEADER
#define ABSYN_HEADER

#include<string>
#include<vector>

//C++ Abstract Syntax Interface generated by the BNF Converter.

/********************   TypeDef Section    ********************/

typedef int Integer;
typedef char Char;
typedef double Double;
typedef std::string String;
typedef std::string Ident;




/********************   Forward Declarations    ********************/

class Program;
class TopDef;
class ClsFld;
class Arg;
class Block;
class Stmt;
class Item;
class SimpleType;
class Type;
class Expr;
class AddOp;
class MulOp;
class RelOp;
class Prog;
class FnDef;
class ClsDef;
class InhClsDef;
class VarDef;
class MetDef;
class Ar;
class Blk;
class Empty;
class BStmt;
class Decl;
class NoInit;
class Init;
class Ass;
class Incr;
class Decr;
class Ret;
class VRet;
class Cond;
class CondElse;
class While;
class ForEach;
class SExp;
class SExpParen;
class Int;
class Str;
class Bool;
class Void;
class SimpleVarType;
class SimpleArrType;
class VarType;
class ArrType;
class Fun;
class EVar;
class EClsVar;
class EArrVar;
class ELitInt;
class EString;
class ELitTrue;
class ELitFalse;
class ELitNull;
class EApp;
class EClsApp;
class ENeg;
class ENot;
class EVarNew;
class EVarSimpleNew;
class EArrNew;
class EArrSimpleNew;
class EVarCast;
class EVarSimpleCast;
class EArrCast;
class EArrSimpleCast;
class EMul;
class EAdd;
class ERel;
class EAnd;
class EOr;
class Plus;
class Minus;
class Times;
class Div;
class Mod;
class LTH;
class LE;
class GTH;
class GE;
class EQU;
class NE;
class ListClsFld;
class ListTopDef;
class ListIdent;
class ListArg;
class ListStmt;
class ListItem;
class ListType;
class ListExpr;


/********************   Visitor Interfaces    ********************/
class Visitor
{
public:
  virtual ~Visitor() {}
    virtual void visitProgram(Program *p)  {};
    virtual void visitTopDef(TopDef *p)  {};
    virtual void visitClsFld(ClsFld *p)  {};
    virtual void visitArg(Arg *p)  {};
    virtual void visitBlock(Block *p)  {};
    virtual void visitStmt(Stmt *p) {};
    virtual void visitItem(Item *p)  {};
    virtual void visitSimpleType(SimpleType *p)  {};
    virtual void visitType(Type *p)  {};
    virtual void visitExpr(Expr *p)  {};
    virtual void visitSExpParen(SExpParen *p) {};
    virtual void visitAddOp(AddOp *p)  {};
    virtual void visitMulOp(MulOp *p)  {};
    virtual void visitRelOp(RelOp *p)  {};
    virtual void visitProg(Prog *p)  {};
    virtual void visitFnDef(FnDef *p)  {};
    virtual void visitClsDef(ClsDef *p)  {};
    virtual void visitInhClsDef(InhClsDef *p)  {};
    virtual void visitVarDef(VarDef *p)  {};
    virtual void visitMetDef(MetDef *p)  {};
    virtual void visitAr(Ar *p)  {};
    virtual void visitBlk(Blk *p) {};
    virtual void visitEmpty(Empty *p)  {};
    virtual void visitBStmt(BStmt *p) {};
    virtual void visitDecl(Decl *p)  {};
    virtual void visitNoInit(NoInit *p) {};
    virtual void visitInit(Init *p)  {};
    virtual void visitAss(Ass *p)  {};
    virtual void visitIncr(Incr *p)  {};
    virtual void visitDecr(Decr *p)  {};
    virtual void visitRet(Ret *p)  {};
    virtual void visitVRet(VRet *p)  {};
    virtual void visitCond(Cond *p)  {};
    virtual void visitCondElse(CondElse *p)  {};
    virtual void visitWhile(While *p)  {};
    virtual void visitForEach(ForEach *p)  {};
    virtual void visitSExp(SExp *p)  {};
    virtual void visitInt(Int *p)  {};
    virtual void visitStr(Str *p)  {};
    virtual void visitBool(Bool *p)  {};
    virtual void visitVoid(Void *p)  {};
    virtual void visitSimpleVarType(SimpleVarType *p)  {};
    virtual void visitSimpleArrType(SimpleArrType *p)  {};
    virtual void visitVarType(VarType *p)  {};
    virtual void visitArrType(ArrType *p)  {};
    virtual void visitFun(Fun *p)  {};
    virtual void visitEVar(EVar *p)  {};
    virtual void visitEClsVar(EClsVar *p)  {};
    virtual void visitEArrVar(EArrVar *p)  {};
    virtual void visitELitInt(ELitInt *p) {};
    virtual void visitEString(EString *p)  {};
    virtual void visitELitTrue(ELitTrue *p) {};
    virtual void visitELitFalse(ELitFalse *p)  {};
    virtual void visitELitNull(ELitNull *p)  {};
    virtual void visitEApp(EApp *p)  {};
    virtual void visitEClsApp(EClsApp *p)  {};
    virtual void visitENeg(ENeg *p)  {};
    virtual void visitENot(ENot *p)  {};
    virtual void visitEVarNew(EVarNew *p)  {};
    virtual void visitEVarSimpleNew(EVarSimpleNew *p)  {};
    virtual void visitEArrNew(EArrNew *p)  {};
    virtual void visitEArrSimpleNew(EArrSimpleNew *p)  {};
    virtual void visitEVarCast(EVarCast *p)  {};
    virtual void visitEVarSimpleCast(EVarSimpleCast *p)  {};
    virtual void visitEArrCast(EArrCast *p)  {};
    virtual void visitEArrSimpleCast(EArrSimpleCast *p)  {};
    virtual void visitEMul(EMul *p)  {};
    virtual void visitEAdd(EAdd *p)  {};
    virtual void visitERel(ERel *p)  {};
    virtual void visitEAnd(EAnd *p)  {};
    virtual void visitEOr(EOr *p)  {};
    virtual void visitPlus(Plus *p)  {};
    virtual void visitMinus(Minus *p)  {};
    virtual void visitTimes(Times *p)  {};
    virtual void visitDiv(Div *p)  {};
    virtual void visitMod(Mod *p)  {};
    virtual void visitLTH(LTH *p)  {};
    virtual void visitLE(LE *p)  {};
    virtual void visitGTH(GTH *p)  {};
    virtual void visitGE(GE *p)  {};
    virtual void visitEQU(EQU *p)  {};
    virtual void visitNE(NE *p)  {};
    virtual void visitListClsFld(ListClsFld *p)  {};
    virtual void visitListTopDef(ListTopDef *p)  {};
    virtual void visitListIdent(ListIdent *p) {};
    virtual void visitListArg(ListArg *p)  {};
    virtual void visitListStmt(ListStmt *p)  {};
    virtual void visitListItem(ListItem *p)  {};
    virtual void visitListType(ListType *p)  {};
    virtual void visitListExpr(ListExpr *p)  {};


    virtual void visitInteger(Integer x)  {};
    virtual void visitChar(Char x)  {};
    virtual void visitDouble(Double x)  {};
    virtual void visitString(String x)  {};
    virtual void visitIdent(Ident x) {};


};


class Visitable
{
 public:
  virtual ~Visitable() {}
  virtual void accept(Visitor *v) = 0;
  int line;
};



/********************   Abstract Syntax Classes    ********************/

class Program : public Visitable
{
public:
  virtual Program *clone() const = 0;

};


class TopDef : public Visitable
{
public:
  virtual TopDef *clone() const = 0;

};

class ClsFld : public Visitable
{
public:
  virtual ClsFld *clone() const = 0;

};

class Arg : public Visitable
{
public:
  virtual Arg *clone() const = 0;
  virtual std::string getType()  = 0;
  virtual std::string getIdent()  = 0;
};

class Block : public Visitable
{
public:
  virtual Block *clone() const = 0;

};

class Stmt : public Visitable
{
public:
  virtual Stmt *clone() const = 0;

};

class Item : public Visitable
{
public:
  virtual Item *clone() const = 0;
    std::string type_;
    int index_;
    std::string function_name_;

};

class SimpleType : public Visitable
{
public:
  virtual SimpleType *clone() const = 0;
  virtual std::string get() = 0;
};

class Type : public Visitable
{
public:
  virtual Type *clone() const = 0;
  virtual std::string get() = 0;
};

class Expr : public Visitable
{
public:
    Expr() : init_(false),ident_(""),is_lvalue_(false), is_always_false_(false), is_always_true_(false),
             has_value_(false), is_null_(false) {}
  virtual Expr *clone() const = 0;
    bool init_;
    Ident ident_;
    std::string type_;
    bool is_lvalue_;
    bool is_always_false_, is_always_true_;
    bool has_value_, is_null_;
    int value_;
};

class AddOp : public Visitable
{
public:
  virtual AddOp *clone() const = 0;

};

class MulOp : public Visitable
{
public:
  virtual MulOp *clone() const = 0;

};

class RelOp : public Visitable
{
public:
  virtual RelOp *clone() const = 0;

};



class Prog : public Program
{
public:
  ListTopDef *listtopdef_;

  Prog(const Prog &);
  Prog &operator=(const Prog &);
  Prog(ListTopDef *p1);
  ~Prog();
  virtual void accept(Visitor *v);
  virtual Prog *clone() const;
  void swap(Prog &);
};

class FnDef : public TopDef
{
public:
  Type *type_;
  Ident ident_;
  ListArg *listarg_;
  Block *block_;

  FnDef(const FnDef &);
  FnDef &operator=(const FnDef &);
  FnDef(Type *p1, Ident p2, ListArg *p3, Block *p4);
  ~FnDef();
  virtual void accept(Visitor *v);
  virtual FnDef *clone() const;
  void swap(FnDef &);
};

class ClsDef : public TopDef
{
public:
  Ident ident_;
  ListClsFld *listclsfld_;

  ClsDef(const ClsDef &);
  ClsDef &operator=(const ClsDef &);
  ClsDef(Ident p1, ListClsFld *p2);
  ~ClsDef();
  virtual void accept(Visitor *v);
  virtual ClsDef *clone() const;
  void swap(ClsDef &);
};

class InhClsDef : public TopDef
{
public:
  Ident ident_1;
  Ident ident_2;
  ListClsFld *listclsfld_;

  InhClsDef(const InhClsDef &);
  InhClsDef &operator=(const InhClsDef &);
  InhClsDef(Ident p1, Ident p2, ListClsFld *p3);
  ~InhClsDef();
  virtual void accept(Visitor *v);
  virtual InhClsDef *clone() const;
  void swap(InhClsDef &);
};

class VarDef : public ClsFld
{
public:
  Type *type_;
  ListIdent *listident_;

  VarDef(const VarDef &);
  VarDef &operator=(const VarDef &);
  VarDef(Type *p1, ListIdent *p2);
  ~VarDef();
  virtual void accept(Visitor *v);
  virtual VarDef *clone() const;
  void swap(VarDef &);
};

class MetDef : public ClsFld
{
public:
  Type *type_;
  Ident ident_;
  ListArg *listarg_;
  Block *block_;
  std::string owner_;
  MetDef(const MetDef &);
  MetDef &operator=(const MetDef &);
  MetDef(Type *p1, Ident p2, ListArg *p3, Block *p4);
  ~MetDef();
  virtual void accept(Visitor *v);
  virtual MetDef *clone() const;
  void swap(MetDef &);
};

class Ar : public Arg
{
public:
  Type *type_;
  Ident ident_;

  int index_;
  std::string function_name_;
  Ar(const Ar &);
  Ar &operator=(const Ar &);
  Ar(Type *p1, Ident p2);
  ~Ar();
  virtual void accept(Visitor *v);
  virtual Ar *clone() const;
  void swap(Ar &);
  virtual std::string getType();
  virtual std::string getIdent();
};

class Blk : public Block
{
public:
  ListStmt *liststmt_;

  Blk(const Blk &);
  Blk &operator=(const Blk &);
  Blk(ListStmt *p1);
  ~Blk();
  virtual void accept(Visitor *v);
  virtual Blk *clone() const;
  void swap(Blk &);
};
class SExpParen : public Stmt
{
public:
    Expr *expr_;

    SExpParen(const SExpParen &);
    SExpParen &operator=(const SExpParen &);
    SExpParen(Expr *p1);
    ~SExpParen();
    virtual void accept(Visitor *v);
    virtual SExpParen *clone() const;
    void swap(SExpParen &);
};
class Empty : public Stmt
{
public:

  Empty(const Empty &);
  Empty &operator=(const Empty &);
  Empty();
  ~Empty();
  virtual void accept(Visitor *v);
  virtual Empty *clone() const;
  void swap(Empty &);
};

class BStmt : public Stmt
{
public:
  Block *block_;

  BStmt(const BStmt &);
  BStmt &operator=(const BStmt &);
  BStmt(Block *p1);
  ~BStmt();
  virtual void accept(Visitor *v);
  virtual BStmt *clone() const;
  void swap(BStmt &);
};

class Decl : public Stmt
{
public:
  Type *type_;
  ListItem *listitem_;

  Decl(const Decl &);
  Decl &operator=(const Decl &);
  Decl(Type *p1, ListItem *p2);
  ~Decl();
  virtual void accept(Visitor *v);
  virtual Decl *clone() const;
  void swap(Decl &);
};

class Ass : public Stmt
{
public:
  Expr *expr_1;
  Expr *expr_2;

  Ass(const Ass &);
  Ass &operator=(const Ass &);
  Ass(Expr *p1, Expr *p2);
  ~Ass();
  virtual void accept(Visitor *v);
  virtual Ass *clone() const;
  void swap(Ass &);
};

class Incr : public Stmt
{
public:
  Expr *expr_;

  Incr(const Incr &);
  Incr &operator=(const Incr &);
  Incr(Expr *p1);
  ~Incr();
  virtual void accept(Visitor *v);
  virtual Incr *clone() const;
  void swap(Incr &);
};

class Decr : public Stmt
{
public:
  Expr *expr_;

  Decr(const Decr &);
  Decr &operator=(const Decr &);
  Decr(Expr *p1);
  ~Decr();
  virtual void accept(Visitor *v);
  virtual Decr *clone() const;
  void swap(Decr &);
};

class Ret : public Stmt
{
public:
  Expr *expr_;

  Ret(const Ret &);
  Ret &operator=(const Ret &);
  Ret(Expr *p1);
  ~Ret();
  virtual void accept(Visitor *v);
  virtual Ret *clone() const;
  void swap(Ret &);
};

class VRet : public Stmt
{
public:

  VRet(const VRet &);
  VRet &operator=(const VRet &);
  VRet();
  ~VRet();
  virtual void accept(Visitor *v);
  virtual VRet *clone() const;
  void swap(VRet &);
};

class Cond : public Stmt
{
public:
  Expr *expr_;
  Stmt *stmt_;

  Cond(const Cond &);
  Cond &operator=(const Cond &);
  Cond(Expr *p1, Stmt *p2);
  ~Cond();
  virtual void accept(Visitor *v);
  virtual Cond *clone() const;
  void swap(Cond &);
};

class CondElse : public Stmt
{
public:
  Expr *expr_;
  Stmt *stmt_1;
  Stmt *stmt_2;

  CondElse(const CondElse &);
  CondElse &operator=(const CondElse &);
  CondElse(Expr *p1, Stmt *p2, Stmt *p3);
  ~CondElse();
  virtual void accept(Visitor *v);
  virtual CondElse *clone() const;
  void swap(CondElse &);
};

class While : public Stmt
{
public:
  Expr *expr_;
  Stmt *stmt_;

  While(const While &);
  While &operator=(const While &);
  While(Expr *p1, Stmt *p2);
  ~While();
  virtual void accept(Visitor *v);
  virtual While *clone() const;
  void swap(While &);
};

class ForEach : public Stmt
{
public:
  Type *type_;
  Ident ident_;
  Expr *expr_;
  Stmt *stmt_;
  std::string function_name_;
  int index_;
  ForEach(const ForEach &);
  ForEach &operator=(const ForEach &);
  ForEach(Type *p1, Ident p2, Expr *p3, Stmt *p4);
  ~ForEach();
  virtual void accept(Visitor *v);
  virtual ForEach *clone() const;
  void swap(ForEach &);
};

class SExp : public Stmt
{
public:
  Expr *expr_;

  SExp(const SExp &);
  SExp &operator=(const SExp &);
  SExp(Expr *p1);
  ~SExp();
  virtual void accept(Visitor *v);
  virtual SExp *clone() const;
  void swap(SExp &);
};

class NoInit : public Item
{
public:
  Ident ident_;

  NoInit(const NoInit &);
  NoInit &operator=(const NoInit &);
  NoInit(Ident p1);
  ~NoInit();
  virtual void accept(Visitor *v);
  virtual NoInit *clone() const;
  void swap(NoInit &);
};

class Init : public Item
{
public:
  Ident ident_;
  Expr *expr_;

  Init(const Init &);
  Init &operator=(const Init &);
  Init(Ident p1, Expr *p2);
  ~Init();
  virtual void accept(Visitor *v);
  virtual Init *clone() const;
  void swap(Init &);
};

class Int : public SimpleType
{
public:

  Int(const Int &);
  Int &operator=(const Int &);
  Int();
  ~Int();
  virtual void accept(Visitor *v);
  virtual Int *clone() const;
  void swap(Int &);
  virtual std::string get();

};

class Str : public SimpleType
{
public:

  Str(const Str &);
  Str &operator=(const Str &);
  Str();
  ~Str();
  virtual void accept(Visitor *v);
  virtual Str *clone() const;
  void swap(Str &);
  virtual std::string get();
};

class Bool : public SimpleType
{
public:

  Bool(const Bool &);
  Bool &operator=(const Bool &);
  Bool();
  ~Bool();
  virtual void accept(Visitor *v);
  virtual Bool *clone() const;
  void swap(Bool &);
  virtual std::string get();
};

class Void : public SimpleType
{
public:

  Void(const Void &);
  Void &operator=(const Void &);
  Void();
  ~Void();
  virtual void accept(Visitor *v);
  virtual Void *clone() const;
  void swap(Void &);
  virtual std::string get();
};

class SimpleVarType : public Type
{
public:
  SimpleType *simpletype_;

  SimpleVarType(const SimpleVarType &);
  SimpleVarType &operator=(const SimpleVarType &);
  SimpleVarType(SimpleType *p1);
  ~SimpleVarType();
  virtual void accept(Visitor *v);
  virtual SimpleVarType *clone() const;
  void swap(SimpleVarType &);
  virtual std::string get();
};

class SimpleArrType : public Type
{
public:
  SimpleType *simpletype_;

  SimpleArrType(const SimpleArrType &);
  SimpleArrType &operator=(const SimpleArrType &);
  SimpleArrType(SimpleType *p1);
  ~SimpleArrType();
  virtual void accept(Visitor *v);
  virtual SimpleArrType *clone() const;
  void swap(SimpleArrType &);
  virtual std::string get();
};

class VarType : public Type
{
public:
  Ident ident_;

  VarType(const VarType &);
  VarType &operator=(const VarType &);
  VarType(Ident p1);
  ~VarType();
  virtual void accept(Visitor *v);
  virtual VarType *clone() const;
  void swap(VarType &);
  virtual std::string get();
};

class ArrType : public Type
{
public:
  Ident ident_;

  ArrType(const ArrType &);
  ArrType &operator=(const ArrType &);
  ArrType(Ident p1);
  ~ArrType();
  virtual void accept(Visitor *v);
  virtual ArrType *clone() const;
  void swap(ArrType &);
  virtual std::string get();
};

class Fun : public Type
{
public:
  Type *type_;
  ListType *listtype_;

  Fun(const Fun &);
  Fun &operator=(const Fun &);
  Fun(Type *p1, ListType *p2);
  ~Fun();
  virtual void accept(Visitor *v);
  virtual Fun *clone() const;
  void swap(Fun &);
  virtual std::string get();
};

class EVar : public Expr
{
public:
  int index_;
  std::string function_name_;
  bool is_reference_;

  EVar(const EVar &);
  EVar &operator=(const EVar &);
  EVar(Ident p1);
  ~EVar();
  virtual void accept(Visitor *v);
  virtual EVar *clone() const;
  void swap(EVar &);
};

class EClsVar : public Expr
{
public:
  Expr *expr_;

  EClsVar(const EClsVar &);
  EClsVar &operator=(const EClsVar &);
  EClsVar(Expr *p1, Ident p2);
  ~EClsVar();
  virtual void accept(Visitor *v);
  virtual EClsVar *clone() const;
  void swap(EClsVar &);
};

class EArrVar : public Expr
{
public:
  Expr *expr_1;
  Expr *expr_2;

  EArrVar(const EArrVar &);
  EArrVar &operator=(const EArrVar &);
  EArrVar(Expr *p1, Expr *p2);
  ~EArrVar();
  virtual void accept(Visitor *v);
  virtual EArrVar *clone() const;
  void swap(EArrVar &);
};

class ELitInt : public Expr
{
public:
  Integer integer_;

  ELitInt(const ELitInt &);
  ELitInt &operator=(const ELitInt &);
  ELitInt(Integer p1);
  ~ELitInt();
  virtual void accept(Visitor *v);
  virtual ELitInt *clone() const;
  void swap(ELitInt &);
};

class EString : public Expr
{
public:
  String string_;

  EString(const EString &);
  EString &operator=(const EString &);
  EString(String p1);
  ~EString();
  virtual void accept(Visitor *v);
  virtual EString *clone() const;
  void swap(EString &);
};

class ELitTrue : public Expr
{
public:

  ELitTrue(const ELitTrue &);
  ELitTrue &operator=(const ELitTrue &);
  ELitTrue();
  ~ELitTrue();
  virtual void accept(Visitor *v);
  virtual ELitTrue *clone() const;
  void swap(ELitTrue &);
};

class ELitFalse : public Expr
{
public:

  ELitFalse(const ELitFalse &);
  ELitFalse &operator=(const ELitFalse &);
  ELitFalse();
  ~ELitFalse();
  virtual void accept(Visitor *v);
  virtual ELitFalse *clone() const;
  void swap(ELitFalse &);
};

class ELitNull : public Expr
{
public:

  ELitNull(const ELitNull &);
  ELitNull &operator=(const ELitNull &);
  ELitNull();
  ~ELitNull();
  virtual void accept(Visitor *v);
  virtual ELitNull *clone() const;
  void swap(ELitNull &);
};

class EApp : public Expr
{
public:
  ListExpr *listexpr_;

  EApp(const EApp &);
  EApp &operator=(const EApp &);
  EApp(Ident p1, ListExpr *p2);
  ~EApp();
  virtual void accept(Visitor *v);
  virtual EApp *clone() const;
  void swap(EApp &);
};

class EClsApp : public Expr
{
public:
  Expr *expr_;

  ListExpr *listexpr_;
  std::string owner_;
  EClsApp(const EClsApp &);
  EClsApp &operator=(const EClsApp &);
  EClsApp(Expr *p1, Ident p2, ListExpr *p3);
  ~EClsApp();
  virtual void accept(Visitor *v);
  virtual EClsApp *clone() const;
  void swap(EClsApp &);
};

class ENeg : public Expr
{
public:
  Expr *expr_;

  ENeg(const ENeg &);
  ENeg &operator=(const ENeg &);
  ENeg(Expr *p1);
  ~ENeg();
  virtual void accept(Visitor *v);
  virtual ENeg *clone() const;
  void swap(ENeg &);
};

class ENot : public Expr
{
public:
  Expr *expr_;

  ENot(const ENot &);
  ENot &operator=(const ENot &);
  ENot(Expr *p1);
  ~ENot();
  virtual void accept(Visitor *v);
  virtual ENot *clone() const;
  void swap(ENot &);
};

class EVarNew : public Expr
{
public:

  EVarNew(const EVarNew &);
  EVarNew &operator=(const EVarNew &);
  EVarNew(Ident p1);
  ~EVarNew();
  virtual void accept(Visitor *v);
  virtual EVarNew *clone() const;
  void swap(EVarNew &);
};

class EVarSimpleNew : public Expr
{
public:
  SimpleType *simpletype_;

  EVarSimpleNew(const EVarSimpleNew &);
  EVarSimpleNew &operator=(const EVarSimpleNew &);
  EVarSimpleNew(SimpleType *p1);
  ~EVarSimpleNew();
  virtual void accept(Visitor *v);
  virtual EVarSimpleNew *clone() const;
  void swap(EVarSimpleNew &);
};

class EArrNew : public Expr
{
public:
  Expr *expr_;

  EArrNew(const EArrNew &);
  EArrNew &operator=(const EArrNew &);
  EArrNew(Ident p1, Expr *p2);
  ~EArrNew();
  virtual void accept(Visitor *v);
  virtual EArrNew *clone() const;
  void swap(EArrNew &);
};

class EArrSimpleNew : public Expr
{
public:
  SimpleType *simpletype_;
  Expr *expr_;

  EArrSimpleNew(const EArrSimpleNew &);
  EArrSimpleNew &operator=(const EArrSimpleNew &);
  EArrSimpleNew(SimpleType *p1, Expr *p2);
  ~EArrSimpleNew();
  virtual void accept(Visitor *v);
  virtual EArrSimpleNew *clone() const;
  void swap(EArrSimpleNew &);
};

class EVarCast : public Expr
{
public:
  Expr *expr_;

  EVarCast(const EVarCast &);
  EVarCast &operator=(const EVarCast &);
  EVarCast(Ident p1, Expr *p2);
  ~EVarCast();
  virtual void accept(Visitor *v);
  virtual EVarCast *clone() const;
  void swap(EVarCast &);
};

class EVarSimpleCast : public Expr
{
public:
  SimpleType *simpletype_;
  Expr *expr_;

  EVarSimpleCast(const EVarSimpleCast &);
  EVarSimpleCast &operator=(const EVarSimpleCast &);
  EVarSimpleCast(SimpleType *p1, Expr *p2);
  ~EVarSimpleCast();
  virtual void accept(Visitor *v);
  virtual EVarSimpleCast *clone() const;
  void swap(EVarSimpleCast &);
};

class EArrCast : public Expr
{
public:
  Expr *expr_;

  EArrCast(const EArrCast &);
  EArrCast &operator=(const EArrCast &);
  EArrCast(Ident p1, Expr *p2);
  ~EArrCast();
  virtual void accept(Visitor *v);
  virtual EArrCast *clone() const;
  void swap(EArrCast &);
};

class EArrSimpleCast : public Expr
{
public:
  SimpleType *simpletype_;
  Expr *expr_;

  EArrSimpleCast(const EArrSimpleCast &);
  EArrSimpleCast &operator=(const EArrSimpleCast &);
  EArrSimpleCast(SimpleType *p1, Expr *p2);
  ~EArrSimpleCast();
  virtual void accept(Visitor *v);
  virtual EArrSimpleCast *clone() const;
  void swap(EArrSimpleCast &);
};

class EMul : public Expr
{
public:
  Expr *expr_1;
  MulOp *mulop_;
  Expr *expr_2;

  EMul(const EMul &);
  EMul &operator=(const EMul &);
  EMul(Expr *p1, MulOp *p2, Expr *p3);
  ~EMul();
  virtual void accept(Visitor *v);
  virtual EMul *clone() const;
  void swap(EMul &);
};

class EAdd : public Expr
{
public:
  Expr *expr_1;
  AddOp *addop_;
  Expr *expr_2;

  EAdd(const EAdd &);
  EAdd &operator=(const EAdd &);
  EAdd(Expr *p1, AddOp *p2, Expr *p3);
  ~EAdd();
  virtual void accept(Visitor *v);
  virtual EAdd *clone() const;
  void swap(EAdd &);
};

class ERel : public Expr
{
public:
  Expr *expr_1;
  RelOp *relop_;
  Expr *expr_2;

  ERel(const ERel &);
  ERel &operator=(const ERel &);
  ERel(Expr *p1, RelOp *p2, Expr *p3);
  ~ERel();
  virtual void accept(Visitor *v);
  virtual ERel *clone() const;
  void swap(ERel &);
};

class EAnd : public Expr
{
public:
  Expr *expr_1;
  Expr *expr_2;

  EAnd(const EAnd &);
  EAnd &operator=(const EAnd &);
  EAnd(Expr *p1, Expr *p2);
  ~EAnd();
  virtual void accept(Visitor *v);
  virtual EAnd *clone() const;
  void swap(EAnd &);
};

class EOr : public Expr
{
public:
  Expr *expr_1;
  Expr *expr_2;

  EOr(const EOr &);
  EOr &operator=(const EOr &);
  EOr(Expr *p1, Expr *p2);
  ~EOr();
  virtual void accept(Visitor *v);
  virtual EOr *clone() const;
  void swap(EOr &);
};

class Plus : public AddOp
{
public:

  Plus(const Plus &);
  Plus &operator=(const Plus &);
  Plus();
  ~Plus();
  virtual void accept(Visitor *v);
  virtual Plus *clone() const;
  void swap(Plus &);
};

class Minus : public AddOp
{
public:

  Minus(const Minus &);
  Minus &operator=(const Minus &);
  Minus();
  ~Minus();
  virtual void accept(Visitor *v);
  virtual Minus *clone() const;
  void swap(Minus &);
};

class Times : public MulOp
{
public:

  Times(const Times &);
  Times &operator=(const Times &);
  Times();
  ~Times();
  virtual void accept(Visitor *v);
  virtual Times *clone() const;
  void swap(Times &);
};

class Div : public MulOp
{
public:

  Div(const Div &);
  Div &operator=(const Div &);
  Div();
  ~Div();
  virtual void accept(Visitor *v);
  virtual Div *clone() const;
  void swap(Div &);
};

class Mod : public MulOp
{
public:

  Mod(const Mod &);
  Mod &operator=(const Mod &);
  Mod();
  ~Mod();
  virtual void accept(Visitor *v);
  virtual Mod *clone() const;
  void swap(Mod &);
};

class LTH : public RelOp
{
public:

  LTH(const LTH &);
  LTH &operator=(const LTH &);
  LTH();
  ~LTH();
  virtual void accept(Visitor *v);
  virtual LTH *clone() const;
  void swap(LTH &);
};

class LE : public RelOp
{
public:

  LE(const LE &);
  LE &operator=(const LE &);
  LE();
  ~LE();
  virtual void accept(Visitor *v);
  virtual LE *clone() const;
  void swap(LE &);
};

class GTH : public RelOp
{
public:

  GTH(const GTH &);
  GTH &operator=(const GTH &);
  GTH();
  ~GTH();
  virtual void accept(Visitor *v);
  virtual GTH *clone() const;
  void swap(GTH &);
};

class GE : public RelOp
{
public:

  GE(const GE &);
  GE &operator=(const GE &);
  GE();
  ~GE();
  virtual void accept(Visitor *v);
  virtual GE *clone() const;
  void swap(GE &);
};

class EQU : public RelOp
{
public:

  EQU(const EQU &);
  EQU &operator=(const EQU &);
  EQU();
  ~EQU();
  virtual void accept(Visitor *v);
  virtual EQU *clone() const;
  void swap(EQU &);
};

class NE : public RelOp
{
public:

  NE(const NE &);
  NE &operator=(const NE &);
  NE();
  ~NE();
  virtual void accept(Visitor *v);
  virtual NE *clone() const;
  void swap(NE &);
};



class ListClsFld : public Visitable, public std::vector<ClsFld*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListClsFld *clone() const;
};

class ListTopDef : public Visitable, public std::vector<TopDef*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListTopDef *clone() const;
};

class ListIdent : public Visitable, public std::vector<Ident>
{
public:
  virtual void accept(Visitor *v);
  virtual ListIdent *clone() const;
};

class ListArg : public Visitable, public std::vector<Arg*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListArg *clone() const;
  virtual std::vector<std::string> getTypes();
  virtual std::vector<std::string> getIdents();
};

class ListStmt : public Visitable, public std::vector<Stmt*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListStmt *clone() const;
};

class ListItem : public Visitable, public std::vector<Item*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListItem *clone() const;
  std::string type_;
};

class ListType : public Visitable, public std::vector<Type*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListType *clone() const;
  virtual std::string get();
};

class ListExpr : public Visitable, public std::vector<Expr*>
{
public:
  virtual void accept(Visitor *v);
  virtual ListExpr *clone() const;
};



#endif
