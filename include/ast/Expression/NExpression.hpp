#ifndef NEXPRESSION_H
#define NEXPRESSION_H

#include <memory>
#include <vector>
#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NExpression : public NAbstractAstNode {
    public:
        mutable NType type = NType();

        NExpression() {}

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NExpression>> NExpressionList;


#endif /* !NEXPRESSION_H */