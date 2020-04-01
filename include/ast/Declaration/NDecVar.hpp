#ifndef NDECVAR_HPP
#define NDECVAR_HPP

#include <memory>
#include "NDeclaration.hpp"
#include "../Expression/NExpression.hpp"
#include "../Expression/NExpIdentifier.hpp"
#include "../Type/NType.hpp"


class NDecVar : public NDeclaration {
    public:
        NExpIdentifierList lhs;
        std::shared_ptr<NType> type;
        const NExpressionList rhs;

        //wrapper for function parameters
        NDecVar(string id, std::shared_ptr<NType> type) : lhs{NExpIdentifierList()}, type{type}, rhs{NExpressionList()} {
            std::shared_ptr<NExpIdentifier> tempId {new NExpIdentifier(id)};
            lhs.push_back(std::move(tempId));
        }

        NDecVar(NExpIdentifierList &lhs, std::shared_ptr<NType> type, const NExpressionList &rhs) 
            : lhs{std::move(lhs)}, type{type}, rhs{std::move(rhs)} {}

        NDecVar(NDecVar &src) = default;
        NDecVar(NDecVar &&src) = default;

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NDecVar>> NDecVarList;


#endif /* !NDECVAR_HPP */