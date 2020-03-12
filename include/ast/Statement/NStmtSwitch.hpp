#ifndef NSTMTSWITCH_H
#define NSTMTSWITCH_H

#include "NStatement.hpp"
#include "../Expression/Switch/NExpCaseClause.hpp"

class NStmtSwitch : public NStatement {
    public:
        const NExpression &condition;
        const NExpCaseClauseList &caseClauses;

        NStmtSwitch(const NExpression &condition, const NExpCaseClauseList &caseClauses)
            : condition{condition}, caseClauses{caseClauses} {}
};

#endif /* !NSTMTSWITCH_H */