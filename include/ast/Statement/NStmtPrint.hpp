#ifndef NSTMTPRINT_H
#define NSTMTPRINT_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtPrint : public NStatement {
    public:
        const NExpressionList &exps; 
        bool newLine;
        NStmtPrint(const NExpressionList &exps, bool newLine) : exps{exps}, newLine{newLine} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTPRINT_H */