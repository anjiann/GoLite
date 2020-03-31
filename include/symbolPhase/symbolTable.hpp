#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <unordered_map>
#include <string>
#include <memory>
#include "symbolDefs.hpp"
#include "symbols/symbol.hpp"
#include "../ast/NAbstractAstNode.hpp"

#include <iostream>
using std::string;

class SymbolTable {
    public:
        SymbolTable *parent;
        std::unordered_map<string, std::shared_ptr<Symbol>> hashMap;

        SymbolTable() {}

        std::shared_ptr<Symbol> insertSymbol(const string &name, std::shared_ptr<Symbol> symbol) {
            auto it = hashMap.find(name);
            if(it != hashMap.end()) {
                std::cerr << name << " was already declared in the current scope" << std::endl;
                exit(EXIT_FAILURE);
            }

            hashMap.insert(std::make_pair(name, symbol));
            return symbol;
        }

        std::shared_ptr<Symbol> getSymbol(const string &name) const {
            //check current scope
            for(auto it = hashMap.begin(); it != hashMap.end(); it++) {
                if(it->first == name) {
                    return std::move(it->second);
                }
            }

            //check for existence of a parent scope
            if(!parent) {
                return std::shared_ptr<Symbol>(nullptr);
            }

            //check the parent scope
            return parent->getSymbol(name);
        }
};

#endif