#include <iostream>
#include "prettyPrintPhase/prettyPrintPhase.hpp"

using std::cout;

void PrettyPrintPhase::dispatch(const NStatement &stmt) const {}
void PrettyPrintPhase::dispatch(const NStmtAssign &assignStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtBlock &blockStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtDec &decStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtEmpty &emptyStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtExp &expStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtFor &forStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtIfElse &ifElseStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtIncDec &incDecStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtPrint &printStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtReturn &returnStmt) const {}
void PrettyPrintPhase::dispatch(const NStmtSwitch &switchStmt) const {}