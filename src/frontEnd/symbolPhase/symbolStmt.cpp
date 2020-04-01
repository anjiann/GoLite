#include "symbolPhase/symbolHelper.hpp"

using std::cerr;
using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NStatement &stmt) {
    stmt.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NStmtAssign &assignStmt) {
    for(const auto &exp : assignStmt.lhs) {
        exp->accept(*symbolDispatcher);
    }

    for(const auto &exp : assignStmt.rhs) {
        exp->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NStmtBlock &blockStmt) {
    for(const auto &stmt : blockStmt.stmts) {
        stmt->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NStmtBreakContinue &breakContinueStmt) {}
void SymbolHelper::dispatch(const NStmtDec &decStmt) { 
    decStmt.dec->accept(*symbolDispatcher); 
}

void SymbolHelper::dispatch(const NStmtEmpty &emptyStmt) {}

void SymbolHelper::dispatch(const NStmtExp &expStmt) {
    expStmt.exp->accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NStmtFor &forStmt) {
    forStmt.initStmt.accept(*symbolDispatcher);
    forStmt.exp.accept(*symbolDispatcher);
    forStmt.updateStmt.accept(*symbolDispatcher);
    for(const auto &stmt : forStmt.stmts) {
        stmt->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NStmtIfElse &ifElseStmt) {
    ifElseStmt.condition.accept(*symbolDispatcher);
    for(const auto &stmt : ifElseStmt.body) {
        stmt->accept(*symbolDispatcher);
    }
    for(const auto &stmt : ifElseStmt.elseBody) {
        stmt->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NStmtIncDec &incDecStmt) {
    incDecStmt.exp.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NStmtPrint &printStmt) {
    for(const auto &exp : printStmt.exps) {
        exp->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NStmtReturn &returnStmt) {
    returnStmt.exp.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NStmtSwitch &switchStmt) {
    switchStmt.condition.accept(*symbolDispatcher);
    for(const auto &caseClause : switchStmt.caseClauses) {
        caseClause->accept(*symbolDispatcher);
    }
}