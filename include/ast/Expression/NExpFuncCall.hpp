#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>

#include "NExpression.hpp"

using std::string;

class NExpFuncCall : NExpression {    
    public:
        string identifier;
        const vector<Expression*> &exps;
        NExpFuncCall(string identifier, const vector<Expression*> &exps) : identifier{identifier}, exps{exps} {}
};

#endif /* !NEXPFUNCCALL_H */