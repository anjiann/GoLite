#ifndef NSTMTINCDEC_H
#define NSTMTINCDEC_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

class NStmtIncDec : public NStatement {
    public:
        string id;
        bool isIncrement;

        NStmtIncDec(string id, bool isIncrement) : id{id}, isIncrement{isIncrement} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTINCDEC_H */