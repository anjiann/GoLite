#ifndef NEXPSWITCHCASE_H
#define NEXPSWITCHCASE_H

#include "../../../abstractDispatcher.hpp"

#include "../NExpression.hpp"

// ExprSwitchCase = "case" ExpressionList | "default" .
// refer to https://golang.org/ref/spec#ExprSwitchStmt
class NExpSwitchCase : NExpression {
    public:
        const NExpressionList &explist; //"default" if size == 0, "case" otherwise
        
        NExpSwitchCase(const NExpressionList &explist) : explist{explist} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPSWITCHCASE_H */