#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>

#include "NExpression.hpp"
#include "NExpIdentifier.hpp"
#include "typedefs.h"

using std::string;

class NExpFuncCall : NExpression {    
    public:
        string id;
        NExpressionList &exps;
        NExpFuncCall(string id) : id{id} {
            NExpressionList *list = new NExpressionList();
            exps = *list;
            delete list;
        }
        NExpFuncCall(string id, const vector<Expression*> &exps) : id{id}, exps{exps} {}
};

#endif /* !NEXPFUNCCALL_H */