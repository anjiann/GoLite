#ifndef NSTMTEMPTY_H
#define NSTMTEMPTY_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"


class NStmtEmpty : public NStatement {
    public:
        NStmtEmpty() {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTEMPTY_H */