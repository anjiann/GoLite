#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../NAstNode.hpp"

class NDeclaration : public NAstNode {
    public:
        int lineno;

        NDeclaration() {}
        NDeclaration(int lineno) : lineno{lineno} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NDeclaration*> NDeclarationList;


#endif /* !NDECLARATION_H */