#include <iostream>
#include "symbolPhase/symbolPhaseHelper.hpp"

using std::cout;
using std::endl;

void SymbolPhaseHelper::dispatch(const NDeclaration &dec) {
    // dec.accept(*this);
}

void SymbolPhaseHelper::dispatch(const NDecFunc &funcDec) {
    // funcDecs.push_back(&funcDec);
    // currSymTable->hashMap.insert({funcDec.id, });
}

void SymbolPhaseHelper::dispatch(const NDecType &typeDec) {
    // cout << "type " << typeDec.id;
    // const NAbstractAstNode *node = &typeDec.type;
    // currSymTable->hashMap[typeDec.id] = std::make_pair(SymbolKind::SType, node);
    // cout << " ";
    // typeDec.type.accept(*this);
    // cout << endl;
}

void SymbolPhaseHelper::dispatch(const NDecVar &varDec) {
}