#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <memory>
#include <vector>
#include "../../abstractDispatcher.hpp"
#include "../NAbstractAstNode.hpp"

class NDeclaration : public NAbstractAstNode {
    public:
        NDeclaration() {}
        
        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

typedef std::vector<std::shared_ptr<NDeclaration>> NDeclarationList;


#endif /* !NDECLARATION_H */