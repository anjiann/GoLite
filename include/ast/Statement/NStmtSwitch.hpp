#ifndef NSTMTSWITCH_H
#define NSTMTSWITCH_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/Switch/NExpCaseClause.hpp"

class NStmtSwitch : public NStatement {
    public:
        const NExpression &condition;
        const NExpCaseClauseList &caseClauses;

        NStmtSwitch(const NExpression &condition, const NExpCaseClauseList &caseClauses)
            : condition{condition}, caseClauses{caseClauses} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTSWITCH_H */