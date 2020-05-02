#include <iostream>
#include "weederPhase/weederDispatcher.hpp"

using std::cerr;
using std::endl;

void WeederDispatcher::dispatch(const NStatement &stmt) const {
    stmt.accept(*this);
}

void WeederDispatcher::dispatch(const NStmtAssign &assignStmt) const {
    if(assignStmt.rhs.size() != 0 && assignStmt.lhs.size() != assignStmt.rhs.size()) {
        cerr << "Error: (line " << assignStmt.lineno << ") assignment";
        cerr << "lhs(" << assignStmt.lhs.size() << ") != rhs(" << assignStmt.rhs.size() << ")" << endl;
        exit(EXIT_FAILURE);
    }
}

void WeederDispatcher::dispatch(const NStmtBlock &blockStmt) const {
    for(const auto &stmt : blockStmt.stmts) {
        stmt->accept(*this);
    }
}

void WeederDispatcher::dispatch(const NStmtBreakContinue &breakContinueStmt) const {
    
}

void WeederDispatcher::dispatch(const NStmtDec &decStmt) const {
    decStmt.dec->accept(*this);
}

void WeederDispatcher::dispatch(const NStmtEmpty &emptyStmt) const {}
void WeederDispatcher::dispatch(const NStmtExp &expStmt) const {
    std::shared_ptr<NExpFunc> funcCall = std::dynamic_pointer_cast<NExpFunc>(expStmt.exp);   
    if(!funcCall) {
        cerr << "Error: expression statement needs to be a function call" << endl;
        exit(EXIT_FAILURE);
    } 
    
    expStmt.exp->accept(*this);
}
void WeederDispatcher::dispatch(const NStmtFor &forStmt) const {}
void WeederDispatcher::dispatch(const NStmtIfElse &ifElseStmt) const {}
void WeederDispatcher::dispatch(const NStmtIncDec &incDecStmt) const {}
void WeederDispatcher::dispatch(const NStmtPrint &printStmt) const {}
void WeederDispatcher::dispatch(const NStmtReturn &returnStmt) const {}
void WeederDispatcher::dispatch(const NStmtSwitch &switchStmt) const {
    int numDefaults = 0;
    for(const auto &caseClause : switchStmt.caseClauses) {
        if(caseClause->switchCase.explist.size() == 0) {
            numDefaults++;
        }
        if(numDefaults > 1) {
            cerr << "Error: more than one default case found in switch " << endl;
            exit(EXIT_FAILURE);
        }
    }
}