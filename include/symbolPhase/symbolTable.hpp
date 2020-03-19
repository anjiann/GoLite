#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <unordered_map>
#include <string>
#include "symbolDefs.hpp"
#include "../ast/NAbstractAstNode.hpp"

#include <iostream>
using std::string;

class Symbol {
    public:
        string name;
        SymbolKind kind;
        const NAbstractAstNode *defNode;

        Symbol(string id, SymbolKind symbolKind, const NAbstractAstNode* node) 
            : name{id}, kind{symbolKind}, defNode{node} {}

        ~Symbol() {
            // delete defNode;
        }
};

class SymbolTable {
    public:
        const SymbolTable *parent = NULL;
        std::unordered_map<string, Symbol*> hashMap {};

        SymbolTable() {}
        SymbolTable(const SymbolTable *parent, const SymbolTable *child) : parent{parent} {}

        ~SymbolTable() {
            // delete parent;
        }

        SymbolTable *scopeSymbolTable() {
            SymbolTable *t = new SymbolTable();
            t->parent = this;
            return t;
        }

        Symbol *insertSymbol(string id, SymbolKind symbolKind, const NAbstractAstNode* node) {
            std::cout << "inserting symbol " << id << std::endl;
            auto it = hashMap.find(id);
            std::cout << "iterator found" << std::endl;
            if(it != hashMap.end()) {
                std::cerr << id << " was already declared in the current scope" << std::endl;
                exit(EXIT_FAILURE);
            }

            std::cout << "before symbol created\n";
            Symbol *symbol = new Symbol(id, symbolKind, node);
            hashMap.insert(std::make_pair(id, symbol));
            return symbol;
        }

        Symbol *getSymbol(string name) const {
            //check current scope
            for(auto it = hashMap.begin(); it != hashMap.end(); it++) {
                if(it->first == name) {
                    return it->second;
                }
            }

            //check for existence of a parent scope
            if(parent == NULL) {
                return NULL;
            }

            //check the parent scope
            return parent->getSymbol(name);
        }
};

#endif