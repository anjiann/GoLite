#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <map>
#include <string>
#include "symbolDefs.hpp"
#include "../ast/NAbstractAstNode.hpp"

using std::map;
using std::string;

class SymbolTable {
    public:
        const SymbolTable *parent = NULL;
        map<string, std::pair<SymbolKind, const NAbstractAstNode*>> hashMap {};

        SymbolTable() {}
        SymbolTable(const SymbolTable *parent, const SymbolTable *child) : parent{parent} {}

        ~SymbolTable() {
            delete parent;
        }
};

#endif