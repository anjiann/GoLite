#ifndef NEXPRESSION_H
#define NEXPRESSION_H

#include <vector>
#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NExpression : public NAbstractAstNode {
    public:
        NExpression() {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NExpression*> NExpressionList;


#endif /* !NEXPRESSION_H */