#include <iostream>
#include <algorithm>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::cerr;
using std::endl;

void SymbolHelper::dispatch(const NType &type) {
    type.accept(*symbolDispatcher);
}
void SymbolHelper::dispatch(const NTypeArray &arrayType) {
    if(symbol_mode) { cout << "[" << arrayType.size << "]"; }
    arrayType.type->accept(*symbolDispatcher);
    // arrayType.id += arrayType.type->id;
}

void SymbolHelper::dispatch(const NTypeIdentifier &idType) {
    if(idType == NType::inferType) {
        if(symbol_mode) { cout << NType::inferType; }
        return;
    }
    
    std::shared_ptr<Symbol> symbol = currSymTable->getSymbol(idType.id);
    //check that the id is in the symbol table
    if(symbol == nullptr) {
       cerr << "Error: (line " << idType.lineno << ") type " << idType.id << " is not declared";
       exit(EXIT_FAILURE);
    }

    std::shared_ptr<TypeSymbol> typeSym = std::dynamic_pointer_cast<TypeSymbol>(symbol);   
    if(!typeSym) {
        cerr << "Error: (line " << idType.lineno << ") "<< idType.id << " is not a type";
        exit(EXIT_FAILURE);
    } 

    if(symbol_mode) { cout << idType.id; }
    if(!(idType.isArrayId || isBaseType(idType))) {
        if(symbol_mode) { cout << " -> "; }
        typeSym->type.accept(*symbolDispatcher);
    }
}