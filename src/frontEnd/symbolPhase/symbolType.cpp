#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;

void SymbolHelper::dispatch(const NType &type) {
    cout << type.id;
}
void SymbolHelper::dispatch(const NTypeArray &arrayType) {
    cout << "[" << arrayType.size << "]";
    arrayType.type.accept(*symbolDispatcher);
    
}

void SymbolHelper::dispatch(const NTypeIdentifier &idType) {
    cout << idType.id;
    Symbol *symbol = currSymTable->getSymbol(idType.id);
    //check that the id is in the symbol table and that id is not a base type
    if(symbol != nullptr && symbol->defNode != nullptr) {
        cout << " -> ";
        symbol->defNode->accept(*symbolDispatcher);
    }
}