#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <unordered_map>
#include <string>
#include "symbolDefs.hpp"
#include "symbols/symbol.hpp"
#include "../ast/NAbstractAstNode.hpp"

#include <iostream>
using std::string;

class SymbolTable {
    public:
        SymbolTable *parent = nullptr;
        std::unordered_map<string, const Symbol*> hashMap;

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

        const Symbol *insertSymbol(const string &name, const Symbol *symbol) {
            auto it = hashMap.find(name);
            if(it != hashMap.end()) {
                std::cerr << name << " was already declared in the current scope" << std::endl;
                exit(EXIT_FAILURE);
            }

            hashMap.insert(std::make_pair(name, symbol));
            return getSymbol(name);
        }

        const Symbol *getSymbol(const string &name) const {
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