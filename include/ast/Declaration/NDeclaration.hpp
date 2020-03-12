#ifndef NDECLARATION_H
#define NDECLARATION_H

#include <vector>

class NDeclaration {
    public:
        int lineno;

        NDeclaration() {}
        NDeclaration(int lineno) : lineno{lineno} {}
};

typedef std::vector<NDeclaration*> NDeclarationList;


#endif /* !NDECLARATION_H */