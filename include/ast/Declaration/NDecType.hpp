#ifndef NDECTYPE_HPP
#define NDECTYPE_HPP

#include <string>

#include "NDeclaration.hpp"
#include "NExpression.hpp"

#include "NExpIdentifier.hpp"

using std::string;

class NDecType : NDeclaration {
    public:
        string &id;
        const NExpressionList &exps;
        
        NDecFunc(string id, NExpressionList &exps) : id{id}, exps{exps} {}
        NDecFunc(string id) : NDecFunc(id, NExpressionList(1, NULL));
}

#endif /* !NDECTYPE_HPP */