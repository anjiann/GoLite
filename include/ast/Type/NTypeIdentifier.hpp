#ifndef NTYPEIDENTIFIER_H
#define NTYPEIDENTIFIER_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NType.hpp"

using std::string;

class NTypeIdentifier : public NType {    
    public:
        NTypeIdentifier(string id) : NType(id) {}

        void accept(const AbstractDispatcher &dispatcher) const override{
            dispatcher.dispatch(*this);
        }
};

#endif /* !NTYPEIDENTIFIER_H */