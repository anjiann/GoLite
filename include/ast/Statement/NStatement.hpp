#ifndef NSTATEMENT_H
#define NSTATEMENT_H

#include <vector>
#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NStatement : public NAbstractAstNode {
    public:
        int lineno;

        NStatement() {}
        NStatement(int lineno) : lineno{lineno} {}

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NStatement*> NStatementList;


#endif /* !NSTATEMENT_H */