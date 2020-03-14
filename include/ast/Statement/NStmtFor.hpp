#ifndef NSTMTFOR_H
#define NSTMTFOR_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtFor : public NStatement {
    public:
        const NStatement &initStmt;
        const NExpression &exp;
        const NStatement &updateStmt;
        const NStatementList &stmts;

        NStmtFor(const NStatement &initStmt, const NExpression &exp, const NStatement &updateStmt, const NStatementList &stmts)
            : initStmt{initStmt}, exp{exp}, updateStmt{updateStmt}, stmts{stmts} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTFOR_H */