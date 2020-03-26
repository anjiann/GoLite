#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;

void TypecheckDispatcher::dispatch(const NStatement &stmt) const {}
void TypecheckDispatcher::dispatch(const NStmtAssign &assignStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtBlock &blockStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtDec &decStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtEmpty &emptyStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtExp &expstmt) const {}
void TypecheckDispatcher::dispatch(const NStmtFor &forStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtIfElse &ifElseStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtIncDec &incDecStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtPrint &printStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtReturn &returnStmt) const {}
void TypecheckDispatcher::dispatch(const NStmtSwitch &switchStmt) const {}