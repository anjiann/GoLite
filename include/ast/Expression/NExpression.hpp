#ifndef NEXPRESSION_H
#define NEXPRESSION_H

#include <memory>
#include <vector>
#include <iostream>
#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NExpression : public NAbstractAstNode {
    private:
        bool isEmpty = false; //hack for empty expressions to prevent infinite recursion since we use polymorphism in visitor pattern

    public:
        mutable NType type = NType();

        NExpression() : isEmpty{true} {}
        NExpression(const NExpression &src) = default;
        NExpression(NExpression &&src) = default;

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            if(!isEmpty) {
                dispatcher.dispatch(*this);
            }
        }
};

typedef std::vector<std::shared_ptr<NExpression>> NExpressionList;

#endif /* !NEXPRESSION_H */