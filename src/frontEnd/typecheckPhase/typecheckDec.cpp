#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;
using std::cerr;

//helpers

void assert(const NType &lhs, const NType &rhs) {
    if(lhs != rhs) {
        cerr << "Error: (line " << lhs.lineno << ")";
        cerr << rhs << " is not assignment compatible with " << lhs << " in variable declaration" << endl;
        exit(EXIT_FAILURE);
    }
}

void TypecheckDispatcher::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}

void TypecheckDispatcher::dispatch(const NDecFunc &funcDec) const {
    for(const auto &stmt : funcDec.stmts) {
        stmt->accept(*this);
    }
}

void TypecheckDispatcher::dispatch(const NDecType &typeDec) const {}

void TypecheckDispatcher::dispatch(const NDecVar &varDec) const {
    if(varDec.rhs.size() != 0 && varDec.lhs.size() != varDec.rhs.size()) {
        cerr << "assignment mismatch: " << varDec.lhs.size() << " variables";
        cerr << " but " << varDec.rhs.size() << " values" << endl;
        exit(EXIT_FAILURE);
    }

    if(varDec.rhs.size() == 0) {
        for(const auto &expId : varDec.lhs) {
            expId->type = varDec.type;
        }
    }

    for(const auto &exp : varDec.rhs) {
        exp->accept(*this);
    }

    auto itLhs = varDec.lhs.begin();
    auto itRhs = varDec.rhs.begin();
    while(itLhs != varDec.lhs.end() || itRhs != varDec.rhs.end()) {
        auto &expId = *itLhs++;
        auto &exp = *itRhs++;

        if(varDec.type == NType::inferType) {
            expId->type = exp->type;
        }
        else {
            assert(expId->type, exp->type);
        }
    }
}
