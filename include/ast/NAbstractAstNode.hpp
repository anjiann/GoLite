#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../abstractDispatcher.hpp"

#include "../prettyPrintPhase.hpp"

class NAbstractAstNode {
    virtual void accept(const AbstractDispatcher &dispatcher) const {}
};

#endif