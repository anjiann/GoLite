#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>

#include "NExpression.hpp"
#include "NExpIdentifier.hpp"
#include "typedefs.h"

using std::string;

class NExpFuncCall : NExpression {    
    public:
        const Nexpression &expId;
        NExpressionList &exps;
        
        NExpFuncCall(const Nexpression &expId, const vector<Expression*> &exps) : expId{expId}, exps{exps} {}
};

#endif /* !NEXPFUNCCALL_H */