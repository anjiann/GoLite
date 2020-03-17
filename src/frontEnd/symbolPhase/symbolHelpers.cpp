#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

string SymbolHelper::getTabs() {
    string s;
    for(int i = 0; i < numTabs; i++) {
        s += "\t";
    }
    return s;
}

//if id exists in symTable return id[<SymbolKind>], else error and exit
string SymbolHelper::getIdSymKindStr(string id) {
    auto it = currSymTable->hashMap.find(id);
    if(it == currSymTable->hashMap.end()) {
        std::cerr << "invalid argument: " << id << "was not found in symbol table" << endl;
        exit(EXIT_FAILURE);
    }

    string s = id + "[" + getSymKind(it->second.first) + "]";

    return s;
}

string SymbolHelper::getSymKind(SymbolKind symbolKind) {
    switch(symbolKind) {
        case SymbolKind::SFunction: return "function";
        case SymbolKind::SFormal: return "formal";
        case SymbolKind::SLocal: break;
        case SymbolKind::SType: break;
        case SymbolKind::SConstant: break;
    }
}

string SymbolHelper::getType(const NDecVarList &params) {
    string s = "(";
    string separator = "";
    for(const auto &param : params) {
        s += separator;
        s += getType(param->type);
        separator = " ,";
    }

    return s;
}

string SymbolHelper::getType(const NType &params) {

}

