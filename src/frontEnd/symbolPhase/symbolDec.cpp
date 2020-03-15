#include <iostream>
#include "symbolPhase/symbolPhase.hpp"

using std::cout;
using std::endl;

void SymbolPhase::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}
void SymbolPhase::dispatch(const NDecFunc &funcDec) const {
    funcDecs.push_back(&funcDec);
    // currSymTable->hashMap.insert({funcDec.id, })
}
void SymbolPhase::dispatch(const NDecType &typeDec) const {}
void SymbolPhase::dispatch(const NDecVar &varDec) const {}