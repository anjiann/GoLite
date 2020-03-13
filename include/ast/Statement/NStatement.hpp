#ifndef NSTATEMENT_H
#define NSTATEMENT_H

#include <vector>
#include "../../abstractDispatcher.hpp"

#include "../NAstNode.hpp"

class NStatement : public NAstNode {
    public:
        int lineno;

        NStatement() {}
        NStatement(int lineno) : lineno{lineno} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NStatement*> NStatementList;


#endif /* !NSTATEMENT_H */