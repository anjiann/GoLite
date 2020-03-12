#ifndef NEXPUNARY_H
#define NEXPUNARY_H

#include <string>
#include "NExpression.hpp"
#include "enums.hpp"

using std::string;

class NExpUnary : NExpression {    
    public:
        const NExpression &exp;
        NExpOp op;

        NExpUnary(const NExpression &exp, NExpOp op) : exp{exp}, op{op} {}
};


#endif /* !NEXPUNARY_H */