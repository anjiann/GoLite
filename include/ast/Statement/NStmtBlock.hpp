#ifndef NSTMTBLOCK_H
#define NSTMTBLOCK_H

#include "NStatement.hpp"
#include "NExpression.hpp"
#include "NStatements.hpp"

class NStmtBlock {
    public:
        NStatements *stmts;
        NStmtBlock(NStatements *stmts) : stmts{stmts} {}
}

#endif /* !NSTMTBLOCK_H */