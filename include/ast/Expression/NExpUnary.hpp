#ifndef NEXPUNARY_H
#define NEXPUNARY_H

#include <string>
#include "NExpression.h"

using std::string;

class NExpUnary : NExpression {    
    public:
        const NExpression &exp;
        NExpUnaryOp op;

        NExpUnary(const NExpression &exp, NExpUnaryOp op) : exp{exp}, op{op};
};

enum NExpUnaryOp {	
    notExp, // ! 
    posExp, // +
	negExp, // -
    xorExp, // ^
    parenExp, // (e)
}

#endif /* !NEXPUNARY_H */