#ifndef NEXPFUNCCALL_H
#define NEXPFUNCCALL_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"

using std::string;

class NExpFunc : public NExpression {    
    public:
        // string id;
        const NExpression &expId;
        const NExpressionList &args;
        
        NExpFunc(const NExpression &expId, const NExpressionList &args) : expId{expId}, args{args} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPFUNCCALL_H */