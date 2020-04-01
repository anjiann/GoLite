#ifndef SYMBOLTYPE_HPP
#define SYMBOLTYPE_HPP

#include <iostream>
#include <string>
#include "symbol.hpp"
#include "../../ast/Type/NType.hpp"

using std::string;

class TypeSymbol : public Symbol {
    public: 
        string name;
        const NType &type;

        TypeSymbol(string name, const NType &type) : name{name}, type{type} {}
        TypeSymbol(const TypeSymbol &src) : name{src.name}, type{src.type} {}

        void print(std::ostream &os) const {
            std::cout << name << " [type]";
        }
};



#endif