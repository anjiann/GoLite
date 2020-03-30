#ifndef LOCALSYMBOL_HPP
#define LOCALSYMBOL_HPP

#include <string>
#include "symbol.hpp"

using std::string;

class LocalSymbol : public Symbol {
    public: 
        string name;
        const NExpIdentifier &expId;

        LocalSymbol(string name, const NExpIdentifier &expId) : name{name}, expId{expId} {}

        void print(std::ostream &os) const {
            std::cout << name << " [variable]";
        }
};

#endif