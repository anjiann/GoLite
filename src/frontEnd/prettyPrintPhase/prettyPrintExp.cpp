#include <iostream>
#include <string>
#include "prettyPrintPhase/prettyDispatcher.hpp"

using std::cout;
using std::endl;
using std::string;

void PrettyDispatcher::dispatch(const NExpression &exp) const {
    exp.accept(*this);
}

void PrettyDispatcher::dispatch(const NExpBinary &binaryExp) const {
    cout << "(";
    binaryExp.lhs.accept(*this);
    cout << " ";
    binaryExp.rhs.accept(*this);
    cout << ")" << endl;
}

void PrettyDispatcher::dispatch(const NExpBuiltin &unaryExp) const {
}
void PrettyDispatcher::dispatch(const NExpFuncCall &funcCallExp) const {
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
void PrettyDispatcher::dispatch(const NExpIdentifier &idExp) const {}
void PrettyDispatcher::dispatch(const NExpIndexer &indexerExp) const {}
void PrettyDispatcher::dispatch(const NExpLiteral &literalExp) const {}
void PrettyDispatcher::dispatch(const NExpUnary &unaryExp) const {}
void PrettyDispatcher::dispatch(const NExpCaseClause &caseClauseExp) const {}
void PrettyDispatcher::dispatch(const NExpSwitchCase &switchCaseExp) const {}