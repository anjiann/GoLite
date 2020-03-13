#ifndef NEXPRESSION_H
#define NEXPRESSION_H

#include <vector>
#include "../../abstractDispatcher.hpp"

class NExpression : public NAstNode {
    public:
        NExpression();

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NExpression*> NExpressionList;


#endif /* !NEXPRESSION_H */