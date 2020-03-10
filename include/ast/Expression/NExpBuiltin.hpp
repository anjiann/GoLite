#ifndef NEXPBUILTIN_H
#define NEXPBUILTIN_H

#include <string>

#include "NExpression.hpp"

using std::string;

class NExpBuiltin : NExpression {    
    public:
        NExpBuiltin name;
        const NExpression &exp;
        NExpBuiltin(const NExpression &exp, NExpBuiltin name) : exp{exp}, name{name} {}
};

enum NExpBuiltin {
    lenExp,
    capExp,
    funcExp
    // append, //not required in golite_mini
}

#endif /* !NEXPBUILTIN_H */