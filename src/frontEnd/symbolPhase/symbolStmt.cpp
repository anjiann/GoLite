#include <iostream>
#include "symbolPhase/symbolPhase.hpp"

using std::cout;

void SymbolPhase::dispatch(const NStatement &stmt) const {}
void SymbolPhase::dispatch(const NStmtAssign &assignStmt) const {}
void SymbolPhase::dispatch(const NStmtBlock &blockStmt) const {}
void SymbolPhase::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}
void SymbolPhase::dispatch(const NStmtDec &decStmt) const {}
void SymbolPhase::dispatch(const NStmtEmpty &emptyStmt) const {}
void SymbolPhase::dispatch(const NStmtExp &expstmt) const {}
void SymbolPhase::dispatch(const NStmtFor &forStmt) const {}
void SymbolPhase::dispatch(const NStmtIfElse &ifElseStmt) const {}
void SymbolPhase::dispatch(const NStmtIncDec &incDecStmt) const {}
void SymbolPhase::dispatch(const NStmtPrint &printStmt) const {}
void SymbolPhase::dispatch(const NStmtReturn &returnStmt) const {}
void SymbolPhase::dispatch(const NStmtSwitch &switchStmt) const {}