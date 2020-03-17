#include <iostream>
#include <string>
#include "prettyPrintPhase/prettyPrintPhase.hpp"

using std::cout;
using std::endl;
using std::string;

void PrettyPrintPhase::dispatch(const NExpression &exp) const {
    exp.accept(*this);
}

void PrettyPrintPhase::dispatch(const NExpBinary &binaryExp) const {
    cout << "(";
    binaryExp.lhs.accept(*this);
    cout << " ";
    binaryExp.rhs.accept(*this);
    cout << ")" << endl;
}

void PrettyPrintPhase::dispatch(const NExpBuiltin &unaryExp) const {
}
void PrettyPrintPhase::dispatch(const NExpFuncCall &funcCallExp) const {
    funcCallExp.expId.accept(*this);
    cout << "(";
    string separator;
    for(const auto &param : funcCallExp.params) {
        cout << separator;
        param->accept(*this);
        separator = " ,";
    }

    cout << ")" << endl;
}
void PrettyPrintPhase::dispatch(const NExpIdentifier &idExp) const {}
void PrettyPrintPhase::dispatch(const NExpIndexer &indexerExp) const {}
void PrettyPrintPhase::dispatch(const NExpLiteral &literalExp) const {}
void PrettyPrintPhase::dispatch(const NExpUnary &unaryExp) const {}
void PrettyPrintPhase::dispatch(const NExpCaseClause &caseClauseExp) const {}
void PrettyPrintPhase::dispatch(const NExpSwitchCase &switchCaseExp) const {}