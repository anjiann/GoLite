#ifndef NDECVAR_HPP
#define NDECVAR_HPP

#include "NDeclaration.hpp"
#include "NExpression.hpp"

typedef vector<NDecVar*> NDecVarList;

class NDecVar : NDeclaration {
    public:
        const NExpressionList &lhs;
        const NType &type;
        const NExpressionList &rhs;

        NDecVar(const NExpressionList &lhs, const NType &type, const NExpressionList &rhs) 
            : lhs{lhs}, type{type}, rhs{rhs} {}

        NDecVar(string id, const NType &type) {
            NExpression *expId = new NExpIdentifier(id);
            lhs = {expId};
            rhs = *(new NExpressionList());
        }
}

#endif /* !NDECVAR_HPP */