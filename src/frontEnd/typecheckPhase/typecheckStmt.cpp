#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;

void TypecheckDispatcher::dispatch(const NStatement &stmt) const {
    stmt.accept(*this);
}
void TypecheckDispatcher::dispatch(const NStmtAssign &assignStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtBlock &blockStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtDec &decStmt) const {
    decStmt.dec.accept(*this);
}
void TypecheckDispatcher::dispatch(const NStmtEmpty &emptyStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtExp &expStmt) const {
    expStmt.exp.accept(*this);
}
void TypecheckDispatcher::dispatch(const NStmtFor &forStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtIfElse &ifElseStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtIncDec &incDecStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtPrint &printStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtReturn &returnStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtSwitch &switchStmt) const {}