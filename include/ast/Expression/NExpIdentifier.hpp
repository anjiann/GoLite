#ifndef NEXPIDENTIFIER_H
#define NEXPIDENTIFIER_H

#include <string>
#include "NExpression.h"

using std::string;

class NExpIdentifier: NExpression {    
    public:
        int name;
        NExpIdentifier(string name) name{name} {}
};

#endif /* !NEXPIDENTIFIER_H */