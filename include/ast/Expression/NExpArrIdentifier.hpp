#ifndef NEXPARRIDENTIFIER_H
#define NEXPARRIDENTIFIER_H

#include <string>
#include <vector>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"
#include "NExpIdentifier.hpp"

using std::string;

class NExpArrIdentifier : public NExpIdentifier {    
    public:
        std::vector<NExpression*> sizeExps;

        NExpArrIdentifier(string name) : NExpIdentifier(name) {}
};

#endif /* !NEXPARRIDENTIFIER_H */