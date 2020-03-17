#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NExpression &exp) {}
void SymbolHelper::dispatch(const NExpBinary &binaryExp) {}
void SymbolHelper::dispatch(const NExpBuiltin &unaryExp) {}
void SymbolHelper::dispatch(const NExpFuncCall &funcCallExp) {}
void SymbolHelper::dispatch(const NExpIdentifier &idExp) {}
void SymbolHelper::dispatch(const NExpIndexer &indexerExp) {}
void SymbolHelper::dispatch(const NExpLiteral &literalExp) {}
void SymbolHelper::dispatch(const NExpUnary &unaryExp) {}
void SymbolHelper::dispatch(const NExpCaseClause &caseClauseExp) {}
void SymbolHelper::dispatch(const NExpSwitchCase &switchCaseExp) {}