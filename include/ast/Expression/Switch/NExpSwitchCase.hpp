#ifndef NEXPSWITCHCASE_H
#define NEXPSWITCHCASE_H

#include "NExpression.hpp"

// ExprSwitchCase = "case" ExpressionList | "default" .
// refer to https://golang.org/ref/spec#ExprSwitchStmt
class NExpSwitchCase : NExpression {
    public:
        const NExpressionList &explist; //"default" if size == 0, "case" otherwise
        
        NExpSwitchCase() {
            NExpressionList *list = new NExpressionList();
            explist = *NExpressionList;
         }

        NExpSwitchCase(const NExpressionList &explist) : explist{explist} {}
};

#endif /* !NEXPSWITCHCASE_H */