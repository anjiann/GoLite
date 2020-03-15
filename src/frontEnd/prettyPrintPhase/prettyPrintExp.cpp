#include <iostream>
#include "prettyPrintPhase/prettyPrintPhase.hpp"

using std::cout;
using std::endl;

void PrettyPrintPhase::dispatch(const NExpression &exp) const {}
void PrettyPrintPhase::dispatch(const NExpBinary &binaryExp) const {}
void PrettyPrintPhase::dispatch(const NExpBuiltin &unaryExp) const {}
void PrettyPrintPhase::dispatch(const NExpFuncCall &funcCallExp) const {}
void PrettyPrintPhase::dispatch(const NExpIdentifier &idExp) const {}
void PrettyPrintPhase::dispatch(const NExpIndexer &indexerExp) const {}
void PrettyPrintPhase::dispatch(const NExpLiteral &literalExp) const {}
void PrettyPrintPhase::dispatch(const NExpUnary &unaryExp) const {}
void PrettyPrintPhase::dispatch(const NExpCaseClause &caseClauseExp) const {}
void PrettyPrintPhase::dispatch(const NExpSwitchCase &switchCaseExp) const {}