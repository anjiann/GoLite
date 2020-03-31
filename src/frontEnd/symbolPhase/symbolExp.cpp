#include "symbolPhase/symbolHelper.hpp"

using std::cerr;
using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NExpression &exp) {
    exp.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NExpArrIdentifier &arrIdExp) {
    for(const auto &sizeExp : arrIdExp.sizeExps) {
        sizeExp->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NExpBinary &binaryExp) {
    binaryExp.lhs.accept(*symbolDispatcher);
    binaryExp.rhs.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NExpBuiltin &builtinExp) {
    builtinExp.exp.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NExpFunc &funcExp) {
    funcExp.expId.accept(*symbolDispatcher);
    for(const auto &arg : funcExp.args) {
        arg->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NExpIdentifier &idExp) {
    auto sym = currSymTable->getSymbol(idExp.name);
    if(sym == nullptr) {
        cerr << "Error: (line " << idExp.lineno << ") "<< idExp.name << "is not declared" << endl;
        exit(EXIT_FAILURE);
    }
    idExp.symbol = sym;
}

void SymbolHelper::dispatch(const NExpIndexer &indexerExp) {
    indexerExp.exp.accept(*symbolDispatcher);
    indexerExp.index.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NExpLiteral &literalExp) {}

void SymbolHelper::dispatch(const NExpUnary &unaryExp) {
    unaryExp.exp.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NExpCaseClause &caseClauseExp) {
    caseClauseExp.switchCase.accept(*symbolDispatcher);
    for(const auto &stmt :caseClauseExp.stmts) {
        stmt->accept(*symbolDispatcher);
    }
}

void SymbolHelper::dispatch(const NExpSwitchCase &switchCaseExp) {
    for(const auto &exp : switchCaseExp.explist) {
        exp->accept(*symbolDispatcher);
    }
}