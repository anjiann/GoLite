#ifndef NSTMTASSIGN_H
#define NSTMTASSIGN_H

#include "NStatement.hpp"
#include "../Expression/NExpression.hpp"

class NStmtAssign : NStatement {
    public:
        const NExpressionList &lhs;
        const NExpressionList &rhs;
        NStmtAssign(const NExpressionList &lhs, const NExpressionList &rhs) : lhs{lhs}, rhs{rhs} {}
};

#endif /* !NSTMTASSIGN_H */