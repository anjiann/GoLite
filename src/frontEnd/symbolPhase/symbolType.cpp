#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::cerr;
using std::endl;

void SymbolHelper::dispatch(const NType &type) {
    cout << type.id;
}
void SymbolHelper::dispatch(const NTypeArray &arrayType) {
    cout << "[" << arrayType.size << "]";
    arrayType.type.accept(*symbolDispatcher);
    
}

void SymbolHelper::dispatch(const NTypeIdentifier &idType) {
    const Symbol *symbol = currSymTable->getSymbol(idType.id);
    //check that the id is in the symbol table
    if(symbol == nullptr) {
       cerr << "Error: (line " << idType.lineno << ") type " << idType.id << " is not declared";
       exit(EXIT_FAILURE);
    }
    //don't recurse if id is a base type
    const TypeSymbol *typeSym = dynamic_cast<const TypeSymbol*>(symbol);
    cout << " -> ";
}