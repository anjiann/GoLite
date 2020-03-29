#include "symbolPhase/symbolHelper.hpp"

using std::cerr;
using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NStatement &stmt) {}
void SymbolHelper::dispatch(const NStmtAssign &assignStmt) {
    for(const auto &expId : assignStmt.lhs) {
        Symbol *sym = currSymTable->getSymbol(expId->name);
        if(sym == nullptr) {
            cerr << "Error: (line " << expId->lineno << ") "<< expId->name << "is not declared" << endl;
            exit(EXIT_FAILURE);
        }
        expId->symbol = *sym;
    }
}

void SymbolHelper::dispatch(const NStmtBlock &blockStmt) {}
void SymbolHelper::dispatch(const NStmtBreakContinue &breakContinueStmt) {}
void SymbolHelper::dispatch(const NStmtDec &decStmt) { 
    decStmt.dec.accept(*symbolDispatcher); 
}
void SymbolHelper::dispatch(const NStmtEmpty &emptyStmt) {}
void SymbolHelper::dispatch(const NStmtExp &expstmt) {}
void SymbolHelper::dispatch(const NStmtFor &forStmt) {}
void SymbolHelper::dispatch(const NStmtIfElse &ifElseStmt) {}
void SymbolHelper::dispatch(const NStmtIncDec &incDecStmt) {}
void SymbolHelper::dispatch(const NStmtPrint &printStmt) {}
void SymbolHelper::dispatch(const NStmtReturn &returnStmt) {}
void SymbolHelper::dispatch(const NStmtSwitch &switchStmt) {}