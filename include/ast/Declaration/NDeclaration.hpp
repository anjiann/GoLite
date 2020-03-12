#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <vector>
#include "../NAstNode.hpp"

class NDeclaration : public NAstNode {
    public:
        int lineno;

        NDeclaration() {}
        NDeclaration(int lineno) : lineno{lineno} {}
};

typedef std::vector<NDeclaration*> NDeclarationList;


#endif /* !NDECLARATION_H */