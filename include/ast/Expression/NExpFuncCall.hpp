#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"

using std::string;

class NExpFuncCall : public NExpression {    
    public:
        // string id;
        const NExpression &expId;
        const NExpressionList &params;
        
        NExpFuncCall(const NExpression &expId, const NExpressionList &params) : expId{expId}, params{params} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPFUNCCALL_H */