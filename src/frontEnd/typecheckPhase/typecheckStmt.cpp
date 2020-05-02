#include <iostream>
#include <string>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;
using std::cerr;
using std::to_string;

//HELPER

void assert(const NType &type1, const NType &type2, const string &errMsg) {
    if(type1 != type2) {
        cerr << errMsg << endl;
        exit(EXIT_FAILURE);
    }
}

//DISPATCHER

void TypecheckDispatcher::dispatch(const NStatement &stmt) const {
    stmt.accept(*this);
}

void TypecheckDispatcher::dispatch(const NStmtAssign &assignStmt) const {
    for(const auto &exp : assignStmt.rhs) {
        exp->accept(*this);
    }

    auto itLhs = assignStmt.lhs.begin();
    auto itRhs = assignStmt.rhs.begin();
    while(itLhs != assignStmt.lhs.end() || itRhs != assignStmt.rhs.end()) {
        auto &expId = *itLhs++;
        auto &exp = *itRhs++;

        const NType &lhs = expId->type;
        const NType &rhs = exp->type;
        string errMsg = "Error: (line " + to_string(lhs.lineno) + ")" + rhs + " is not assignment compatible with " + lhs + " in assign statement";
        assert(lhs, rhs, errMsg);
    }
}

void TypecheckDispatcher::dispatch(const NStmtBlock &blockStmt) const {
    for(const auto &stmt : blockStmt.stmts) {
        stmt->accept(*this);
    }
}

void TypecheckDispatcher::dispatch(const NStmtBreakContinue &breakContinueStmt) const {}

void TypecheckDispatcher::dispatch(const NStmtDec &decStmt) const {
    decStmt.dec->accept(*this);
}

void TypecheckDispatcher::dispatch(const NStmtEmpty &emptyStmt) const {}

void TypecheckDispatcher::dispatch(const NStmtExp &expStmt) const {
    expStmt.exp->accept(*this);
}

void TypecheckDispatcher::dispatch(const NStmtFor &forStmt) const {
    const NExpression &exp = forStmt.exp;
    exp.accept(*this);
    string errMsg =  "Error: (line " + to_string(exp.lineno) + ")" + " incompatible type in loop condition [received " + exp.type + "expected bool]";
    assert(exp.type, NType::boolType, errMsg);

    for(const auto &stmt : forStmt.stmts) {
        stmt->accept(*this);
    }
}

void TypecheckDispatcher::dispatch(const NStmtIfElse &ifElseStmt) const {
    const NExpression &exp = ifElseStmt.condition;
    exp.accept(*this);
    string errMsg = "Error: (line " + to_string(exp.lineno) + ")" + " incompatible type in if condition [received " + exp.type + "expected bool]";
    assert(exp.type, NType::boolType, errMsg);
    for(const auto &stmt : ifElseStmt.body) {
        stmt->accept(*this);
    }
    for(const auto &stmt : ifElseStmt.elseBody) {
        stmt->accept(*this);
    }
}

void TypecheckDispatcher::dispatch(const NStmtIncDec &incDecStmt) const {
    const NExpression &exp = incDecStmt.exp;
    exp.accept(*this);
    if(exp.type != NType::intType && exp.type != NType::runeType && exp.type != NType::stringType) {
        string errMsg = "Error: (line " + to_string(exp.lineno) + ")" + " incompatible type in increment [received " + exp.type + "expected numeric (int, rune, float64)]";
        cerr << errMsg << endl;
        exit(EXIT_FAILURE);
    }
}

void TypecheckDispatcher::dispatch(const NStmtPrint &printStmt) const {
    for(const auto &exp : printStmt.exps) {
        exp->accept(*this);
        if(!isBaseType(exp->type)) {
            string errMsg = "Error: (line " + to_string(exp->lineno) + ")" + " print expects base types [received {" + exp->type + "}, expected base types (int, float64, rune, string, bool)]";
            cerr << errMsg << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void TypecheckDispatcher::dispatch(const NStmtReturn &returnStmt) const {
    
}

void TypecheckDispatcher::dispatch(const NStmtSwitch &switchStmt) const {
    const NExpression &switchExp = switchStmt.condition;
    switchExp.accept(*this);
    for(const auto &caseClause : switchStmt.caseClauses) {
        caseClause->accept(*this);
        for(const auto &exp : caseClause->switchCase.explist) {
            string errMsg = "Error: (line " + to_string(exp->lineno) + ")" + " switch statement expresion type is incompatible with case type [" + exp->type + " != " + switchExp.type + "]";
            assert(switchExp.type, exp->type, errMsg);
        }
    }
}