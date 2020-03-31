#ifndef NDECVAR_HPP
#define NDECVAR_HPP

#include "NDeclaration.hpp"
#include "../Expression/NExpression.hpp"
#include "../Expression/NExpIdentifier.hpp"
#include "../Type/NType.hpp"


class NDecVar : public NDeclaration {
    public:
        NExpIdentifierList lhs;
        const NType type;
        const NExpressionList rhs;

        //used for function parameters as params are stored as a NDecVarList
        NDecVar(string id, const NType &type) : lhs{NExpIdentifierList()}, type{type}, rhs{NExpressionList()} {
            std::unique_ptr<NExpIdentifier> tempId {new NExpIdentifier(id)};
            lhs.push_back(std::move(tempId));
        }

        NDecVar(NExpIdentifierList &lhs, const NType &type, const NExpressionList &rhs) 
            : lhs{lhs}, type{type}, rhs{std::move(rhs)} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NDecVar>> NDecVarList;


#endif /* !NDECVAR_HPP */