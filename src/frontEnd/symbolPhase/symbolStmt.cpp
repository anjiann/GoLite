#include <iostream>
#include "symbolPhase/symbolPhaseHelper.hpp"

using std::cout;

void SymbolPhaseHelper::dispatch(const NStatement &stmt) {}
void SymbolPhaseHelper::dispatch(const NStmtAssign &assignStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtBlock &blockStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtBreakContinue &breakContinueStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtDec &decStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtEmpty &emptyStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtExp &expstmt) {}
void SymbolPhaseHelper::dispatch(const NStmtFor &forStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtIfElse &ifElseStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtIncDec &incDecStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtPrint &printStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtReturn &returnStmt) {}
void SymbolPhaseHelper::dispatch(const NStmtSwitch &switchStmt) {}