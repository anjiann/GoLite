#ifndef NSTMTEXP_H
#define NSTMTEXP_H

#include <memory>
#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Expression/NExpression.hpp"

class NStmtExp : public NStatement {
    public:
        std::shared_ptr<NExpression> exp;

        NStmtExp(std::shared_ptr<NExpression> exp) : exp{exp} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTEXP_H */