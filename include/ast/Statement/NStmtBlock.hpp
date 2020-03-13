#ifndef NSTMTBLOCK_H
#define NSTMTBLOCK_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtBlock : public NStatement {
    public:
        const NStatementList &stmts;
        NStmtBlock(const NStatementList &stmts) : stmts{stmts} {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTBLOCK_H */