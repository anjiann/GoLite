/* The first section of a bison file contains:
 *    1. A code section for includes and other arbitrary C code. Copied to the parser verbatim
 *    2. Definition of the yylval union
 *    3. Definition of the tokens
 *    4. Precedence directives
 *    5. The start token
 *    6. Parser options
 */

/* Code section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <string>
#include "tree.hpp"

extern NProgram *program;

// Reference to the line number generated by the scanner
extern int yylineno;
// Reference to the yylex function to quiet a compiler warning
int yylex();

// The yyerror function is called on any syntax error. When using %error-verbose, this function
// takes a single argument (a string) which contains a detailed explanation of the error.
// Otherwise it takes no arguments and it is up to the user to format the error using a minimal
// description provided in yytext.
void yyerror(const char *s) {
	fprintf(stderr, "Error: (line %d) %s\n", yylineno, s);
	exit(1);
}
%}


/* The union directive defines the yylval union used for associating (a) terminals (tokens)
 * returned by flex with additional scanning data (such as identifier/constant values); and
 * optionally (b) non-terminals (variables in productions) with AST information if any.
 */
%union {
	std::string *identifier;

    NProgram *prog;
    std::vector<std::shared_ptr<NDeclaration>> *declist;
    std::vector<std::shared_ptr<NStatement>> *stmtlist;
    NDeclaration *dec;
    NStatement *stmt;
    NExpression *exp;
    NType *type;

    NExpSwitchCase *switchcase;
    NExpIdentifier *id;
    NExpArrIdentifier *arrid;
    NTypeArray *arrtype;

    std::vector<std::shared_ptr<NExpCaseClause>> *caseclauselist;
    std::vector<std::shared_ptr<NExpression>> *explist;
    std::vector<std::pair<string, std::shared_ptr<NType>>> *paramlist;
    std::vector<std::shared_ptr<NExpIdentifier>> *idlist;
}

/* Token directives define the token types to be returned by the scanner (excluding character
 * tokens). Each token definition takes [optionally, a reference to the associated field in the
 * yylval union] and an identifier. Multiple tokens can eb defined per directive by using a list
 * of identifiers separated by spaces.
 */
 //ast nodes
%type <prog> program
%type <declist> topdec
%type <dec> funcdec dec vardec 
%type <stmtlist> stmts
%type <stmt> stmt printstmt ifstmt forstmt simplestmt
%type <exp> exp optexp literalexp binaryexp unaryexp builtinexp 
%type <type> type opttype 

%type <switchcase> switchcase
%type <id> expid
%type <arrid> arrayid
%type <arrtype> arrtype

%type <caseclauselist> caseclauselist
%type <explist> explist optexplist
%type <paramlist> params optparams
%type <idlist> idlist

%token <identifier> tIDENTIFIER tINTLITERAL tFLOATLITERAL tBOOLLITERAL tRUNELITERAL tSTRINGLITERAL

%token tBREAK
%token tCASE
%token tCONST
%token tCHAN
%token tCONTINUE
%token tDEFAULT
%token tDEFER
%token tELSE
%token tFALLTHROUGH
%token tFOR
%token tFUNC
%token tGO
%token tGOTO
%token tIF
%token tIMPORT
%token tINTERFACE
%token tMAP
%token tPACKAGE
%token tRANGE
%token tRETURN
%token tSELECT
%token <identifier> tSTRUCT //not supported in golite_mini
%token tSWITCH
%token tTYPE
%token tVAR
%token tPRINT
%token tPRINTLN
%token tAPPEND //not supported in golite_mini%token <intval>
%token tLEN
%token tCAP
%token tPLUS
%token tMINUS
%token tDIV
%token tMULT
%token tMOD
%token tBWAND
%token tBWOR
%token tBWXOR
%token tRIGHTSHIFT
%token tLEFTSHIFT
%token tBWANDNOT
%token tPLUSASSIGN
%token tMINUSASSIGN
%token tMULTASSIGN
%token tDIVASSIGN
%token tMODASSIGN
%token tBWANDASSIGN
%token tBWORASSIGN
%token tBWXORASSIGN
%token tRSHIFTASSIGN
%token tLSHIFTASSIGN
%token tBWANDNOTASSIGN
%token tAND
%token tOR
%token tARROW
%token tINCREMENT
%token tDECREMENT
%token tEQUAL
%token tLESS
%token tGREATER
%token tASSIGN
%token tNOT
%token tNOTEQ
%token tLESSEQ
%token tGREATEREQ
%token tCOLONASSIGN //not supported in golite_mini
%token tELLIPSIS
%token tLBRACE
%token tLPAREN
%token tLBRACKET
%token tCOMMA
%token tPERIOD
%token tRBRACE
%token tRPAREN
%token tRBRACKET
%token tSEMICOLON
%token tCOLON
%token tNEWLINE


/* Precedence directives resolve grammar ambiguities by breaking ties between shift/reduce
 * operations. Tokens are grouped into precendence levels, with lower precedence coming first
 * and then higher precedence in later directives. Tokens specified in the same directive have
 * the same precedence. Ties at the same level are broken using either %left or %right, which
 * denote left-associative and right-associative respectively.
 */



// %left tOR
// %left tAND tANDNOT
// %left tBWOR tBWXOR
// %left tBWAND
// %left tLEFTSHIFT tRIGHTSHIFT
// %left tEQUAL tNOTEQ 
// %left tGREATEREQ tLESSEQ tGREATER tLESS
// %left tPLUS tMINUS
// %left tMULT tDIV tMOD 
// %left UNARY
// %left tPERIOD // struct field access
// %left tLBRACKET
// %left tLBRACE

%left EXPSTMT
%left EXPLIST
%left tOR
%left tAND tANDNOT
%left tEQUAL tNOTEQ 
%left tGREATEREQ tLESSEQ tGREATER tLESS
%left tPLUS tMINUS tBWOR tBWXOR
%left tMULT tDIV tMOD tLEFTSHIFT tRIGHTSHIFT tBWAND tBWANDNOT
%left tLBRACKET
%left tLBRACE
%left UNARY

/* Unused tokens, only for precedence directives */
%token UNARY 
%token EXPLIST
%token EXPSTMT

/* Start token (by default if this is missing it takes the first production */
%start program

/* Generate the yylloc structure used for storing line numbers with tokens */
%locations
/* Generate detailed error messages */
%error-verbose

/* The second section of a bison file contains the productions. Note that rules with the
 * same LHS may be joined together and separated with a pipe.
 */
%% 

/* Represents the entire program. Makes sure there is only one package dec */
program         : tPACKAGE tIDENTIFIER tSEMICOLON topdec { program = new NProgram(*$2, *$4); delete $2; delete $4; }
                ;

topdec          : %empty { $$ = new NDeclarationList(); }
                | topdec dec { $1->push_back(std::shared_ptr<NDeclaration>($2)); }
                | topdec funcdec { $1->push_back(std::shared_ptr<NDeclaration>($2)); }
                ;

stmts           : %empty { $$ = new NStatementList(); }
                | stmts stmt { $1->push_back(std::shared_ptr<NStatement>($2)); }
                ;

/* ================= DECLARATIONS ================= */
dec             : tVAR vardec { $$ = $2; }
                | tTYPE tIDENTIFIER type tSEMICOLON { $$ = new NDecType(*$2, std::shared_ptr<NType>($3)); delete $2; }
                ;

vardec          : idlist type tSEMICOLON { $$ = new NDecVar(*$1, std::shared_ptr<NType>($2), NExpressionList()); delete $1; }
                | idlist opttype tASSIGN explist tSEMICOLON { $$ = new NDecVar(*$1, std::shared_ptr<NType>($2), *$4); delete $1; delete $4; }
                ;

/* function definitions */
funcdec         : tFUNC tIDENTIFIER tLBRACE optparams tRBRACE tLPAREN stmts tRPAREN tSEMICOLON
                    { $$ = new NDecFunc(*$2, *$4, std::shared_ptr<NType>(new NTypeIdentifier()), *$7); delete $2; delete $4; delete $7; }
                | tFUNC tIDENTIFIER tLBRACE optparams tRBRACE type tLPAREN stmts tRPAREN tSEMICOLON
                    { $$ = new NDecFunc(*$2, *$4, std::shared_ptr<NType>($6), *$8); delete $2; delete $4; delete $8; }
                ;

/* ================== STATEMENTS ================== */

/* TODO weeder for break, continue, return*/
stmt            : dec { $$ = new NStmtDec(std::shared_ptr<NDeclaration>($1)); }
                | exp %prec EXPSTMT { $$ = new NStmtExp(std::shared_ptr<NExpression>($1)); }
                | printstmt { $$ = $1; }
                | ifstmt { $$ = $1; }
                | forstmt {$$ = $1;}
                | simplestmt tSEMICOLON { $$ = $1; }
                | tBREAK tSEMICOLON { $$ = new NStmtBreakContinue(breakStmt); }
                | tCONTINUE tSEMICOLON { $$ = new NStmtBreakContinue(continueStmt); }
                | tLPAREN stmts tRPAREN tSEMICOLON { $$ = new NStmtBlock(*$2); delete $2; }
                | tSWITCH optexp tLPAREN caseclauselist tRPAREN tSEMICOLON { $$ = new NStmtSwitch(*$2, *$4); delete $2; delete $4; }
                | tRETURN optexp tSEMICOLON { $$ = new NStmtReturn(*$2); delete $2; }
                | tSEMICOLON { $$ = new NStmtEmpty(); }
                ;

printstmt       : tPRINT tLBRACE optexplist tRBRACE tSEMICOLON { $$ = new NStmtPrint(*$3, false); delete $3; }
                | tPRINTLN tLBRACE optexplist tRBRACE tSEMICOLON { $$ = new NStmtPrint(*$3, true); delete $3; }
                ;

ifstmt          : tIF exp tLPAREN stmts tRPAREN tSEMICOLON { $$ = new NStmtIfElse(*$2, *$4, NStatementList()); delete $2; delete $4; }
                | tIF exp tLPAREN stmts tRPAREN tELSE ifstmt { $$ = new NStmtIfElse(*$2, *$4, {std::shared_ptr<NStatement>($7)}); delete $2; delete $4; delete $7; }
                | tIF exp tLPAREN stmts tRPAREN tELSE tLPAREN stmts tRPAREN { $$ = new NStmtIfElse(*$2, *$4, *$8); delete $2; delete $4; delete $8; }
                ;

simplestmt      : expid tINCREMENT { $$ = new NStmtIncDec(*$1, true); delete $1; }
                | expid tDECREMENT { $$ = new NStmtIncDec(*$1, false); delete $1; }
                | explist tASSIGN explist { $$ = new NStmtAssign(*$1, std::move(*$3)); delete $1; delete $3; }
                ;

forstmt         : tFOR optexp tLPAREN stmts tRPAREN tSEMICOLON { $$ = new NStmtFor(NStatement(), *$2, NStatement(), *$4); }
                | tFOR tSEMICOLON optexp tSEMICOLON tLPAREN stmts tRPAREN tSEMICOLON 
                    { $$ = new NStmtFor(NStatement(), *$3, NStatement(), *$6); }
                | tFOR simplestmt tSEMICOLON optexp tSEMICOLON tLPAREN stmts tRPAREN tSEMICOLON 
                    { $$ = new NStmtFor(*$2, *$4, NStatement(), *$7); }
                | tFOR tSEMICOLON optexp tSEMICOLON simplestmt tLPAREN stmts tRPAREN tSEMICOLON 
                    { $$ = new NStmtFor(NStatement(), *$3, *$5, *$7); }
                | tFOR simplestmt tSEMICOLON optexp tSEMICOLON simplestmt tLPAREN stmts tRPAREN tSEMICOLON 
                    { $$ = new NStmtFor(*$2, *$4, *$6, *$8); }
                ;

/* ================ EXPRESSIONS ================ */

exp             : literalexp {$$ = $1;}
                | unaryexp {$$ = $1;}
                | binaryexp {$$ = $1;}
                | builtinexp { $$ = $1; }
                | arrayid { $$ = $1; }
                | exp tLBRACE optexplist tRBRACE { $$ = new NExpFunc(*$1, std::move(*$3)); delete $1; delete $3; }  
                | tLBRACE exp tRBRACE { $$ = $2; }
                | tIDENTIFIER { $$ = new NExpIdentifier(*$1); delete $1; }
                ;

literalexp      : tINTLITERAL {$$ = new NExpLiteral(*$1, NExpLiteralKind::intLiteral); delete $1; }
                | tFLOATLITERAL {$$ = new NExpLiteral(*$1, NExpLiteralKind::floatLiteral); delete $1; }
                | tBOOLLITERAL {$$ = new NExpLiteral(*$1, NExpLiteralKind::boolLiteral); delete $1; }
                | tRUNELITERAL {$$ = new NExpLiteral(*$1, NExpLiteralKind::runeLiteral); delete $1; }
                | tSTRINGLITERAL {$$ = new NExpLiteral(*$1, NExpLiteralKind::stringLiteral); delete $1; }
                ;

unaryexp        : tPLUS exp %prec UNARY {$$ = new NExpUnary(*$2, NExpOpKind::plusExp);}
                | tMINUS exp %prec UNARY {$$ = new NExpUnary(*$2, NExpOpKind::minusExp);}
                | tNOT exp %prec UNARY {$$ = new NExpUnary(*$2, NExpOpKind::notExp);}
                | tBWXOR exp %prec UNARY {$$ = new NExpUnary(*$2, NExpOpKind::xorExp);}
                ;

binaryexp       : exp tPLUS exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tMINUS exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tMULT exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tDIV exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tMOD exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tEQUAL exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tLESS exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tNOTEQ exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tGREATEREQ exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tLESSEQ exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tGREATER exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tBWAND exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tBWOR exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tBWANDNOT exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tAND exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tOR exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tBWXOR exp  {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tLEFTSHIFT exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                | exp tRIGHTSHIFT exp {$$ = new NExpBinary(*$1, *$3, NExpOpKind::plusExp);}
                ;

builtinexp      : tLEN tLBRACE exp tRBRACE {$$ = new NExpBuiltin(*$3, NExpBuiltinKind::lenExp);}
                | tCAP tLBRACE exp tRBRACE {$$ = new NExpBuiltin(*$3, NExpBuiltinKind::capExp);}
                ;  

/* ======= TYPE ======= */
opttype         : %empty { $$ = new NTypeIdentifier(); }
                | type { $$ = $1; }
                ;

type            : tIDENTIFIER { $$ = new NTypeIdentifier(*$1); delete $1; }
                | arrtype { $$ = $1; }
                | tLBRACE type tRBRACE { $$ = $2; }
                ;

arrtype         : tLBRACKET tINTLITERAL tRBRACKET tIDENTIFIER { $$ = new NTypeArray(std::stoi(*$2), std::shared_ptr<NType>(new NTypeIdentifier(*$4, true))); delete $2; delete $4;}
                | tLBRACKET tINTLITERAL tRBRACKET arrtype { $$ = new NTypeArray(std::stoi(*$2), std::shared_ptr<NType>($4)); delete $2; }
                ;

/* ================ HELPERS ================= */

arrayid         : tIDENTIFIER tLBRACKET exp tRBRACKET { $$ = new NExpArrIdentifier(*$1); $$->sizeExps.push_back(std::shared_ptr<NExpression>($3)); delete $1; delete $3; }
                | arrayid tLBRACKET exp tRBRACKET { $1->sizeExps.push_back(std::shared_ptr<NExpression>($3)); delete $3; }
                ;

expid           : tIDENTIFIER { $$ = new NExpIdentifier(*$1); delete $1; }
                | arrayid { $$ = $1; }
                ;

// === vector of ast nodes; used as parameters for constructors ===
params          : tIDENTIFIER type { $$ = new ParamList(); $$->push_back(std::make_pair(*$1, std::shared_ptr<NType>($2))); delete $1; }
                | params tCOMMA tIDENTIFIER type { $1->push_back(std::make_pair(*$3, std::shared_ptr<NType>($4))); delete $3; }
                ;

idlist          : tIDENTIFIER { $$ = new NExpIdentifierList(); $$->push_back(std::shared_ptr<NExpIdentifier>(new NExpIdentifier(*$1))); delete $1; }
                | idlist tCOMMA tIDENTIFIER { $1->push_back(std::shared_ptr<NExpIdentifier>(new NExpIdentifier(*$3))); delete $3;}
                ;
                
/* TODO weed for no exp for case, assign(stmt and decl) */
explist         : exp %prec EXPLIST { $$ = new NExpressionList(); $$->push_back(std::shared_ptr<NExpression>($1)); }
                | explist tCOMMA exp { $1->push_back(std::shared_ptr<NExpression>($3)); }
                ; 

caseclauselist  : %empty { $$ = new NExpCaseClauseList(); }
                | caseclauselist switchcase tCOLON stmts { $1->push_back(std::shared_ptr<NExpCaseClause>(new NExpCaseClause(*$2, *$4))); delete $2; delete $4;}
                ;

switchcase      : tCASE explist { $$ = new NExpSwitchCase(*$2); delete $2; }
                | tDEFAULT { $$ = new NExpSwitchCase(NExpressionList()); }

// === optionals; used to reduce the size of ast non-terminals ===

optexp          : %empty {$$ = new NExpression(); }
                | exp { $$ = $1; }
                ;

optparams       : %empty { $$ = new ParamList(); }  
                | params { $$ = $1; }
                ;

optexplist      : %empty { $$ = new NExpressionList(); }
                | explist { $$ = $1; }
                ;

%%