#ifndef NSTMTBLOCK_H
#define NSTMTBLOCK_H

#include "NStatement.hpp"
#include "../Expression/NExpression.hpp"

class NStmtBlock {
    public:
        const NStatementList &stmts;
        NStmtBlock(const NStatementList &stmts) : stmts{stmts} {}
};

#endif /* !NSTMTBLOCK_H */