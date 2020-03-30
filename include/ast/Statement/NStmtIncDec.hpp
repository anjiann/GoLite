#ifndef NSTMTINCDEC_H
#define NSTMTINCDEC_H

#include <string>
#include "NStatement.hpp"
#include "../Expression/NExpIdentifier.hpp"
#include "../../abstractDispatcher.hpp"

using std::string;

class NStmtIncDec : public NStatement {
    public:
        const NExpIdentifier &exp;
        bool isIncrement;

        NStmtIncDec(const NExpIdentifier &exp, bool isIncrement) : exp{exp}, isIncrement{isIncrement} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTINCDEC_H */