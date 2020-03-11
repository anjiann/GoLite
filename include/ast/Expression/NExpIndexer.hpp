#ifndef NEXPINDEXER_H
#define NEXPINDEXER_H

#include <string>

#include "NExpression.hpp"

using std::string;

class NExpIndexer : NExpression {    
    public:
        const Nexpression &exp;
        const Nexpression &index;

        NExpIndexer(const NExpression &exp, const NExpression &index) : exp{exp}, index{index} {}
};

#endif /* !NEXPINDEXER_H */