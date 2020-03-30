#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <iostream>
#include <string>

using std::string;

class Symbol {
    public:
        virtual void print(std::ostream &os) const = 0;
};

inline std::ostream &operator<<(std::ostream &os, const Symbol &symbol) {
    symbol.print(os);

    return os;
}

#endif