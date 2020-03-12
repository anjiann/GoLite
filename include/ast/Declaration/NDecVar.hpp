#ifndef NDECVAR_HPP
#define NDECVAR_HPP

#include <vector>

#include "NDeclaration.hpp"
#include "../Expression/NExpression.hpp"
#include "../Type/NType.hpp"


class NDecVar : public NDeclaration {
    public:
        const NExpressionList &lhs;
        const NType &type;
        const NExpressionList &rhs;

        NDecVar(const NExpressionList &lhs, const NType &type, const NExpressionList &rhs) 
            : lhs{lhs}, type{type}, rhs{rhs} {}
};

typedef std::vector<NDecVar*> NDecVarList;


#endif /* !NDECVAR_HPP */