#ifndef NEXPIDENTIFIER_H
#define NEXPIDENTIFIER_H

#include <string>
#include <memory>
#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../../symbolPhase/symbols/localSymbol.hpp"

#include "NExpression.hpp"

using std::string;

class NExpIdentifier : public NExpression {    
    public:
        const string name;
        mutable std::shared_ptr<const LocalSymbol> symbol;

        NExpIdentifier(const string &name) : name{name} {}
        NExpIdentifier(const NExpIdentifier &src) : name{name}, symbol{src.symbol} {}
        NExpIdentifier(NExpIdentifier &&src) : name{name}, symbol{std::move(src.symbol)} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NExpIdentifier>> NExpIdentifierList;

#endif /* !NEXPIDENTIFIER_H */