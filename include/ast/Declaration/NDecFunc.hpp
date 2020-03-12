#ifndef NDECFUNC_HPP
#define NDECFUNC_HPP

#include <string>

#include "../Statement/NStatement.hpp"
#include "NDeclaration.hpp"
#include "../Type/NType.hpp"
#include "NDecVar.hpp"

using std::string;

class NDecFunc : NDeclaration {
    public:
        string id;
        const NDecVarList &args;
        const NType &type;
        const NStatementList &stmts;

        NDecFunc(string id, const NDecVarList &args, const NType &type, const NStatementList &stmts) 
            : id{id}, args{args}, type{type}, stmts{stmts} {}

};

#endif /* !NDECFUNC_HPP */