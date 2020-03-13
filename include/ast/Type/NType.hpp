#ifndef NTYPE_HPP
#define NTYPE_HPP

#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NType : public NAbstractAstNode {
    public:
        NType();

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NTYPE_HPP */