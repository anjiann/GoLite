#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NDeclaration &dec) {
    dec.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NDecFunc &funcDec) {
    funcDecs.push_back(&funcDec);
    currSymTable->hashMap.insert({funcDec.id, {SymbolKind::SFunction, &funcDec}});
    cout << getTabs() << getIdSymKindStr(funcDec.id) << "=" << getType(funcDec.params);
}

void SymbolHelper::dispatch(const NDecType &typeDec) {
    // cout << "type " << typeDec.id;
    // const NAbstractAstNode *node = &typeDec.type;
    // currSymTable->hashMap[typeDec.id] = std::make_pair(SymbolKind::SType, node);
    // cout << " ";
    // typeDec.type.accept(*symbolDispatcher);
    // cout << endl;
}

void SymbolHelper::dispatch(const NDecVar &varDec) {
}