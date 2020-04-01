#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <memory>
#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../NAbstractAstNode.hpp"

class NDeclaration : public NAbstractAstNode {
    public:
        NDeclaration() {}

        NDeclaration(const NDeclaration &src) = default;
        NDeclaration(NDeclaration &&src) = default;
        
        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NDeclaration>> NDeclarationList;


#endif /* !NDECLARATION_H */