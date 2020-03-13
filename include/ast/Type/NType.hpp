#ifndef NTYPE_HPP
#define NTYPE_HPP

#include "../../abstractDispatcher.hpp"

#include "../NAstNode.hpp"

class NType : public NAstNode {
    public:
        NType();

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NTYPE_HPP */