#ifndef NSTMTDEC_H
#define NSTMTDEC_H

#include <memory>
#include "NStatement.hpp"
#include "../../abstractDispatcher.hpp"

#include "../Declaration/NDeclaration.hpp"

class NStmtDec : public NStatement {
    public:
        std::shared_ptr<NDeclaration> dec;

        NStmtDec(std::shared_ptr<NDeclaration> dec) : dec{dec} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NSTMTDEC_H */