#ifndef NSTMTDEC_H
#define NSTMTDEC_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Declaration/NDeclaration.hpp"

class NStmtDec : public NStatement {
    public:
        const NDeclaration &dec;

        NStmtDec(const NDeclaration &dec) : dec{dec} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTDEC_H */