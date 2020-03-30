#ifndef NASTNODE_HPP
#define NASTNODE_HPP

#include "../abstractDispatcher.hpp"

extern int yylineno;

class NAbstractAstNode {
    public:
        int lineno = yylineno;

        virtual void accept(const AbstractDispatcher &dispatcher) const = 0;
};

#endif