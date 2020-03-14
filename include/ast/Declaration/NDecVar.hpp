#ifndef NDECVAR_HPP
#define NDECVAR_HPP

#include <vector>
#include "../../abstractDispatcher.hpp"

#include "NDeclaration.hpp"
#include "../Expression/NExpression.hpp"
#include "../Expression/NExpIdentifier.hpp"
#include "../Type/NType.hpp"


class NDecVar : public NDeclaration {
    public:
        NExpIdentifierList &lhs;
        const NType &type;
        const NExpressionList &rhs;
        NDecVar(string id, const NType &type) : NDecVar(*(new NExpIdentifierList()), type, *(new NExpressionList())) {
            NExpIdentifier *tempId = new NExpIdentifier(id);
            lhs.push_back(tempId);
        }

        NDecVar(NExpIdentifierList &lhs, const NType &type, const NExpressionList &rhs) 
            : lhs{lhs}, type{type}, rhs{rhs} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<NDecVar*> NDecVarList;


#endif /* !NDECVAR_HPP */