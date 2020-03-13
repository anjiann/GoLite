#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../abstractDispatcher.hpp"

#include "../prettyPrinter.hpp"

class NAbstractAstNode {
    // virtual void accept(const PrettyPrinter &prettyPrinter);
    virtual void accept(const AbstractDispatcher &dispatcher);
};

#endif