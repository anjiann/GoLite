#ifndef NDECFUNC_HPP
#define NDECFUNC_HPP

#include <string>

#include "NStatements"
#include "typedefs.hpp"

using std::string;

class NDecFunc : NDeclaration {
    public:
        string id;
        const NDecVarList &args;
        const NType &type;
        const NStatements &block;

        NDecFunc(string id, const NDecVarList &args, const NType &type, const NStatements &stmts) 
            : id{id}, args{args}, exps{exps}, block{block} {}

}

#endif /* !NDECFUNC_HPP */