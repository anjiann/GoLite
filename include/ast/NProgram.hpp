#ifndef NPROGRAM_HPP
#define NPROGRAM_HPP

#include "NDeclaration.hpp"

class NProgram {
    public:
        string package;
        const NDeclarationList &topdecs;

        NProgram(string package, const NDeclarationList &topdecs) : package{package}, topdecs{topdecs} {}
};

#endif 