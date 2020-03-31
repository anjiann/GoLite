#ifndef NEXPIDENTIFIER_H
#define NEXPIDENTIFIER_H

#include <string>
#include <memory>
#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../../symbolPhase/symbols/symbol.hpp"

#include "NExpression.hpp"

using std::string;

class NExpIdentifier : public NExpression {    
    public:
        const string name;
        mutable const Symbol *symbol = nullptr; //TODO unique ptr

        NExpIdentifier(const string &name) : name{name} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NExpIdentifier>> NExpIdentifierList;

#endif /* !NEXPIDENTIFIER_H */