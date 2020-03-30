#include "weederPhase/weederDispatcher.hpp"

void WeederDispatcher::dispatch(const NExpression &exp) const {
    exp.accept(*this);
}

void WeederDispatcher::dispatch(const NExpArrIdentifier &arrIdExp) const {}
void WeederDispatcher::dispatch(const NExpBinary &binaryExp) const {}
void WeederDispatcher::dispatch(const NExpBuiltin &unaryExp) const {}
void WeederDispatcher::dispatch(const NExpFunc &funcExp) const {}
void WeederDispatcher::dispatch(const NExpIdentifier &idExp) const {}
void WeederDispatcher::dispatch(const NExpIndexer &indexerExp) const {}
void WeederDispatcher::dispatch(const NExpLiteral &literalExp) const {}
void WeederDispatcher::dispatch(const NExpUnary &unaryExp) const {}
void WeederDispatcher::dispatch(const NExpCaseClause &caseClauseExp) const {}
void WeederDispatcher::dispatch(const NExpSwitchCase &switchCaseExp) const {}