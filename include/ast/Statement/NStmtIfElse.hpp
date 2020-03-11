#ifndef NSTMTIFELSE_H
#define NSTMTIFELSE_H

#include "NStatement.hpp"

class NStmtIfElse : NStatement{
    public:
        const NExpression &condition;
        NStatements *body;
        NStatements *elsebody;

        //else if constructor
        NStmtIfElse(const NExpression &condition, NStatements *body, NStatement *elseifstmt)
            :  condition{condition}, body{body} {
            NStatements stmts = new NStatements();
            stmts.push_back(elseifstmt);
            elsebody = stmts;
        }

        NStmtIfElse(const NExpression &condition, NStatements *body, NStatements *elsebody) 
            : condition{condition}, body{body}, elsebody{elsebody} {}
}

#endif /* !NSTMTIFELSE_H */