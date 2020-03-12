#ifndef NSTMTBLOCK_H
#define NSTMTBLOCK_H

#include "NStatement.hpp"
#include "../Expression/NExpression.hpp"
#include "../NStatements.hpp"

class NStmtBlock {
    public:
        const NStatements &stmts;
        NStmtBlock(const NStatements &stmts) : stmts{stmts} {}
};

#endif /* !NSTMTBLOCK_H */