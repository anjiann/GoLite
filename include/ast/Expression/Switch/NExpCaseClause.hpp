#ifndef NEXPCASECLAUSE_H
#define NEXPCASECLAUSE_H

#include "../../../abstractDispatcher.hpp"

#include "../../Statement/NStatement.hpp"
#include "../NExpression.hpp"
#include "NExpSwitchCase.hpp"

class NExpCaseClause : NExpression {
    public:
        const NExpSwitchCase switchCase;
        const NStatementList stmts;

        NExpCaseClause(const NExpSwitchCase &switchCase, const NStatementList &stmts) 
            : switchCase{switchCase}, stmts{stmts} {}

        NExpCaseClause(NExpCaseClause &&src) = default;

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }


};

typedef std::vector<std::shared_ptr<NExpCaseClause>> NExpCaseClauseList;


#endif /* !NEXPCASECLAUSE_H */