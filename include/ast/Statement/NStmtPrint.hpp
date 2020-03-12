#ifndef NSTMTPRINT_H
#define NSTMTPRINT_H

#include "NStatement.hpp"
#include "../Expression/NExpression.hpp"

class NStmtPrint : public NStatement {
    public:
        const NExpressionList &exps; 
        bool newLine;
        NStmtPrint(const NExpressionList &exps, bool newLine) : exps{exps}, newLine{newLine} {}
};

#endif /* !NSTMTPRINT_H */