#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>

#include "NExpression.hpp"
#include "NExpIdentifier.hpp"

using std::string;

class NExpFuncCall : public NExpression {    
    public:
        string id;
        const NExpressionList &exps;
        
        NExpFuncCall(string id, const NExpressionList &exps) : id{id}, exps{exps} {}
};

#endif /* !NEXPFUNCCALL_H */