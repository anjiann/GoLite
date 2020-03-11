#ifndef NSTMTIFELSEIF_H
#define NSTMTIFELSEIF_H

#include "NStatement.hpp"

class NStmtIfElseIf : NStatement{
    public:
        const NExpression &condition;
        NStatements *body;
        NStatement *ifstmt;
        NStmtIfElseIf(const NExpression &condition, NStatements *body, NStatement *ifstmt) 
            : condition{condition}, body{body}, ifstmt{ifstmt} {}
}

#endif /* !NSTMTIFELSEIF_H */