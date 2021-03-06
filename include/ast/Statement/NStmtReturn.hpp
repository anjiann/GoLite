#ifndef NSTMTRETURN_H
#define NSTMTRETURN_H

#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtReturn : public NStatement {
    public:
        const NExpression exp;
        NStmtReturn(const NExpression &exp) : exp{exp} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTRETURN_H */