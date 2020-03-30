#include <iostream>
#include "weederPhase/weederDispatcher.hpp"

using std::cerr;
using std::endl;

void WeederDispatcher::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}
void WeederDispatcher::dispatch(const NDecFunc &funcDec) const {
    for(const auto &stmt : funcDec.stmts) {
        stmt->accept(*this);
    }
}
void WeederDispatcher::dispatch(const NDecType &typeDec) const {}
void WeederDispatcher::dispatch(const NDecVar &varDec) const {
    if(varDec.rhs.size() != 0 && varDec.lhs.size() != varDec.rhs.size()) {
        cerr << "assignment mismatch: " << varDec.lhs.size() << " variables";
        cerr << " but " << varDec.rhs.size() << " values" << endl;
        exit(EXIT_FAILURE);
    }
} 