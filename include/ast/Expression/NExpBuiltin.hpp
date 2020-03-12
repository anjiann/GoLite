#ifndef NEXPBUILTIN_H
#define NEXPBUILTIN_H

#include <string>

#include "NExpression.hpp"
#include "enums.hpp"

using std::string;

class NExpBuiltin : public NExpression {    
    public:
        NExpBuiltinKind name;
        const NExpression &exp;
        NExpBuiltin(const NExpression &exp, NExpBuiltinKind name) : exp{exp}, name{name} {}
};



#endif /* !NEXPBUILTIN_H */