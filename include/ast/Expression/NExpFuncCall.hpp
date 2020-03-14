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
        const NExpressionList &exps;
        
        // NExpFuncCall(string id, const NExpressionList &exps) : id{id}, exps{exps} {}
        NExpFuncCall(const NExpression &expId, const NExpressionList &exps) : expId{expId}, exps{exps} {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPFUNCCALL_H */