#ifndef NTYPEIDENTIFIER_H
#define NTYPEIDENTIFIER_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NType.hpp"

using std::string;

class NTypeIdentifier : public NType {            
    public:
        bool isArrayId = false;

        NTypeIdentifier() : NType() {}
        NTypeIdentifier(const string &id) : NType(id) {}
        NTypeIdentifier(const string &id, bool isArrayId) : NType(id), isArrayId{isArrayId} {}

        NTypeIdentifier(const NTypeIdentifier &src) = default;
        NTypeIdentifier(NTypeIdentifier &&src) = default;

        void accept(const AbstractDispatcher &dispatcher) const override{
            dispatcher.dispatch(*this);
        }
};

#endif /* !NTYPEIDENTIFIER_H */