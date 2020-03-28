#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../NAbstractAstNode.hpp"

class NDeclaration : public NAbstractAstNode {
    public:
        int lineno;

        NDeclaration() {}

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NDeclaration*> NDeclarationList;


#endif /* !NDECLARATION_H */