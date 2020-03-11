#ifndef NSTMTIF_H
#define NSTMTIF_H

#include "NStatement.hpp"
#include "NStatements.hpp"

class NStmtIf : NStatement{
    public:
        const NExpression &condition;
        NStatements *body;
        NStmtIf(const NExpression &condition, NStatements *body) : condition{condition}, body{body} {}
}

#endif /* !NSTMTIF_H */