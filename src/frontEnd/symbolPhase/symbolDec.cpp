#include <iostream>
#include "symbolPhase/symbolPhase.hpp"

using std::cout;
using std::endl;

void SymbolPhase::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}

void SymbolPhase::dispatch(const NDecFunc &funcDec) const {
    funcDecs.push_back(&funcDec);
    // currSymTable->hashMap.insert({funcDec.id, });
}

void SymbolPhase::dispatch(const NDecType &typeDec) const {
    cout << "type " << typeDec.id;
    const NAbstractAstNode *node = &typeDec.type;
    currSymTable->hashMap[typeDec.id] = std::make_pair(SymbolKind::SType, node);
    cout << " ";
    typeDec.type.accept(*this);
    cout << endl;
}

void SymbolPhase::dispatch(const NDecVar &varDec) const {
}