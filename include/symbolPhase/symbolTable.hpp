#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <unordered_map>
#include <string>
#include "symbolDefs.hpp"
#include "../ast/NAbstractAstNode.hpp"

#include <iostream>
using std::string;

struct Symbol {
    string name;
    SymbolKind kind;
    const NAbstractAstNode *defNode;

    Symbol(string id, SymbolKind symbolKind, const NAbstractAstNode* node) 
        : name{id}, kind{symbolKind}, defNode{node} {}

    ~Symbol() {
        std::cout << "Symbol destructor called" << std::endl;
        // delete defNode;
    }
};

class SymbolTable {
    public:
        SymbolTable *parent = nullptr;
        std::unordered_map<string, Symbol*> hashMap;

        SymbolTable() {
        }

        ~SymbolTable() {
            // delete parent;
        }

        SymbolTable *scopeSymbolTable() {
            SymbolTable *t = new SymbolTable();
            t->parent = this;
            return t;
        }

        Symbol *insertSymbol(string id, SymbolKind symbolKind, const NAbstractAstNode* node) {
            auto it = hashMap.find(id);
            if(it != hashMap.end()) {
                std::cerr << id << " was already declared in the current scope" << std::endl;
                exit(EXIT_FAILURE);
            }

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
            if(parent == nullptr) {
                return nullptr;
            }

            //check the parent scope
            return parent->getSymbol(name);
        }
};

#endif