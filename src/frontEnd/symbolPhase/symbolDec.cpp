#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NDeclaration &dec) {
    // dec.accept(*this);
}

void SymbolHelper::dispatch(const NDecFunc &funcDec) {
    // funcDecs.push_back(&funcDec);
    // currSymTable->hashMap.insert({funcDec.id, });
}

void SymbolHelper::dispatch(const NDecType &typeDec) {
    // cout << "type " << typeDec.id;
    // const NAbstractAstNode *node = &typeDec.type;
    // currSymTable->hashMap[typeDec.id] = std::make_pair(SymbolKind::SType, node);
    // cout << " ";
    // typeDec.type.accept(*this);
    // cout << endl;
}

void SymbolHelper::dispatch(const NDecVar &varDec) {
}