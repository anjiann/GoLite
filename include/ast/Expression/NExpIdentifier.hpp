#ifndef NEXPIDENTIFIER_H
#define NEXPIDENTIFIER_H

#include <string>

#include "NExpression.hpp"

using std::string;

class NExpIdentifier : public NExpression {    
    public:
        string name;
        NExpIdentifier(string name) : name{name} {}
};

#endif /* !NEXPIDENTIFIER_H */