#ifndef NTYPE_HPP
#define NTYPE_HPP

#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NType : public NAbstractAstNode {
    public:
        string id;
        NType() {}
        NType(string id) : id{id} {} 

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NTYPE_HPP */