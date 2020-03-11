#ifndef NDECTYPE_HPP
#define NDECTYPE_HPP

#include <string>

#include "typedefs.hpp"

using std::string;

class NDecType : NDeclaration {
    public:
        const NExpIdentifier &id;
        const NExpressionList &exps;
        
        NDecFunc(const NExpIdentifier &id, NExpressionList &exps) : id{id}, exps{exps} {}
        NDecFunc(const NExpIdentifier &id) : NDecFunc(id, NExpressionList(1, NULL));
}

#endif /* !NDECTYPE_HPP */