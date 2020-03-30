#ifndef CONSTANTSYMBOL_HPP
#define CONSTANTSYMBOL_HPP

#include <string>
#include "symbol.hpp"
#include "../../ast/Type/NType.hpp"

using std::string;

class ConstantSymbol : public Symbol {
    public: 
        string name;
        const NType &type;

        ConstantSymbol(string name, const NType &type) : name{name}, type{type} {}

        void print(std::ostream &os) const {
            std::cout << name << " [constant]";
        }
};

#endif