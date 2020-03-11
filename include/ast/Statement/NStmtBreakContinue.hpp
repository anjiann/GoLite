#ifndef NSTMTBREAKCONTINUE_H
#define NSTMTBREAKCONTINUE_H

#include "NStatement.hpp"

class NStmtBreakContinue : NStatement {
    public:
        NStmtBreakContinueEnum stmtEnum;
        NStmtBreakContinue(NStmtBreakContinueEnum stmtEnum) : stmtEnum{stmtEnum} {}
};

enum NStmtBreakContinueEnum {
    breakStmt,
    continueStmt
}

#endif /* !NSTMTBREAKCONTINUE_H */