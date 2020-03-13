#ifndef NPROGRAM_HPP
#define NPROGRAM_HPP

#include <string>
#include "../../abstractDispatcher.hpp"

#include "Declaration/NDeclaration.hpp"

using std::string;

class NProgram {
    public:
        string package;
        const NDeclarationList &topdecs;

        NProgram(string package, const NDeclarationList &topdecs) : package{package}, topdecs{topdecs} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif 