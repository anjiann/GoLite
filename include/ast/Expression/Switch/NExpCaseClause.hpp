#ifndef NEXPCASECLAUSE_H
#define NEXPCASECLAUSE_H

#include "../../Statement/NStatement.hpp"
#include "../NExpression.hpp"
#include "NExpSwitchCase.hpp"

class NExpCaseClause : NExpression {
    public:
        const NExpSwitchCase &switchCase;
        const NStatementList &stmts;
        NExpCaseClause(const NExpSwitchCase &switchCase, const NStatementList &stmts) 
            : switchCase{switchCase}, stmts{stmts} {}
};

typedef std::vector<NExpCaseClause*> NExpCaseClauseList;


#endif /* !NEXPCASECLAUSE_H */