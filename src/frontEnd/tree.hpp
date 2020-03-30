//contain all the ast constructors and enums used by the parser
#ifndef TREE_H
#define TREE_H

//program
#include "ast/NProgram.hpp"

//declarations
#include "ast/Declaration/NDeclaration.hpp"
#include "ast/Declaration/NDecFunc.hpp"
#include "ast/Declaration/NDecType.hpp"
#include "ast/Declaration/NDecVar.hpp"

//statements
#include "ast/Statement/NStatement.hpp"
#include "ast/Statement/NStmtAssign.hpp"
#include "ast/Statement/NStmtBlock.hpp"
#include "ast/Statement/NStmtBreakContinue.hpp"
#include "ast/Statement/NStmtDec.hpp"
#include "ast/Statement/NStmtEmpty.hpp"
#include "ast/Statement/NStmtExp.hpp"
#include "ast/Statement/NStmtFor.hpp"
#include "ast/Statement/NStmtIfElse.hpp"
#include "ast/Statement/NStmtIncDec.hpp"
#include "ast/Statement/NStmtPrint.hpp"
#include "ast/Statement/NStmtReturn.hpp"
#include "ast/Statement/NStmtSwitch.hpp"

//expressions
#include "ast/Expression/NExpression.hpp"
#include "ast/Expression/NExpArrIdentifier.hpp"
#include "ast/Expression/NExpBinary.hpp"
#include "ast/Expression/NExpBuiltin.hpp"
#include "ast/Expression/NExpFuncCall.hpp"
#include "ast/Expression/NExpIdentifier.hpp"
#include "ast/Expression/NExpIndexer.hpp"
#include "ast/Expression/NExpLiteral.hpp"
#include "ast/Expression/NExpUnary.hpp"
#include "ast/Expression/Switch/NExpCaseClause.hpp"
#include "ast/Expression/Switch/NExpSwitchCase.hpp"

//types
#include "ast/Type/NType.hpp"
#include "ast/Type/NTypeArray.hpp"
#include "ast/Type/NTypeIdentifier.hpp"

//enums
#include "ast/Expression/enums.hpp"

#endif