#include <iostream>
#include "symbolPhase/symbolPhase.hpp"

using std::cout;
using std::endl;

void SymbolPhase::dispatch(const NExpression &exp) const {}
void SymbolPhase::dispatch(const NExpBinary &binaryExp) const {}
void SymbolPhase::dispatch(const NExpBuiltin &unaryExp) const {}
void SymbolPhase::dispatch(const NExpFuncCall &funcCallExp) const {}
void SymbolPhase::dispatch(const NExpIdentifier &idExp) const {}
void SymbolPhase::dispatch(const NExpIndexer &indexerExp) const {}
void SymbolPhase::dispatch(const NExpLiteral &literalExp) const {}
void SymbolPhase::dispatch(const NExpUnary &unaryExp) const {}
void SymbolPhase::dispatch(const NExpCaseClause &caseClauseExp) const {}
void SymbolPhase::dispatch(const NExpSwitchCase &switchCaseExp) const {}