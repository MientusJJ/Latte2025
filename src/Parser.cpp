/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "Latte.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
    return 1;
}
void yyerror(const char *str)
{
    extern char *yytext;
    fprintf(stderr,"ERROR\nLine %d: %s at %s\n",
            yy_mylinenumber, str, yytext);
}



static Program* YY_RESULT_Program_ = 0;

Program* pProgram(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Program_;
    }
}
Program* pProgram(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Program_;
    }
}
static TopDef *YY_RESULT_TopDef_ = 0;
TopDef *pTopDef(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_TopDef_;
    }
}
TopDef *pTopDef(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_TopDef_;
    }
}

static ListClsFld *YY_RESULT_ListClsFld_ = 0;
ListClsFld *pListClsFld(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListClsFld_;
    }
}
ListClsFld *pListClsFld(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListClsFld_;
    }
}

static ListTopDef *YY_RESULT_ListTopDef_ = 0;
ListTopDef *pListTopDef(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListTopDef_;
    }
}
ListTopDef *pListTopDef(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListTopDef_;
    }
}

static ClsFld *YY_RESULT_ClsFld_ = 0;
ClsFld *pClsFld(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ClsFld_;
    }
}
ClsFld *pClsFld(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ClsFld_;
    }
}

static ListIdent *YY_RESULT_ListIdent_ = 0;
ListIdent *pListIdent(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListIdent_;
    }
}
ListIdent *pListIdent(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListIdent_;
    }
}

static Arg *YY_RESULT_Arg_ = 0;
Arg *pArg(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Arg_;
    }
}
Arg *pArg(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Arg_;
    }
}

static ListArg *YY_RESULT_ListArg_ = 0;
ListArg *pListArg(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListArg_;
    }
}
ListArg *pListArg(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListArg_;
    }
}

static Block *YY_RESULT_Block_ = 0;
Block *pBlock(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Block_;
    }
}
Block *pBlock(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Block_;
    }
}

static ListStmt *YY_RESULT_ListStmt_ = 0;
ListStmt *pListStmt(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListStmt_;
    }
}
ListStmt *pListStmt(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListStmt_;
    }
}

static Stmt *YY_RESULT_Stmt_ = 0;
Stmt *pStmt(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Stmt_;
    }
}
Stmt *pStmt(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Stmt_;
    }
}

static Item *YY_RESULT_Item_ = 0;
Item *pItem(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Item_;
    }
}
Item *pItem(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Item_;
    }
}

static ListItem *YY_RESULT_ListItem_ = 0;
ListItem *pListItem(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListItem_;
    }
}
ListItem *pListItem(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListItem_;
    }
}

static SimpleType *YY_RESULT_SimpleType_ = 0;
SimpleType *pStdType(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_SimpleType_;
    }
}
SimpleType *pStdType(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_SimpleType_;
    }
}

static Type *YY_RESULT_Type_ = 0;
Type *pType(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Type_;
    }
}
Type *pType(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Type_;
    }
}

static ListType *YY_RESULT_ListType_ = 0;
ListType *pListType(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListType_;
    }
}
ListType *pListType(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListType_;
    }
}

static Expr *YY_RESULT_Expr_ = 0;
Expr *pExpr(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Expr_;
    }
}
Expr *pExpr(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_Expr_;
    }
}

static ListExpr *YY_RESULT_ListExpr_ = 0;
ListExpr *pListExpr(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListExpr_;
    }
}
ListExpr *pListExpr(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_ListExpr_;
    }
}

static AddOp *YY_RESULT_AddOp_ = 0;
AddOp *pAddOp(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_AddOp_;
    }
}
AddOp *pAddOp(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_AddOp_;
    }
}

static MulOp *YY_RESULT_MulOp_ = 0;
MulOp *pMulOp(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_MulOp_;
    }
}
MulOp *pMulOp(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_MulOp_;
    }
}

static RelOp *YY_RESULT_RelOp_ = 0;
RelOp *pRelOp(FILE *inp)
{
    yy_mylinenumber = 1;
    initialize_lexer(inp);
    if (yyparse())
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_RelOp_;
    }
}
RelOp *pRelOp(const char *str)
{
    YY_BUFFER_STATE buf;
    int result;
    yy_mylinenumber = 1;
    initialize_lexer(0);
    buf = yy_scan_string(str);
    result = yyparse();
    yy_delete_buffer(buf);
    if (result)
    { /* Failure */
        return 0;
    }
    else
    { /* Success */
        return YY_RESULT_RelOp_;
    }
}



#line 135 "Parser.C"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype
{
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _ERROR_ = 258,                 /* _ERROR_  */
    _SYMB_0 = 259,                 /* _SYMB_0  */
    _SYMB_1 = 260,                 /* _SYMB_1  */
    _SYMB_2 = 261,                 /* _SYMB_2  */
    _SYMB_3 = 262,                 /* _SYMB_3  */
    _SYMB_4 = 263,                 /* _SYMB_4  */
    _SYMB_5 = 264,                 /* _SYMB_5  */
    _SYMB_6 = 265,                 /* _SYMB_6  */
    _SYMB_7 = 266,                 /* _SYMB_7  */
    _SYMB_8 = 267,                 /* _SYMB_8  */
    _SYMB_9 = 268,                 /* _SYMB_9  */
    _SYMB_10 = 269,                /* _SYMB_10  */
    _SYMB_11 = 270,                /* _SYMB_11  */
    _SYMB_12 = 271,                /* _SYMB_12  */
    _SYMB_13 = 272,                /* _SYMB_13  */
    _SYMB_14 = 273,                /* _SYMB_14  */
    _SYMB_15 = 274,                /* _SYMB_15  */
    _SYMB_16 = 275,                /* _SYMB_16  */
    _SYMB_17 = 276,                /* _SYMB_17  */
    _SYMB_18 = 277,                /* _SYMB_18  */
    _SYMB_19 = 278,                /* _SYMB_19  */
    _SYMB_20 = 279,                /* _SYMB_20  */
    _SYMB_21 = 280,                /* _SYMB_21  */
    _SYMB_22 = 281,                /* _SYMB_22  */
    _SYMB_23 = 282,                /* _SYMB_23  */
    _SYMB_24 = 283,                /* _SYMB_24  */
    _SYMB_25 = 284,                /* _SYMB_25  */
    _SYMB_26 = 285,                /* _SYMB_26  */
    _SYMB_27 = 286,                /* _SYMB_27  */
    _SYMB_28 = 287,                /* _SYMB_28  */
    _SYMB_29 = 288,                /* _SYMB_29  */
    _SYMB_30 = 289,                /* _SYMB_30  */
    _SYMB_31 = 290,                /* _SYMB_31  */
    _SYMB_32 = 291,                /* _SYMB_32  */
    _SYMB_33 = 292,                /* _SYMB_33  */
    _SYMB_34 = 293,                /* _SYMB_34  */
    _SYMB_35 = 294,                /* _SYMB_35  */
    _SYMB_36 = 295,                /* _SYMB_36  */
    _SYMB_37 = 296,                /* _SYMB_37  */
    _SYMB_38 = 297,                /* _SYMB_38  */
    _SYMB_39 = 298,                /* _SYMB_39  */
    _SYMB_40 = 299,                /* _SYMB_40  */
    _SYMB_41 = 300,                /* _SYMB_41  */
    _SYMB_42 = 301,                /* _SYMB_42  */
    _STRING_ = 302,                /* _STRING_  */
    _INTEGER_ = 303,               /* _INTEGER_  */
    _IDENT_ = 304                  /* _IDENT_  */
};
typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "Latte.y"

    int int_;
    char char_;
    double double_;
    char* string_;
    Program* program_;
    TopDef* topdef_;
    ListClsFld* listclsfld_;
    ListTopDef* listtopdef_;
    ClsFld* clsfld_;
    ListIdent* listident_;
    Arg* arg_;
    ListArg* listarg_;
    Block* block_;
    ListStmt* liststmt_;
    Stmt* stmt_;
    Item* item_;
    ListItem* listitem_;
    SimpleType* simpletype_;
    Type* type_;
    ListType* listtype_;
    Expr* expr_;
    ListExpr* listexpr_;
    AddOp* addop_;
    MulOp* mulop_;
    RelOp* relop_;

#line 259 "Parser.C"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
    YYSYMBOL_YYEMPTY = -2,
    YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
    YYSYMBOL_YYerror = 1,                    /* error  */
    YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
    YYSYMBOL__ERROR_ = 3,                    /* _ERROR_  */
    YYSYMBOL__SYMB_0 = 4,                    /* _SYMB_0  */
    YYSYMBOL__SYMB_1 = 5,                    /* _SYMB_1  */
    YYSYMBOL__SYMB_2 = 6,                    /* _SYMB_2  */
    YYSYMBOL__SYMB_3 = 7,                    /* _SYMB_3  */
    YYSYMBOL__SYMB_4 = 8,                    /* _SYMB_4  */
    YYSYMBOL__SYMB_5 = 9,                    /* _SYMB_5  */
    YYSYMBOL__SYMB_6 = 10,                   /* _SYMB_6  */
    YYSYMBOL__SYMB_7 = 11,                   /* _SYMB_7  */
    YYSYMBOL__SYMB_8 = 12,                   /* _SYMB_8  */
    YYSYMBOL__SYMB_9 = 13,                   /* _SYMB_9  */
    YYSYMBOL__SYMB_10 = 14,                  /* _SYMB_10  */
    YYSYMBOL__SYMB_11 = 15,                  /* _SYMB_11  */
    YYSYMBOL__SYMB_12 = 16,                  /* _SYMB_12  */
    YYSYMBOL__SYMB_13 = 17,                  /* _SYMB_13  */
    YYSYMBOL__SYMB_14 = 18,                  /* _SYMB_14  */
    YYSYMBOL__SYMB_15 = 19,                  /* _SYMB_15  */
    YYSYMBOL__SYMB_16 = 20,                  /* _SYMB_16  */
    YYSYMBOL__SYMB_17 = 21,                  /* _SYMB_17  */
    YYSYMBOL__SYMB_18 = 22,                  /* _SYMB_18  */
    YYSYMBOL__SYMB_19 = 23,                  /* _SYMB_19  */
    YYSYMBOL__SYMB_20 = 24,                  /* _SYMB_20  */
    YYSYMBOL__SYMB_21 = 25,                  /* _SYMB_21  */
    YYSYMBOL__SYMB_22 = 26,                  /* _SYMB_22  */
    YYSYMBOL__SYMB_23 = 27,                  /* _SYMB_23  */
    YYSYMBOL__SYMB_24 = 28,                  /* _SYMB_24  */
    YYSYMBOL__SYMB_25 = 29,                  /* _SYMB_25  */
    YYSYMBOL__SYMB_26 = 30,                  /* _SYMB_26  */
    YYSYMBOL__SYMB_27 = 31,                  /* _SYMB_27  */
    YYSYMBOL__SYMB_28 = 32,                  /* _SYMB_28  */
    YYSYMBOL__SYMB_29 = 33,                  /* _SYMB_29  */
    YYSYMBOL__SYMB_30 = 34,                  /* _SYMB_30  */
    YYSYMBOL__SYMB_31 = 35,                  /* _SYMB_31  */
    YYSYMBOL__SYMB_32 = 36,                  /* _SYMB_32  */
    YYSYMBOL__SYMB_33 = 37,                  /* _SYMB_33  */
    YYSYMBOL__SYMB_34 = 38,                  /* _SYMB_34  */
    YYSYMBOL__SYMB_35 = 39,                  /* _SYMB_35  */
    YYSYMBOL__SYMB_36 = 40,                  /* _SYMB_36  */
    YYSYMBOL__SYMB_37 = 41,                  /* _SYMB_37  */
    YYSYMBOL__SYMB_38 = 42,                  /* _SYMB_38  */
    YYSYMBOL__SYMB_39 = 43,                  /* _SYMB_39  */
    YYSYMBOL__SYMB_40 = 44,                  /* _SYMB_40  */
    YYSYMBOL__SYMB_41 = 45,                  /* _SYMB_41  */
    YYSYMBOL__SYMB_42 = 46,                  /* _SYMB_42  */
    YYSYMBOL__STRING_ = 47,                  /* _STRING_  */
    YYSYMBOL__INTEGER_ = 48,                 /* _INTEGER_  */
    YYSYMBOL__IDENT_ = 49,                   /* _IDENT_  */
    YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
    YYSYMBOL_Program = 51,                   /* Program  */
    YYSYMBOL_TopDef = 52,                    /* TopDef  */
    YYSYMBOL_ListClsFld = 53,                /* ListClsFld  */
    YYSYMBOL_ListTopDef = 54,                /* ListTopDef  */
    YYSYMBOL_ClsFld = 55,                    /* ClsFld  */
    YYSYMBOL_ListIdent = 56,                 /* ListIdent  */
    YYSYMBOL_Arg = 57,                       /* Arg  */
    YYSYMBOL_ListArg = 58,                   /* ListArg  */
    YYSYMBOL_Block = 59,                     /* Block  */
    YYSYMBOL_ListStmt = 60,                  /* ListStmt  */
    YYSYMBOL_Stmt = 61,                      /* Stmt  */
    YYSYMBOL_Item = 62,                      /* Item  */
    YYSYMBOL_ListItem = 63,                  /* ListItem  */
    YYSYMBOL_SimpleType = 64,                /* SimpleType  */
    YYSYMBOL_Type = 65,                      /* Type  */
    YYSYMBOL_Expr8 = 66,                     /* Expr8  */
    YYSYMBOL_Expr7 = 67,                     /* Expr7  */
    YYSYMBOL_Expr6 = 68,                     /* Expr6  */
    YYSYMBOL_Expr5 = 69,                     /* Expr5  */
    YYSYMBOL_Expr4 = 70,                     /* Expr4  */
    YYSYMBOL_Expr3 = 71,                     /* Expr3  */
    YYSYMBOL_Expr2 = 72,                     /* Expr2  */
    YYSYMBOL_Expr1 = 73,                     /* Expr1  */
    YYSYMBOL_Expr = 74,                      /* Expr  */
    YYSYMBOL_ListExpr = 75,                  /* ListExpr  */
    YYSYMBOL_AddOp = 76,                     /* AddOp  */
    YYSYMBOL_MulOp = 77,                     /* MulOp  */
    YYSYMBOL_RelOp = 78                      /* RelOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
/* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
    yy_state_t yyss_alloc;
    YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
        {
                0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
                2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
                5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
                15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
                25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
                35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
                45,    46,    47,    48,    49
        };

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   176,   176,   178,   179,   180,   182,   183,   185,   186,
     188,   189,   191,   192,   194,   196,   197,   198,   200,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   220,   221,   223,   224,   226,
     227,   228,   229,   231,   232,   233,   234,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   252,   253,
     254,   256,   257,   258,   259,   260,   262,   263,   264,   265,
     266,   268,   269,   271,   272,   274,   275,   277,   278,   280,
     281,   283,   284,   285,   287,   288,   290,   291,   292,   294,
     295,   296,   297,   298,   299
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_ERROR_", "_SYMB_0",
  "_SYMB_1", "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6",
  "_SYMB_7", "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12",
  "_SYMB_13", "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18",
  "_SYMB_19", "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24",
  "_SYMB_25", "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30",
  "_SYMB_31", "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36",
  "_SYMB_37", "_SYMB_38", "_SYMB_39", "_SYMB_40", "_SYMB_41", "_SYMB_42",
  "_STRING_", "_INTEGER_", "_IDENT_", "$accept", "Program", "TopDef",
  "ListClsFld", "ListTopDef", "ClsFld", "ListIdent", "Arg", "ListArg",
  "Block", "ListStmt", "Stmt", "Item", "ListItem", "SimpleType", "Type",
  "Expr8", "Expr7", "Expr6", "Expr5", "Expr4", "Expr3", "Expr2", "Expr1",
  "Expr", "ListExpr", "AddOp", "MulOp", "RelOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
        {
                82,  -130,   -35,  -130,  -130,  -130,    12,    32,    82,  -130,
                28,    -9,    -1,  -130,  -130,  -130,  -130,    55,    38,    15,
                38,    59,    38,    20,    74,    73,    80,    39,  -130,  -130,
                4,    96,    38,    38,   107,  -130,    38,    67,  -130,   116,
                -130,  -130,  -130,   121,   150,  -130,  -130,    54,   107,   147,
                -130,  -130,    27,    27,  -130,   156,   157,    79,  -130,   163,
                -130,   159,  -130,  -130,     2,  -130,  -130,   115,   114,  -130,
                -130,  -130,   131,    19,    26,   149,   124,  -130,   147,   148,
                14,   164,   196,   168,   114,   114,    38,   196,   152,   158,
                -130,   165,   196,   196,   166,   169,   167,   128,   196,  -130,
                -130,  -130,   196,  -130,  -130,   196,   196,  -130,  -130,  -130,
                -130,  -130,  -130,   196,   196,  -130,   196,   172,   176,   180,
                196,   184,   196,   188,   189,   153,   193,   196,   196,  -130,
                200,   192,   201,   196,   115,  -130,   204,   199,  -130,   131,
                -130,    19,  -130,   205,  -130,  -130,  -130,  -130,   196,  -130,
                196,  -130,   206,   101,   203,   207,   101,   196,  -130,  -130,
                -130,   196,  -130,  -130,  -130,  -130,   196,   175,  -130,  -130,
                -130,  -130,   212,   213,   101,  -130,   101,  -130,  -130
        };

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
        {
                0,    41,     0,    39,    40,    42,    45,     0,     8,     2,
                43,     0,     0,    46,     1,     9,    44,     0,     0,     0,
                15,     0,     6,     0,     0,    16,     0,     0,     4,     7,
                12,     0,     0,    15,     0,    14,    15,     0,    10,     0,
                17,    19,     3,     0,    12,    13,     5,     0,     0,     0,
                18,    21,     0,     0,    53,     0,     0,     0,    54,     0,
                52,     0,    51,    50,    47,    22,    20,     0,    60,    65,
                70,    72,    74,    76,    78,    80,     0,    11,     0,    47,
                0,     0,     0,    47,    58,    59,     0,     0,    61,    62,
                28,     0,     0,    81,    35,    37,     0,     0,     0,    86,
                87,    88,     0,    85,    84,     0,     0,    89,    90,    91,
                92,    93,    94,     0,     0,    33,     0,     0,     0,     0,
                0,     0,     0,     0,    57,     0,     0,     0,     0,    27,
                0,    82,     0,     0,     0,    23,    48,     0,    71,    73,
                77,    75,    79,     0,    25,    26,    57,    66,     0,    67,
                0,    34,     0,     0,     0,     0,     0,    81,    55,    36,
                38,    81,    49,    24,    68,    69,     0,    29,    63,    64,
                31,    83,     0,     0,     0,    56,     0,    30,    32
        };

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
        {
                -130,  -130,  -130,   -15,   214,  -130,   186,  -130,   -21,   -30,
                -130,  -129,  -130,    87,   -48,     3,   105,  -130,  -130,  -100,
                120,   113,  -130,   122,   -49,   -51,  -130,  -130,  -130
        };

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
        {
                0,     7,     8,    21,     9,    22,    31,    25,    26,    65,
                47,    66,    95,    96,    10,    67,    68,    69,    70,    71,
                72,    73,    74,    75,    76,   132,   105,   102,   113
        };

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
        {
                81,    80,   138,    11,    42,    18,    93,    29,    36,    89,
                91,    11,    40,    37,    12,    43,    13,    39,    77,   122,
                147,    23,   149,    27,   167,    23,    13,   170,   123,   119,
                80,    82,    14,   119,    19,    23,    27,   103,   126,    27,
                17,   104,    16,   130,   131,   177,   106,   178,   164,   137,
                165,   -45,   107,   108,   109,   110,   111,   112,    49,    20,
                41,    50,    51,    54,    24,   142,    28,   143,    58,    30,
                1,    60,    52,    53,    62,    63,    83,     3,   154,   155,
                32,     4,    33,     5,   159,    34,     1,     6,    35,   125,
                54,    55,    56,     3,    57,    58,    59,     4,    60,     5,
                61,    62,    63,    64,    38,    49,   171,    41,   131,    51,
                172,     1,   131,    41,     1,     2,    44,   173,     3,    52,
                53,     3,     4,    46,     5,     4,    48,     5,    88,    97,
                98,     6,   115,     1,   116,   117,   118,    54,    55,    56,
                3,    57,    58,    59,     4,    60,     5,    61,    62,    63,
                64,    78,    93,   120,    99,   100,   101,    84,    85,    37,
                86,    87,   121,    92,    94,    52,    53,    78,   127,   124,
                114,    90,    93,   129,   128,   135,   133,   136,   134,     1,
                144,    52,    53,    54,   145,   146,     3,    57,    58,   148,
                4,    60,     5,   150,    62,    63,    79,   151,   153,    54,
                78,   157,   152,    57,    58,   156,   158,    60,   161,   174,
                62,    63,    83,   163,    52,    53,   162,   175,   176,   166,
                168,   160,    15,    45,   169,   139,   141,     0,   140,     0,
                0,     0,    54,     0,     0,     0,    57,    58,     0,     0,
                60,     0,     0,    62,    63,    83
        };

static const yytype_int16 yycheck[] =
        {
                49,    49,   102,     0,    34,     6,     4,    22,     4,    57,
                59,     8,    33,     9,    49,    36,    14,    32,    48,     5,
                120,    18,   122,    20,   153,    22,    14,   156,    14,    78,
                78,     4,     0,    82,    35,    32,    33,    18,    87,    36,
                49,    22,    14,    92,    93,   174,    20,   176,   148,    98,
                150,    49,    26,    27,    28,    29,    30,    31,     4,     4,
                6,     7,     8,    36,    49,   114,     7,   116,    41,    49,
                32,    44,    18,    19,    47,    48,    49,    39,   127,   128,
                6,    43,     9,    45,   133,     5,    32,    49,    49,    86,
                36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
                46,    47,    48,    49,     8,     4,   157,     6,   157,     8,
                161,    32,   161,     6,    32,    33,    49,   166,    39,    18,
                19,    39,    43,     7,    45,    43,     5,    45,    49,    15,
                16,    49,     8,    32,    10,    11,    12,    36,    37,    38,
                39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
                49,     4,     4,     5,    23,    24,    25,    52,    53,     9,
                4,     4,    14,     4,    49,    18,    19,     4,    16,     5,
                21,     8,     4,     8,    16,     8,    10,    49,     9,    32,
                8,    18,    19,    36,     8,     5,    39,    40,    41,     5,
                43,    44,    45,     5,    47,    48,    49,     8,     5,    36,
                4,     9,    49,    40,    41,     5,     5,    44,     4,    34,
                47,    48,    49,     8,    18,    19,    17,     5,     5,    13,
                17,   134,     8,    37,    17,   105,   113,    -1,   106,    -1,
                -1,    -1,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
                44,    -1,    -1,    47,    48,    49
        };

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
        {
                0,    32,    33,    39,    43,    45,    49,    51,    52,    54,
                64,    65,    49,    14,     0,    54,    14,    49,     6,    35,
                4,    53,    55,    65,    49,    57,    58,    65,     7,    53,
                49,    56,     6,     9,     5,    49,     4,     9,     8,    53,
                58,     6,    59,    58,    49,    56,     7,    60,     5,     4,
                7,     8,    18,    19,    36,    37,    38,    40,    41,    42,
                44,    46,    47,    48,    49,    59,    61,    65,    66,    67,
                68,    69,    70,    71,    72,    73,    74,    59,     4,    49,
                64,    74,     4,    49,    66,    66,     4,     4,    49,    64,
                8,    74,     4,     4,    49,    62,    63,    15,    16,    23,
                24,    25,    77,    18,    22,    76,    20,    26,    27,    28,
                29,    30,    31,    78,    21,     8,    10,    11,    12,    74,
                5,    14,     5,    14,     5,    65,    74,    16,    16,     8,
                74,    74,    75,    10,     9,     8,    49,    74,    69,    70,
                73,    71,    74,    74,     8,     8,     5,    69,     5,    69,
                5,     8,    49,     5,    74,    74,     5,     9,     5,    74,
                63,     4,    17,     8,    69,    69,    13,    61,    17,    17,
                61,    75,    75,    74,    34,     5,     5,    61,    61
        };

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
        {
                0,    50,    51,    52,    52,    52,    53,    53,    54,    54,
                55,    55,    56,    56,    57,    58,    58,    58,    59,    60,
                60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
                61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
                64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
                66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
                67,    68,    68,    68,    68,    68,    69,    69,    69,    69,
                69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
                74,    75,    75,    75,    76,    76,    77,    77,    77,    78,
                78,    78,    78,    78,    78
        };

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
        {
                0,     2,     1,     6,     5,     7,     1,     2,     1,     2,
                3,     6,     1,     3,     2,     0,     1,     3,     3,     0,
                2,     1,     1,     3,     4,     3,     3,     3,     2,     5,
                7,     5,     8,     2,     4,     1,     3,     1,     3,     1,
                1,     1,     1,     1,     2,     1,     2,     1,     3,     4,
                1,     1,     1,     1,     1,     4,     6,     3,     2,     2,
                1,     2,     2,     5,     5,     1,     4,     4,     5,     5,
                1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
                1,     0,     1,     3,     1,     1,     1,     1,     1,     1,
                1,     1,     1,     1,     1
        };


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
    YY_USE (yyvaluep);
    if (!yymsg)
        yymsg = "Deleting";
    YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YY_USE (yykind);
    YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    int yyn;
    /* The return value of yyparse.  */
    int yyresult;
    /* Lookahead symbol kind.  */
    yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
    /* The variables used to return semantic value and location from the
       action routines.  */
    YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

    /* The number of symbols on the RHS of the reduced rule.
       Keep to zero when no symbol should be popped.  */
    int yylen = 0;

    YYDPRINTF ((stderr, "Starting parse\n"));

    yychar = YYEMPTY; /* Cause a token to be read.  */

    goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
    yynewstate:
    /* In all cases, when you get here, the value and location stacks
       have just been pushed.  So pushing a state here evens the stacks.  */
    yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
    yysetstate:
    YYDPRINTF ((stderr, "Entering state %d\n", yystate));
    YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
    YY_IGNORE_USELESS_CAST_BEGIN
    *yyssp = YY_CAST (yy_state_t, yystate);
    YY_IGNORE_USELESS_CAST_END
    YY_STACK_PRINT (yyss, yyssp);

    if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
        YYNOMEM;
#else
    {
        /* Get the current used size of the three stacks, in elements.  */
        YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
        {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
        /* Extend the stack our own way.  */
        if (YYMAXDEPTH <= yystacksize)
            YYNOMEM;
        yystacksize *= 2;
        if (YYMAXDEPTH < yystacksize)
            yystacksize = YYMAXDEPTH;

        {
            yy_state_t *yyss1 = yyss;
            union yyalloc *yyptr =
                    YY_CAST (union yyalloc *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
            if (! yyptr)
                YYNOMEM;
            YYSTACK_RELOCATE (yyss_alloc, yyss);
            YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
            if (yyss1 != yyssa)
                YYSTACK_FREE (yyss1);
        }
# endif

        yyssp = yyss + yysize - 1;
        yyvsp = yyvs + yysize - 1;

        YY_IGNORE_USELESS_CAST_BEGIN
        YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                YY_CAST (long, yystacksize)));
        YY_IGNORE_USELESS_CAST_END

        if (yyss + yystacksize - 1 <= yyssp)
            YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


    if (yystate == YYFINAL)
        YYACCEPT;

    goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
    yybackup:
    /* Do appropriate processing given the current state.  Read a
       lookahead token if we need one and don't already have one.  */

    /* First try to decide what to do without reference to lookahead token.  */
    yyn = yypact[yystate];
    if (yypact_value_is_default (yyn))
        goto yydefault;

    /* Not known => get a lookahead token if don't already have one.  */

    /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
    if (yychar == YYEMPTY)
    {
        YYDPRINTF ((stderr, "Reading a token\n"));
        yychar = yylex ();
    }

    if (yychar <= YYEOF)
    {
        yychar = YYEOF;
        yytoken = YYSYMBOL_YYEOF;
        YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
    else if (yychar == YYerror)
    {
        /* The scanner already issued an error message, process directly
           to error recovery.  But do not keep the error token as
           lookahead, it is too special and may lead us to an endless
           loop in error recovery. */
        yychar = YYUNDEF;
        yytoken = YYSYMBOL_YYerror;
        goto yyerrlab1;
    }
    else
    {
        yytoken = YYTRANSLATE (yychar);
        YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
        goto yydefault;
    yyn = yytable[yyn];
    if (yyn <= 0)
    {
        if (yytable_value_is_error (yyn))
            goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
    }

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus)
        yyerrstatus--;

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
    yystate = yyn;
    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    *++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END

    /* Discard the shifted token.  */
    yychar = YYEMPTY;
    goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
    yydefault:
    yyn = yydefact[yystate];
    if (yyn == 0)
        goto yyerrlab;
    goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
    yyreduce:
    /* yyn is the number of a rule to reduce with.  */
    yylen = yyr2[yyn];

    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  Assigning to YYVAL
       unconditionally makes the parser a bit smaller, and it avoids a
       GCC warning that YYVAL may be used uninitialized.  */
    yyval = yyvsp[1-yylen];


    YY_REDUCE_PRINT (yyn);
    switch (yyn)
    {
        case 2: /* Program: ListTopDef  */
#line 176 "Latte.y"
        {  std::reverse((yyvsp[0].listtopdef_)->begin(),(yyvsp[0].listtopdef_)->end()) ;(yyval.program_) = new Prog((yyvsp[0].listtopdef_)); yyval.program_->line = yy_mylinenumber; YY_RESULT_Program_= (yyval.program_); }
#line 1448 "Parser.C"
            break;

        case 3: /* TopDef: Type _IDENT_ _SYMB_0 ListArg _SYMB_1 Block  */
#line 178 "Latte.y"
        {  std::reverse((yyvsp[-2].listarg_)->begin(),(yyvsp[-2].listarg_)->end()) ;(yyval.topdef_) = new FnDef((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].listarg_), (yyvsp[0].block_));yyval.topdef_->line = yy_mylinenumber;  }
#line 1454 "Parser.C"
            break;

        case 4: /* TopDef: _SYMB_29 _IDENT_ _SYMB_2 ListClsFld _SYMB_3  */
#line 179 "Latte.y"
        {  std::reverse((yyvsp[-1].listclsfld_)->begin(),(yyvsp[-1].listclsfld_)->end()) ;(yyval.topdef_) = new ClsDef((yyvsp[-3].string_), (yyvsp[-1].listclsfld_));yyval.topdef_->line = yy_mylinenumber;  }
#line 1460 "Parser.C"
            break;

        case 5: /* TopDef: _SYMB_29 _IDENT_ _SYMB_31 _IDENT_ _SYMB_2 ListClsFld _SYMB_3  */
#line 180 "Latte.y"
        {  std::reverse((yyvsp[-1].listclsfld_)->begin(),(yyvsp[-1].listclsfld_)->end()) ;(yyval.topdef_) = new InhClsDef((yyvsp[-5].string_), (yyvsp[-3].string_), (yyvsp[-1].listclsfld_)); yyval.topdef_->line = yy_mylinenumber; }
#line 1466 "Parser.C"
            break;

        case 6: /* ListClsFld: ClsFld  */
#line 182 "Latte.y"
        {  (yyval.listclsfld_) = new ListClsFld() ; (yyval.listclsfld_)->push_back((yyvsp[0].clsfld_));yyval.listclsfld_->line = yy_mylinenumber;  }
#line 1472 "Parser.C"
            break;

        case 7: /* ListClsFld: ClsFld ListClsFld  */
#line 183 "Latte.y"
        {  (yyvsp[0].listclsfld_)->push_back((yyvsp[-1].clsfld_)) ; (yyval.listclsfld_) = (yyvsp[0].listclsfld_) ; yyval.listclsfld_->line = yy_mylinenumber;  }
#line 1478 "Parser.C"
            break;

        case 8: /* ListTopDef: TopDef  */
#line 185 "Latte.y"
        {  (yyval.listtopdef_) = new ListTopDef() ; (yyval.listtopdef_)->push_back((yyvsp[0].topdef_));  yyval.listtopdef_->line = yy_mylinenumber;  }
#line 1484 "Parser.C"
            break;

        case 9: /* ListTopDef: TopDef ListTopDef  */
#line 186 "Latte.y"
        {  (yyvsp[0].listtopdef_)->push_back((yyvsp[-1].topdef_)) ; (yyval.listtopdef_) = (yyvsp[0].listtopdef_) ;  yyval.listtopdef_->line = yy_mylinenumber; }
#line 1490 "Parser.C"
            break;

        case 10: /* ClsFld: Type ListIdent _SYMB_4  */
#line 188 "Latte.y"
        {  std::reverse((yyvsp[-1].listident_)->begin(),(yyvsp[-1].listident_)->end()) ;(yyval.clsfld_) = new VarDef((yyvsp[-2].type_), (yyvsp[-1].listident_));   yyval.clsfld_->line = yy_mylinenumber; }
#line 1496 "Parser.C"
            break;

        case 11: /* ClsFld: Type _IDENT_ _SYMB_0 ListArg _SYMB_1 Block  */
#line 189 "Latte.y"
        {  std::reverse((yyvsp[-2].listarg_)->begin(),(yyvsp[-2].listarg_)->end()) ;(yyval.clsfld_) = new MetDef((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].listarg_), (yyvsp[0].block_));  yyval.clsfld_->line = yy_mylinenumber;}
#line 1502 "Parser.C"
            break;

        case 12: /* ListIdent: _IDENT_  */
#line 191 "Latte.y"
        {  (yyval.listident_) = new ListIdent() ; (yyval.listident_)->push_back((yyvsp[0].string_));yyval.listident_->line = yy_mylinenumber;  }
#line 1508 "Parser.C"
            break;

        case 13: /* ListIdent: _IDENT_ _SYMB_5 ListIdent  */
#line 192 "Latte.y"
        {  (yyvsp[0].listident_)->push_back((yyvsp[-2].string_)) ; (yyval.listident_) = (yyvsp[0].listident_) ; yyval.listident_->line = yy_mylinenumber; }
#line 1514 "Parser.C"
            break;

        case 14: /* Arg: Type _IDENT_  */
#line 194 "Latte.y"
        {  (yyval.arg_) = new Ar((yyvsp[-1].type_), (yyvsp[0].string_)); ; yyval.arg_->line = yy_mylinenumber; }
#line 1520 "Parser.C"
            break;

        case 15: /* ListArg: %empty  */
#line 196 "Latte.y"
        {  (yyval.listarg_) = new ListArg();    yyval.listarg_->line = yy_mylinenumber;}
#line 1526 "Parser.C"
            break;

        case 16: /* ListArg: Arg  */
#line 197 "Latte.y"
        {  (yyval.listarg_) = new ListArg() ; (yyval.listarg_)->push_back((yyvsp[0].arg_));    yyval.listarg_->line = yy_mylinenumber;}
#line 1532 "Parser.C"
            break;

        case 17: /* ListArg: Arg _SYMB_5 ListArg  */
#line 198 "Latte.y"
        {  (yyvsp[0].listarg_)->push_back((yyvsp[-2].arg_)) ; (yyval.listarg_) = (yyvsp[0].listarg_) ;yyval.listarg_->line = yy_mylinenumber;  }
#line 1538 "Parser.C"
            break;

        case 18: /* Block: _SYMB_2 ListStmt _SYMB_3  */
#line 200 "Latte.y"
        {  (yyval.block_) = new Blk((yyvsp[-1].liststmt_)); ; yyval.block_->line = yy_mylinenumber; }
#line 1544 "Parser.C"
            break;

        case 19: /* ListStmt: %empty  */
#line 202 "Latte.y"
        {  (yyval.liststmt_) = new ListStmt();   yyval.liststmt_->line = yy_mylinenumber; }
#line 1550 "Parser.C"
            break;

        case 20: /* ListStmt: ListStmt Stmt  */
#line 203 "Latte.y"
        {  (yyvsp[-1].liststmt_)->push_back((yyvsp[0].stmt_)) ; (yyval.liststmt_) = (yyvsp[-1].liststmt_) ;  yyval.liststmt_->line = yy_mylinenumber;  }
#line 1556 "Parser.C"
            break;

        case 21: /* Stmt: _SYMB_4  */
#line 205 "Latte.y"
        {  (yyval.stmt_) = new Empty(); ; yyval.stmt_->line = yy_mylinenumber; }
#line 1562 "Parser.C"
            break;

        case 22: /* Stmt: Block  */
#line 206 "Latte.y"
        {  (yyval.stmt_) = new BStmt((yyvsp[0].block_));   yyval.stmt_->line = yy_mylinenumber; }
#line 1568 "Parser.C"
            break;

        case 23: /* Stmt: Type ListItem _SYMB_4  */
#line 207 "Latte.y"
        {  std::reverse((yyvsp[-1].listitem_)->begin(),(yyvsp[-1].listitem_)->end()) ;(yyval.stmt_) = new Decl((yyvsp[-2].type_), (yyvsp[-1].listitem_));yyval.stmt_->line = yy_mylinenumber;  }
#line 1574 "Parser.C"
            break;

        case 24: /* Stmt: Expr _SYMB_6 Expr _SYMB_4  */
#line 208 "Latte.y"
        {  (yyval.stmt_) = new Ass((yyvsp[-3].expr_), (yyvsp[-1].expr_)); yyval.stmt_->line = yy_mylinenumber; }
#line 1580 "Parser.C"
            break;

        case 25: /* Stmt: Expr _SYMB_7 _SYMB_4  */
#line 209 "Latte.y"
        {  (yyval.stmt_) = new Incr((yyvsp[-2].expr_)); yyval.stmt_->line = yy_mylinenumber; }
#line 1586 "Parser.C"
            break;

        case 26: /* Stmt: Expr _SYMB_8 _SYMB_4  */
#line 210 "Latte.y"
        {  (yyval.stmt_) = new Decr((yyvsp[-2].expr_)); yyval.stmt_->line = yy_mylinenumber; }
#line 1592 "Parser.C"
            break;

        case 27: /* Stmt: _SYMB_38 Expr _SYMB_4  */
#line 211 "Latte.y"
        {  (yyval.stmt_) = new Ret((yyvsp[-1].expr_)); yyval.stmt_->line = yy_mylinenumber; }
#line 1598 "Parser.C"
            break;

        case 28: /* Stmt: _SYMB_38 _SYMB_4  */
#line 212 "Latte.y"
        {  (yyval.stmt_) = new VRet();  yyval.stmt_->line = yy_mylinenumber; }
#line 1604 "Parser.C"
            break;

        case 29: /* Stmt: _SYMB_34 _SYMB_0 Expr _SYMB_1 Stmt  */
#line 213 "Latte.y"
        {  (yyval.stmt_) = new Cond((yyvsp[-2].expr_), (yyvsp[0].stmt_)); yyval.stmt_->line = yy_mylinenumber;  }
#line 1610 "Parser.C"
            break;

        case 30: /* Stmt: _SYMB_34 _SYMB_0 Expr _SYMB_1 Stmt _SYMB_30 Stmt  */
#line 214 "Latte.y"
        {  (yyval.stmt_) = new CondElse((yyvsp[-4].expr_), (yyvsp[-2].stmt_), (yyvsp[0].stmt_)); yyval.stmt_->line = yy_mylinenumber;  }
#line 1616 "Parser.C"
            break;

        case 31: /* Stmt: _SYMB_42 _SYMB_0 Expr _SYMB_1 Stmt  */
#line 215 "Latte.y"
        {  (yyval.stmt_) = new While((yyvsp[-2].expr_), (yyvsp[0].stmt_)); yyval.stmt_->line = yy_mylinenumber;  }
#line 1622 "Parser.C"
            break;

        case 32: /* Stmt: _SYMB_33 _SYMB_0 Type _IDENT_ _SYMB_9 Expr _SYMB_1 Stmt  */
#line 216 "Latte.y"
        {  (yyval.stmt_) = new ForEach((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].expr_), (yyvsp[0].stmt_)); yyval.stmt_->line = yy_mylinenumber;  }
#line 1628 "Parser.C"
            break;

        case 33: /* Stmt: Expr _SYMB_4  */
#line 217 "Latte.y"
        {  (yyval.stmt_) = new SExp((yyvsp[-1].expr_)); yyval.stmt_->line = yy_mylinenumber;  }
#line 1634 "Parser.C"
            break;

        case 34: /* Stmt: _SYMB_0 Expr _SYMB_1 _SYMB_4  */
#line 218 "Latte.y"
        {  (yyval.stmt_) = new SExpParen((yyvsp[-2].expr_)); ; yyval.item_->line = yy_mylinenumber; }
#line 1640 "Parser.C"
            break;

        case 35: /* Item: _IDENT_  */
#line 220 "Latte.y"
        {  (yyval.item_) = new NoInit((yyvsp[0].string_)); yyval.item_->line = yy_mylinenumber; }
#line 1646 "Parser.C"
            break;

        case 36: /* Item: _IDENT_ _SYMB_6 Expr  */
#line 221 "Latte.y"
        {  (yyval.item_) = new Init((yyvsp[-2].string_), (yyvsp[0].expr_)); yyval.item_->line = yy_mylinenumber; }
#line 1652 "Parser.C"
            break;

        case 37: /* ListItem: Item  */
#line 223 "Latte.y"
        {  (yyval.listitem_) = new ListItem() ; (yyval.listitem_)->push_back((yyvsp[0].item_)); yyval.listitem_->line = yy_mylinenumber;  }
#line 1658 "Parser.C"
            break;

        case 38: /* ListItem: Item _SYMB_5 ListItem  */
#line 224 "Latte.y"
        {  (yyvsp[0].listitem_)->push_back((yyvsp[-2].item_)) ; (yyval.listitem_) = (yyvsp[0].listitem_) ; yyval.listitem_->line = yy_mylinenumber;   }
#line 1664 "Parser.C"
            break;

        case 39: /* SimpleType: _SYMB_35  */
#line 226 "Latte.y"
        {  (yyval.simpletype_) = new Int(); yyval.simpletype_->line = yy_mylinenumber; }
#line 1670 "Parser.C"
            break;

        case 40: /* SimpleType: _SYMB_39  */
#line 227 "Latte.y"
        {  (yyval.simpletype_) = new Str(); yyval.simpletype_->line = yy_mylinenumber; }
#line 1676 "Parser.C"
            break;

        case 41: /* SimpleType: _SYMB_28  */
#line 228 "Latte.y"
        {  (yyval.simpletype_) = new Bool(); yyval.simpletype_->line = yy_mylinenumber; }
#line 1682 "Parser.C"
            break;

        case 42: /* SimpleType: _SYMB_41  */
#line 229 "Latte.y"
        {  (yyval.simpletype_) = new Void(); yyval.simpletype_->line = yy_mylinenumber; }
#line 1688 "Parser.C"
            break;

        case 43: /* Type: SimpleType  */
#line 231 "Latte.y"
        {  (yyval.type_) = new SimpleVarType((yyvsp[0].simpletype_)); yyval.type_->line = yy_mylinenumber; }
#line 1694 "Parser.C"
            break;

        case 44: /* Type: SimpleType _SYMB_10  */
#line 232 "Latte.y"
        {  (yyval.type_) = new SimpleArrType((yyvsp[-1].simpletype_)); yyval.type_->line = yy_mylinenumber; }
#line 1700 "Parser.C"
            break;

        case 45: /* Type: _IDENT_  */
#line 233 "Latte.y"
        {  (yyval.type_) = new VarType((yyvsp[0].string_));  yyval.type_->line = yy_mylinenumber; }
#line 1706 "Parser.C"
            break;

        case 46: /* Type: _IDENT_ _SYMB_10  */
#line 234 "Latte.y"
        {  (yyval.type_) = new ArrType((yyvsp[-1].string_)); yyval.type_->line = yy_mylinenumber; }
#line 1712 "Parser.C"
            break;

        case 47: /* Expr8: _IDENT_  */
#line 240 "Latte.y"
        {  (yyval.expr_) = new EVar((yyvsp[0].string_));   yyval.expr_->line = yy_mylinenumber;}
#line 1718 "Parser.C"
            break;

        case 48: /* Expr8: Expr8 _SYMB_11 _IDENT_  */
#line 241 "Latte.y"
        {  (yyval.expr_) = new EClsVar((yyvsp[-2].expr_), (yyvsp[0].string_)); yyval.expr_->line = yy_mylinenumber; }
#line 1724 "Parser.C"
            break;

        case 49: /* Expr8: Expr8 _SYMB_12 Expr _SYMB_13  */
#line 242 "Latte.y"
        {  (yyval.expr_) = new EArrVar((yyvsp[-3].expr_), (yyvsp[-1].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1730 "Parser.C"
            break;

        case 50: /* Expr8: _INTEGER_  */
#line 243 "Latte.y"
        {  (yyval.expr_) = new ELitInt((yyvsp[0].int_)); yyval.expr_->line = yy_mylinenumber;  }
#line 1736 "Parser.C"
            break;

        case 51: /* Expr8: _STRING_  */
#line 244 "Latte.y"
        {  (yyval.expr_) = new EString((yyvsp[0].string_)); yyval.expr_->line = yy_mylinenumber; }
#line 1742 "Parser.C"
            break;

        case 52: /* Expr8: _SYMB_40  */
#line 245 "Latte.y"
        {  (yyval.expr_) = new ELitTrue(); yyval.expr_->line = yy_mylinenumber;  }
#line 1748 "Parser.C"
            break;

        case 53: /* Expr8: _SYMB_32  */
#line 246 "Latte.y"
        {  (yyval.expr_) = new ELitFalse(); yyval.expr_->line = yy_mylinenumber; }
#line 1754 "Parser.C"
            break;

        case 54: /* Expr8: _SYMB_37  */
#line 247 "Latte.y"
        {  (yyval.expr_) = new ELitNull();  yyval.expr_->line = yy_mylinenumber; }
#line 1760 "Parser.C"
            break;

        case 55: /* Expr8: _IDENT_ _SYMB_0 ListExpr _SYMB_1  */
#line 248 "Latte.y"
        {  std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new EApp((yyvsp[-3].string_), (yyvsp[-1].listexpr_));yyval.expr_->line = yy_mylinenumber;   }
#line 1766 "Parser.C"
            break;

        case 56: /* Expr8: Expr8 _SYMB_11 _IDENT_ _SYMB_0 ListExpr _SYMB_1  */
#line 249 "Latte.y"
        {  std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new EClsApp((yyvsp[-5].expr_), (yyvsp[-3].string_), (yyvsp[-1].listexpr_)); yyval.expr_->line = yy_mylinenumber;  }
#line 1772 "Parser.C"
            break;

        case 57: /* Expr8: _SYMB_0 Expr _SYMB_1  */
#line 250 "Latte.y"
        {  (yyval.expr_) = (yyvsp[-1].expr_);yyval.expr_->line = yy_mylinenumber;  }
#line 1778 "Parser.C"
            break;

        case 58: /* Expr7: _SYMB_14 Expr8  */
#line 252 "Latte.y"
        {  (yyval.expr_) = new ENeg((yyvsp[0].expr_)); yyval.expr_->line = yy_mylinenumber; }
#line 1784 "Parser.C"
            break;

        case 59: /* Expr7: _SYMB_15 Expr8  */
#line 253 "Latte.y"
        {  (yyval.expr_) = new ENot((yyvsp[0].expr_)); yyval.expr_->line = yy_mylinenumber; }
#line 1790 "Parser.C"
            break;

        case 60: /* Expr7: Expr8  */
#line 254 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_); yyval.expr_->line = yy_mylinenumber; }
#line 1796 "Parser.C"
            break;

        case 61: /* Expr6: _SYMB_36 _IDENT_  */
#line 256 "Latte.y"
        {  (yyval.expr_) = new EVarNew((yyvsp[0].string_)); yyval.expr_->line = yy_mylinenumber; }
#line 1802 "Parser.C"
            break;

        case 62: /* Expr6: _SYMB_36 SimpleType  */
#line 257 "Latte.y"
        {  (yyval.expr_) = new EVarSimpleNew((yyvsp[0].simpletype_)); yyval.expr_->line = yy_mylinenumber; }
#line 1808 "Parser.C"
            break;

        case 63: /* Expr6: _SYMB_36 _IDENT_ _SYMB_12 Expr _SYMB_13  */
#line 258 "Latte.y"
        {  (yyval.expr_) = new EArrNew((yyvsp[-3].string_), (yyvsp[-1].expr_)); yyval.expr_->line = yy_mylinenumber; }
#line 1814 "Parser.C"
            break;

        case 64: /* Expr6: _SYMB_36 SimpleType _SYMB_12 Expr _SYMB_13  */
#line 259 "Latte.y"
        {  (yyval.expr_) = new EArrSimpleNew((yyvsp[-3].simpletype_), (yyvsp[-1].expr_)); yyval.expr_->line = yy_mylinenumber; }
#line 1820 "Parser.C"
            break;

        case 65: /* Expr6: Expr7  */
#line 260 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_); yyval.expr_->line = yy_mylinenumber; }
#line 1826 "Parser.C"
            break;

        case 66: /* Expr5: _SYMB_0 _IDENT_ _SYMB_1 Expr5  */
#line 262 "Latte.y"
        {  (yyval.expr_) = new EVarCast((yyvsp[-2].string_), (yyvsp[0].expr_));   yyval.expr_->line = yy_mylinenumber;}
#line 1832 "Parser.C"
            break;

        case 67: /* Expr5: _SYMB_0 SimpleType _SYMB_1 Expr5  */
#line 263 "Latte.y"
        {  (yyval.expr_) = new EVarSimpleCast((yyvsp[-2].simpletype_), (yyvsp[0].expr_));   yyval.expr_->line = yy_mylinenumber;}
#line 1838 "Parser.C"
            break;

        case 68: /* Expr5: _SYMB_0 _IDENT_ _SYMB_10 _SYMB_1 Expr5  */
#line 264 "Latte.y"
        {  (yyval.expr_) = new EArrCast((yyvsp[-3].string_), (yyvsp[0].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1844 "Parser.C"
            break;

        case 69: /* Expr5: _SYMB_0 SimpleType _SYMB_10 _SYMB_1 Expr5  */
#line 265 "Latte.y"
        {  (yyval.expr_) = new EArrSimpleCast((yyvsp[-3].simpletype_), (yyvsp[0].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1850 "Parser.C"
            break;

        case 70: /* Expr5: Expr6  */
#line 266 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_); yyval.expr_->line = yy_mylinenumber;  }
#line 1856 "Parser.C"
            break;

        case 71: /* Expr4: Expr4 MulOp Expr5  */
#line 268 "Latte.y"
        {  (yyval.expr_) = new EMul((yyvsp[-2].expr_), (yyvsp[-1].mulop_), (yyvsp[0].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1862 "Parser.C"
            break;

        case 72: /* Expr4: Expr5  */
#line 269 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_);  yyval.expr_->line = yy_mylinenumber; }
#line 1868 "Parser.C"
            break;

        case 73: /* Expr3: Expr3 AddOp Expr4  */
#line 271 "Latte.y"
        {  (yyval.expr_) = new EAdd((yyvsp[-2].expr_), (yyvsp[-1].addop_), (yyvsp[0].expr_)); yyval.expr_->line = yy_mylinenumber;  }
#line 1874 "Parser.C"
            break;

        case 74: /* Expr3: Expr4  */
#line 272 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_); yyval.expr_->line = yy_mylinenumber;  }
#line 1880 "Parser.C"
            break;

        case 75: /* Expr2: Expr2 RelOp Expr3  */
#line 274 "Latte.y"
        {  (yyval.expr_) = new ERel((yyvsp[-2].expr_), (yyvsp[-1].relop_), (yyvsp[0].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1886 "Parser.C"
            break;

        case 76: /* Expr2: Expr3  */
#line 275 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_);  yyval.expr_->line = yy_mylinenumber; }
#line 1892 "Parser.C"
            break;

        case 77: /* Expr1: Expr2 _SYMB_16 Expr1  */
#line 277 "Latte.y"
        {  (yyval.expr_) = new EAnd((yyvsp[-2].expr_), (yyvsp[0].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1898 "Parser.C"
            break;

        case 78: /* Expr1: Expr2  */
#line 278 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_);  yyval.expr_->line = yy_mylinenumber; }
#line 1904 "Parser.C"
            break;

        case 79: /* Expr: Expr1 _SYMB_17 Expr  */
#line 280 "Latte.y"
        {  (yyval.expr_) = new EOr((yyvsp[-2].expr_), (yyvsp[0].expr_));  yyval.expr_->line = yy_mylinenumber; }
#line 1910 "Parser.C"
            break;

        case 80: /* Expr: Expr1  */
#line 281 "Latte.y"
        {  (yyval.expr_) = (yyvsp[0].expr_);  yyval.expr_->line = yy_mylinenumber; }
#line 1916 "Parser.C"
            break;

        case 81: /* ListExpr: %empty  */
#line 283 "Latte.y"
        {  (yyval.listexpr_) = new ListExpr(); yyval.listexpr_->line = yy_mylinenumber; }
#line 1922 "Parser.C"
            break;

        case 82: /* ListExpr: Expr  */
#line 284 "Latte.y"
        {  (yyval.listexpr_) = new ListExpr() ; (yyval.listexpr_)->push_back((yyvsp[0].expr_)); yyval.listexpr_->line = yy_mylinenumber; }
#line 1928 "Parser.C"
            break;

        case 83: /* ListExpr: Expr _SYMB_5 ListExpr  */
#line 285 "Latte.y"
        {  (yyvsp[0].listexpr_)->push_back((yyvsp[-2].expr_)) ; (yyval.listexpr_) = (yyvsp[0].listexpr_) ; yyval.listexpr_->line = yy_mylinenumber; }
#line 1934 "Parser.C"
            break;

        case 84: /* AddOp: _SYMB_18  */
#line 287 "Latte.y"
        {  (yyval.addop_) = new Plus(); yyval.addop_->line = yy_mylinenumber; }
#line 1940 "Parser.C"
            break;

        case 85: /* AddOp: _SYMB_14  */
#line 288 "Latte.y"
        {  (yyval.addop_) = new Minus();  yyval.addop_->line = yy_mylinenumber; }
#line 1946 "Parser.C"
            break;

        case 86: /* MulOp: _SYMB_19  */
#line 290 "Latte.y"
        {  (yyval.mulop_) = new Times();yyval.mulop_->line = yy_mylinenumber;  }
#line 1952 "Parser.C"
            break;

        case 87: /* MulOp: _SYMB_20  */
#line 291 "Latte.y"
        {  (yyval.mulop_) = new Div(); yyval.mulop_->line = yy_mylinenumber; }
#line 1958 "Parser.C"
            break;

        case 88: /* MulOp: _SYMB_21  */
#line 292 "Latte.y"
        {  (yyval.mulop_) = new Mod(); yyval.mulop_->line = yy_mylinenumber; }
#line 1964 "Parser.C"
            break;

        case 89: /* RelOp: _SYMB_22  */
#line 294 "Latte.y"
        {  (yyval.relop_) = new LTH(); yyval.relop_->line = yy_mylinenumber; }
#line 1970 "Parser.C"
            break;

        case 90: /* RelOp: _SYMB_23  */
#line 295 "Latte.y"
        {  (yyval.relop_) = new LE(); yyval.relop_->line = yy_mylinenumber; }
#line 1976 "Parser.C"
            break;

        case 91: /* RelOp: _SYMB_24  */
#line 296 "Latte.y"
        {  (yyval.relop_) = new GTH();  yyval.relop_->line = yy_mylinenumber;}
#line 1982 "Parser.C"
            break;

        case 92: /* RelOp: _SYMB_25  */
#line 297 "Latte.y"
        {  (yyval.relop_) = new GE(); yyval.relop_->line = yy_mylinenumber; }
#line 1988 "Parser.C"
            break;

        case 93: /* RelOp: _SYMB_26  */
#line 298 "Latte.y"
        {  (yyval.relop_) = new EQU();  yyval.relop_->line = yy_mylinenumber;}
#line 1994 "Parser.C"
            break;

        case 94: /* RelOp: _SYMB_27  */
#line 299 "Latte.y"
        {  (yyval.relop_) = new NE();  yyval.relop_->line = yy_mylinenumber;}
#line 2000 "Parser.C"
            break;


#line 2004 "Parser.C"

        default: break;
    }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action invokes
       YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
       if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
       incorrect destructor might then be invoked immediately.  In the
       case of YYERROR or YYBACKUP, subsequent parser actions might lead
       to an incorrect destructor call or verbose syntax error message
       before the lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

    YYPOPSTACK (yylen);
    yylen = 0;

    *++yyvsp = yyval;

    /* Now 'shift' the result of the reduction.  Determine what state
       that goes to, based on the state we popped back to and the rule
       number reduced by.  */
    {
        const int yylhs = yyr1[yyn] - YYNTOKENS;
        const int yyi = yypgoto[yylhs] + *yyssp;
        yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
                   ? yytable[yyi]
                   : yydefgoto[yylhs]);
    }

    goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
    yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus)
    {
        ++yynerrs;
        yyerror (YY_("syntax error"));
    }

    if (yyerrstatus == 3)
    {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        if (yychar <= YYEOF)
        {
            /* Return failure if at end of input.  */
            if (yychar == YYEOF)
                YYABORT;
        }
        else
        {
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
        }
    }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
    yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and the
       label yyerrorlab therefore never appears in user code.  */
    if (0)
        YYERROR;
    ++yynerrs;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    YYPOPSTACK (yylen);
    yylen = 0;
    YY_STACK_PRINT (yyss, yyssp);
    yystate = *yyssp;
    goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
    yyerrlab1:
    yyerrstatus = 3;      /* Each real token shifted decrements this.  */

    /* Pop stack until we find a state that shifts the error token.  */
    for (;;)
    {
        yyn = yypact[yystate];
        if (!yypact_value_is_default (yyn))
        {
            yyn += YYSYMBOL_YYerror;
            if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
                yyn = yytable[yyn];
                if (0 < yyn)
                    break;
            }
        }

        /* Pop the current state because it cannot handle the error token.  */
        if (yyssp == yyss)
            YYABORT;


        yydestruct ("Error: popping",
                    YY_ACCESSING_SYMBOL (yystate), yyvsp);
        YYPOPSTACK (1);
        yystate = *yyssp;
        YY_STACK_PRINT (yyss, yyssp);
    }

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    *++yyvsp = yylval;
    YY_IGNORE_MAYBE_UNINITIALIZED_END


    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

    yystate = yyn;
    goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
    yyacceptlab:
    yyresult = 0;
    goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
    yyabortlab:
    yyresult = 1;
    goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
    yyexhaustedlab:
    yyerror (YY_("memory exhausted"));
    yyresult = 2;
    goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
    yyreturnlab:
    if (yychar != YYEMPTY)
    {
        /* Make sure we have latest lookahead translation.  See comments at
           user semantic actions for why this is necessary.  */
        yytoken = YYTRANSLATE (yychar);
        yydestruct ("Cleanup: discarding lookahead",
                    yytoken, &yylval);
    }
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    YYPOPSTACK (yylen);
    YY_STACK_PRINT (yyss, yyssp);
    while (yyssp != yyss)
    {
        yydestruct ("Cleanup: popping",
                    YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
        YYPOPSTACK (1);
    }
#ifndef yyoverflow
    if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif

    return yyresult;
}

