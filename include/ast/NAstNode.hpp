#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../prettyPrinter.hpp"

class NAstNode {
    virtual void accept(const PrettyPrinter &prettyPrinter);
};

#endif