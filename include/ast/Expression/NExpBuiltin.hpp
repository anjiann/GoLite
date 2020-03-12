#ifndef NEXPBUILTIN_H
#define NEXPBUILTIN_H

#include <string>

#include "NExpression.hpp"

using std::string;

enum NExpBuiltinKind {
    lenExp,
    capExp,
    funcExp
    // append, //not required in golite_mini
};

class NExpBuiltin : NExpression {    
    public:
        NExpBuiltinKind name;
        const NExpression &exp;
        NExpBuiltin(const NExpression &exp, NExpBuiltinKind name) : exp{exp}, name{name} {}
};



#endif /* !NEXPBUILTIN_H */