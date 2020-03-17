#include <iostream>
#include "prettyPrintPhase/prettyDispatcher.hpp"

using std::cout;

void PrettyDispatcher::dispatch(const NStatement &stmt) const {}
void PrettyDispatcher::dispatch(const NStmtAssign &assignStmt) const {}
void PrettyDispatcher::dispatch(const NStmtBlock &blockStmt) const {}
void PrettyDispatcher::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}
void PrettyDispatcher::dispatch(const NStmtDec &decStmt) const {}
void PrettyDispatcher::dispatch(const NStmtEmpty &emptyStmt) const {}
void PrettyDispatcher::dispatch(const NStmtExp &expStmt) const {}
void PrettyDispatcher::dispatch(const NStmtFor &forStmt) const {}
void PrettyDispatcher::dispatch(const NStmtIfElse &ifElseStmt) const {}
void PrettyDispatcher::dispatch(const NStmtIncDec &incDecStmt) const {}
void PrettyDispatcher::dispatch(const NStmtPrint &printStmt) const {}
void PrettyDispatcher::dispatch(const NStmtReturn &returnStmt) const {}
void PrettyDispatcher::dispatch(const NStmtSwitch &switchStmt) const {}