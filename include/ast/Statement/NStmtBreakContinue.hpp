#ifndef NSTMTBREAKCONTINUE_H
#define NSTMTBREAKCONTINUE_H

#include "NStatement.hpp"

enum NStmtBreakContinueKind{
    breakStmt,
    continueStmt
};

class NStmtBreakContinue : NStatement {
    public:
        NStmtBreakContinueKind kind;
        NStmtBreakContinue(NStmtBreakContinueKind kind) : kind{kind} {}
};


#endif /* !NSTMTBREAKCONTINUE_H */