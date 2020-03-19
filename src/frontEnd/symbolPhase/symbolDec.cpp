#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::dispatch(const NDeclaration &dec) {
    dec.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NDecFunc &funcDec) {
    funcDecs.push_back(&funcDec);
    currSymTable->insertSymbol(funcDec.id, SymbolKind::SFunction, &funcDec);

    //print to console
    cout << getTabs() << getIdSymKindStr(funcDec.id) << " = (";
    string separator = "";
    for(const auto &param : funcDec.params) {
        cout << separator;

        param->type.accept(*symbolDispatcher);
        separator = ", ";
    }
    cout << ") -> ";
    funcDec.type.accept(*symbolDispatcher);
    cout << endl;

    cout << getTabs() << "{" << endl;
    for(const auto &stmt : funcDec.stmts) {
        stmt->accept(*symbolDispatcher);
        cout << endl;
    }
    cout << getTabs() << "}" << endl;
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