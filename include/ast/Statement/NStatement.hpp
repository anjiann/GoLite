#ifndef NSTATEMENT_H
#define NSTATEMENT_H

#include <memory>
#include <vector>
#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NStatement : public NAbstractAstNode {
    public:
        NStatement() {}

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NStatement>> NStatementList;


#endif /* !NSTATEMENT_H */