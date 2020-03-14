#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../abstractDispatcher.hpp"

class NAbstractAstNode {
    virtual void accept(const AbstractDispatcher &dispatcher) const = 0;
};

#endif