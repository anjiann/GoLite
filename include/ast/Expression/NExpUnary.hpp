#ifndef NEXPUNARY_H
#define NEXPUNARY_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"
#include "enums.hpp"

using std::string;

class NExpUnary : public NExpression {    
    public:
        const NExpression &exp;
        NExpOpKind op;

        NExpUnary(const NExpression &exp, NExpOpKind op) : exp{exp}, op{op} {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};


#endif /* !NEXPUNARY_H */