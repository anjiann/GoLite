#ifndef NEXPIDENTIFIER_H
#define NEXPIDENTIFIER_H

#include <string>
#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../../symbolPhase/symbols/symbol.hpp"

#include "NExpression.hpp"

using std::string;

class NExpIdentifier : public NExpression {    
    public:
        const string name;
        mutable const Symbol *symbol = nullptr;

        NExpIdentifier(const string &name) : name{name} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NExpIdentifier*> NExpIdentifierList;

#endif /* !NEXPIDENTIFIER_H */