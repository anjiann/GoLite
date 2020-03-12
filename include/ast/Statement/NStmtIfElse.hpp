#ifndef NSTMTIFELSE_H
#define NSTMTIFELSE_H

#include "NStatement.hpp"
#include "../Expression/NExpression.hpp"

class NStmtIfElse : NStatement{
    public:
        const NExpression &condition;
        const NStatementList &body;
        const NStatementList &elsebody;

        NStmtIfElse(const NExpression &condition, const NStatementList &body, const NStatementList &elsebody) 
            : condition{condition}, body{body}, elsebody{elsebody} {}
};

#endif /* !NSTMTIFELSE_H */