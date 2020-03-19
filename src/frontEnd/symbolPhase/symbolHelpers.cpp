#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

//if id exists in symTable return id[<SymbolKind>], else error and exit
string SymbolHelper::getIdSymKindStr(string id) {
    Symbol *symbol = currSymTable->getSymbol(id);
    if(symbol == NULL) {
        std::cerr << "invalid argument: " << id << "was not found in symbol table" << endl;
        exit(EXIT_FAILURE);
    }

    string s = id + "[" + getSymKindName(symbol->kind) + "]";

    return s;
}

string SymbolHelper::getSymKindName(SymbolKind symbolKind) {
    switch(symbolKind) {
        case SymbolKind::SFunction: return "function";
        case SymbolKind::SFormal: break;
        case SymbolKind::SLocal: break;
        case SymbolKind::SType: return "type";
        case SymbolKind::SConstant: return "constant";
    }
}