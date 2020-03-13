#ifndef NEXPINDEXER_H
#define NEXPINDEXER_H

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"

using std::string;

class NExpIndexer : public NExpression {    
    public:
        const NExpression &exp;
        const NExpression &index;

        NExpIndexer(const NExpression &exp, const NExpression &index) : exp{exp}, index{index} {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPINDEXER_H */