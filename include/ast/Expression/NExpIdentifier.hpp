#ifndef NEXPIDENTIFIER_H
#define NEXPIDENTIFIER_H

#include <string>
#include <vector>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"

using std::string;

class NExpIdentifier : public NExpression {    
    public:
        string name;
        NExpIdentifier(string name) : name{name} {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NExpIdentifier*> NExpIdentifierList;

#endif /* !NEXPIDENTIFIER_H */