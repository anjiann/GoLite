#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <iostream>
#include <string>
#include "../ast/NAbstractAstNode.hpp"
#include "symbolDefs.hpp"

using std::string;

struct Symbol {
    string name;
    SymbolKind kind;
    const NAbstractAstNode *defNode;

    Symbol() {}

    Symbol(string id, SymbolKind symbolKind, const NAbstractAstNode* node) 
        : name{id}, kind{symbolKind}, defNode{node} {}

    ~Symbol() {
        std::cout << "Symbol destructor called" << std::endl;
        // delete defNode;
    }
};

#endif