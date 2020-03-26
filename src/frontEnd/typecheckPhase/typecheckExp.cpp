#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;

void TypecheckDispatcher::dispatch(const NExpression &exp) const {}
void TypecheckDispatcher::dispatch(const NExpBinary &binaryExp) const {}
void TypecheckDispatcher::dispatch(const NExpBuiltin &unaryExp) const {}
void TypecheckDispatcher::dispatch(const NExpFunc &funcExp) const {}
void TypecheckDispatcher::dispatch(const NExpIdentifier &idExp) const {}
void TypecheckDispatcher::dispatch(const NExpIndexer &indexerExp) const {}
void TypecheckDispatcher::dispatch(const NExpLiteral &literalExp) const {}
void TypecheckDispatcher::dispatch(const NExpUnary &unaryExp) const {}
void TypecheckDispatcher::dispatch(const NExpCaseClause &caseClauseExp) const {}
void TypecheckDispatcher::dispatch(const NExpSwitchCase &switchCaseExp) const {}