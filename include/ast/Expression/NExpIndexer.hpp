#ifndef NEXPINDEXER_H
#define NEXPINDEXER_H

#include <string>

#include "NExpression.hpp"

using std::string;

class NExpIndexer : NExpression {    
    public:
        string identifier;
        const Nexpression &exp;
        
        NExpIndexer(string identifier, const NExpression &exp) : identifier{identifier}, exp{exp} {}
};

#endif /* !NEXPINDEXER_H */