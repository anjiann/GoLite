#ifndef NSTMTEXP_H
#define NSTMTEXP_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtExp : public NStatement {
    public:
        const NExpression &exp;

        NStmtExp(const NExpression &exp) : exp{exp} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTEXP_H */