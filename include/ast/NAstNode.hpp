#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../../abstractDispatcher.hpp"

#include "../prettyPrinter.hpp"

class NAstNode {
    // virtual void accept(const PrettyPrinter &prettyPrinter);
    virtual void dispatch(const AbstractDispatcher &dispatcher);
};

#endif