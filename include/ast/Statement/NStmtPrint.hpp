#ifndef NSTMTPRINT_H
#define NSTMTPRINT_H

#include "NStatement.hpp"

class NStmtPrint : NStatement {
    public:
        const NExpressionList &exps; 
        NStmtPrint(const NExpressionList &exps, bool newLine) : exps{exps}, newLine{newLine} {}
}

#endif /* !NSTMTPRINT_H */