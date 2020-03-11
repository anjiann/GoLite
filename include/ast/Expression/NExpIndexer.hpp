#ifndef NEXPINDEXER_H
#define NEXPINDEXER_H

#include <string>

#include "NExpression.hpp"

using std::string;

class NExpIndexer : NExpression {    
    public:
        string id;
        const Nexpression &exp;

        NExpIndexer(string id, const NExpression &exp) : id{id}, exp{exp} {}
};

#endif /* !NEXPINDEXER_H */