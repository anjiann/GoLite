#ifndef NDECVAR_HPP
#define NDECVAR_HPP

#include "NDeclaration.hpp"
#include "NExpression.hpp"

class NDecVar : NDeclaration {
    public:
        const NExpressionList &lhs;
        const NType &type;
        const NExpressionList &rhs;

        NDecVar(const NExpressionList &lhs, const NType &type) : lhs{lhs}, type{type} rhs(NExpressionList()) {}
        NDecVar(const NExpressionList &lhs, const NType &type, const NExpressionList &rhs) 
            : lhs{lhs}, type{type}, rhs{rhs} {}
 
}

#endif /* !NDECVAR_HPP */