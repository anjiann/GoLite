#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;
using std::cerr;

void TypecheckDispatcher::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}
void TypecheckDispatcher::dispatch(const NDecFunc &funcDec) const {}
void TypecheckDispatcher::dispatch(const NDecType &typeDec) const {}
void TypecheckDispatcher::dispatch(const NDecVar &varDec) const {
    if(varDec.rhs.size() != 0 && varDec.lhs.size() != varDec.rhs.size()) {
        cerr << "assignment mismatch: " << varDec.lhs.size() << " variables";
        cerr << " but " << varDec.rhs.size() << " values" << endl;
        exit(EXIT_FAILURE);
    }

    for(const auto &exp : varDec.rhs) {
        exp->accept(*typecheckDispatcher);
    }

    for(const auto &expId : varDec.lhs) {
        if(expId.type == NType.inferType) {

        }
    }
}
