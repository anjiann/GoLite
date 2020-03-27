#ifndef NSTMTASSIGN_H
#define NSTMTASSIGN_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtAssign : public NStatement {
    public:
        const NExpressionList lhs;
        const NExpressionList rhs;
        NStmtAssign(const NExpressionList &lhs, const NExpressionList &rhs) : lhs{lhs}, rhs{rhs} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTASSIGN_H */