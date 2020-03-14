#ifndef NEXPBINARY_H
#define NEXPBINARY_H

#include "../../abstractDispatcher.hpp"

#include <string>
#include "NExpression.hpp"
#include "enums.hpp"

using std::string;

class NExpBinary : public NExpression {    
    public:
        const NExpression &lhs;
        const NExpression &rhs;
        NExpOpKind op;
        NExpBinary(const NExpression &lhs, const NExpression &rhs, NExpOpKind op) : lhs{lhs}, rhs{rhs}, op{op} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPBINARY_H */