#ifndef FUNCSYMBOL_HPP
#define FUNCSYMBOL_HPP

#include <string>
#include "symbol.hpp"

using std::string;

class FuncSymbol : public Symbol {
    public:
        string name;
        const NDecFunc &funcDec;

        FuncSymbol(string name, const NDecFunc &funcDec) : name{name}, funcDec{funcDec} {}

        void print(std::ostream &os) const {
            std::cout << name << " [function]";
        }
};

#endif