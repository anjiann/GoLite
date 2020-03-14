#ifndef NEXPBUILTIN_H
#define NEXPBUILTIN_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"
#include "enums.hpp"

using std::string;

class NExpBuiltin : public NExpression {    
    public:
        NExpBuiltinKind name;
        const NExpression &exp;
        NExpBuiltin(const NExpression &exp, NExpBuiltinKind name) : exp{exp}, name{name} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};



#endif /* !NEXPBUILTIN_H */