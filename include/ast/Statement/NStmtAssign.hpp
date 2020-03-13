#ifndef NSTMTASSIGN_H
#define NSTMTASSIGN_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtAssign : public NStatement {
    public:
        const NExpressionList &lhs;
        const NExpressionList &rhs;
        NStmtAssign(const NExpressionList &lhs, const NExpressionList &rhs) : lhs{lhs}, rhs{rhs} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTASSIGN_H */