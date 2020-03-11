#ifndef NSTMTFOR_H
#define NSTMTFOR_H

#include "NStatement.hpp"

class NStmtFor : NStatement {
    public:
        const NStatement &initStmt;
        const NExpression &exp;
        const NStatement &updateStmt;
        const NStatements &stmts;

        NStmtFor(const NExpression &exp, const NStatements &stmts) {
            NStatement *stmt = new NStatement();
            initStmt = *stmt;
            updateStmt = *stmt;
        }
        NStmtFor(const NStatement &initStmt, const NExpression &exp, const NStatement &updateStmt, const NStatements &stmts)
            : initStmt{initStmt}, exp{exp}, updateStmt{updateStmt}, stmts{stmts} {}
}

#endif /* !NSTMTFOR_H */