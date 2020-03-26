#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;

void TypecheckDispatcher::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}
void TypecheckDispatcher::dispatch(const NDecFunc &funcDec) const {}
void TypecheckDispatcher::dispatch(const NDecType &typeDec) const {}
void TypecheckDispatcher::dispatch(const NDecVar &varDec) const {
    // //declared but not initialized
    // if(varDec.rhs.size() == 0) {

    // }
    // else {
    //     if(varDec.lhs.size() != varDec.rhs.size()) {
    //         cerr << "assignment mismatch: " << varDec.lhs.size() << " variables";
    //         cerr << " but " << varDec.rhs.size() << " values" << endl;
    //         exit(EXIT_FAILURE);
    //     }


    // }
}
