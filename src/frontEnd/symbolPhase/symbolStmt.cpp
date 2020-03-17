#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;

void SymbolHelper::dispatch(const NStatement &stmt) {}
void SymbolHelper::dispatch(const NStmtAssign &assignStmt) {}
void SymbolHelper::dispatch(const NStmtBlock &blockStmt) {}
void SymbolHelper::dispatch(const NStmtBreakContinue &breakContinueStmt) {}
void SymbolHelper::dispatch(const NStmtDec &decStmt) {}
void SymbolHelper::dispatch(const NStmtEmpty &emptyStmt) {}
void SymbolHelper::dispatch(const NStmtExp &expstmt) {}
void SymbolHelper::dispatch(const NStmtFor &forStmt) {}
void SymbolHelper::dispatch(const NStmtIfElse &ifElseStmt) {}
void SymbolHelper::dispatch(const NStmtIncDec &incDecStmt) {}
void SymbolHelper::dispatch(const NStmtPrint &printStmt) {}
void SymbolHelper::dispatch(const NStmtReturn &returnStmt) {}
void SymbolHelper::dispatch(const NStmtSwitch &switchStmt) {}