#ifndef NDECFUNC_HPP
#define NDECFUNC_HPP

#include <string>
#include "../../abstractDispatcher.hpp"

#include "../Statement/NStatement.hpp"
#include "NDeclaration.hpp"
#include "../Type/NType.hpp"
#include "NDecVar.hpp"

using std::string;

class NDecFunc : public NDeclaration {
    public:
        string id;
        const NDecVarList &params;
        const NType &type;
        const NStatementList &stmts;

        NDecFunc(string id, const NDecVarList &params, const NType &type, const NStatementList &stmts) 
            : id{id}, params{params}, type{type}, stmts{stmts} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NDECFUNC_HPP */