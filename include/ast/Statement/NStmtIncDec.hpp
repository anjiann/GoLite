#ifndef NSTMTINCDEC_H
#define NSTMTINCDEC_H

#include <string>
#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

using std::string;

class NStmtIncDec : public NStatement {
    public:
        string id;
        bool isIncrement;

        NStmtIncDec(string id, bool isIncrement) : id{id}, isIncrement{isIncrement} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTINCDEC_H */