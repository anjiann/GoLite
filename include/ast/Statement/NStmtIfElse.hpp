#ifndef NSTMTIFELSE_H
#define NSTMTIFELSE_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtIfElse : public NStatement{
    public:
        const NExpression &condition;
        const NStatementList &body;
        const NStatementList &elsebody;

        NStmtIfElse(const NExpression &condition, const NStatementList &body, const NStatementList &elsebody) 
            : condition{condition}, body{body}, elsebody{elsebody} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTIFELSE_H */