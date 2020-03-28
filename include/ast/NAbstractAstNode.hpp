#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../abstractDispatcher.hpp"

extern int lineno;

class NAbstractAstNode {
    public:
        int lineno = lineno;

        virtual void accept(const AbstractDispatcher &dispatcher) const = 0;
};

#endif