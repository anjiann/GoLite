#ifndef NEXPCASECLAUSE_H
#define NEXPCASECLAUSE_H

#include "NExpression.hpp"

typedef std::vector<NExpCaseClause*> NExpCaseClauseList;

class NExpCaseClause : NExpression {
    public:
        const NExpSwitchCase &switchCase;
        const NStatements &stmts;
        NExpCaseClause(const NExpSwitchCase &switchCase, const NStatements &stmts) 
            : switchCase{switchCase}, stmts{stmts} {}
};

#endif /* !NEXPCASECLAUSE_H */