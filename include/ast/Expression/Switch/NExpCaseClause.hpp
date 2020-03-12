#ifndef NEXPCASECLAUSE_H
#define NEXPCASECLAUSE_H

#include "../../NStatements.hpp"
#include "../NExpression.hpp"
#include "NExpSwitchCase.hpp"

class NExpCaseClause : NExpression {
    public:
        const NExpSwitchCase &switchCase;
        const NStatements &stmts;
        NExpCaseClause(const NExpSwitchCase &switchCase, const NStatements &stmts) 
            : switchCase{switchCase}, stmts{stmts} {}
};

typedef std::vector<NExpCaseClause*> NExpCaseClauseList;


#endif /* !NEXPCASECLAUSE_H */