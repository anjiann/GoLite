#include <iostream>
#include "weederPhase/weederDispatcher.hpp"

using std::cerr;
using std::endl;

void WeederDispatcher::dispatch(const NStatement &stmt) const {
    stmt.accept(*this);
}

void WeederDispatcher::dispatch(const NStmtAssign &assignStmt) const {
    if(assignStmt.rhs.size() != 0 && assignStmt.lhs.size() != assignStmt.rhs.size()) {
        cerr << "assignment mismatch: " << assignStmt.lhs.size() << " variables";
        cerr << " but " << assignStmt.rhs.size() << " values" << endl;
        exit(EXIT_FAILURE);
    }
}

void WeederDispatcher::dispatch(const NStmtBlock &blockStmt) const {
    for(const auto &stmt : blockStmt.stmts) {
        stmt->accept(*this);
    }
}

void WeederDispatcher::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}

void WeederDispatcher::dispatch(const NStmtDec &decStmt) const {
    decStmt.dec.accept(*this);
}

void WeederDispatcher::dispatch(const NStmtEmpty &emptyStmt) const {}
void WeederDispatcher::dispatch(const NStmtExp &expStmt) const {
    expStmt.exp.accept(*this);
}
void WeederDispatcher::dispatch(const NStmtFor &forStmt) const {}
void WeederDispatcher::dispatch(const NStmtIfElse &ifElseStmt) const {}
void WeederDispatcher::dispatch(const NStmtIncDec &incDecStmt) const {}
void WeederDispatcher::dispatch(const NStmtPrint &printStmt) const {}
void WeederDispatcher::dispatch(const NStmtReturn &returnStmt) const {}
void WeederDispatcher::dispatch(const NStmtSwitch &switchStmt) const {}