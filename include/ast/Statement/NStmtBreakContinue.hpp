#ifndef NSTMTBREAKCONTINUE_H
#define NSTMTBREAKCONTINUE_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"


enum NStmtBreakContinueKind{
    breakStmt,
    continueStmt
};

class NStmtBreakContinue : public NStatement {
    public:
        NStmtBreakContinueKind kind;
        NStmtBreakContinue(NStmtBreakContinueKind kind) : kind{kind} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};


#endif /* !NSTMTBREAKCONTINUE_H */