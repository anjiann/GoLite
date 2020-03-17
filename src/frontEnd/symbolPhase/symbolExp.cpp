#include <iostream>
#include "symbolPhase/symbolPhaseHelper.hpp"

using std::cout;
using std::endl;

void SymbolPhaseHelper::dispatch(const NExpression &exp) {}
void SymbolPhaseHelper::dispatch(const NExpBinary &binaryExp) {}
void SymbolPhaseHelper::dispatch(const NExpBuiltin &unaryExp) {}
void SymbolPhaseHelper::dispatch(const NExpFuncCall &funcCallExp) {}
void SymbolPhaseHelper::dispatch(const NExpIdentifier &idExp) {}
void SymbolPhaseHelper::dispatch(const NExpIndexer &indexerExp) {}
void SymbolPhaseHelper::dispatch(const NExpLiteral &literalExp) {}
void SymbolPhaseHelper::dispatch(const NExpUnary &unaryExp) {}
void SymbolPhaseHelper::dispatch(const NExpCaseClause &caseClauseExp) {}
void SymbolPhaseHelper::dispatch(const NExpSwitchCase &switchCaseExp) {}