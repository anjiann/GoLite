#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>

#include "NExpression.hpp"
#include "NExpIdentifier.hpp"

using std::string;

class NExpFuncCall : NExpression {    
    public:
        const Nexpression &expId;
        NExpressionList &exps;
        
        NExpFuncCall(const Nexpression &expId, const NExpressionList &exps) : expId{expId}, exps{exps} {}
};

#endif /* !NEXPFUNCCALL_H */