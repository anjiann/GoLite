#ifndef NDECFUNC_HPP
#define NDECFUNC_HPP

#include <vector>
#include <string>
#include <memory>
#include "../../abstractDispatcher.hpp"

#include "../Statement/NStatement.hpp"
#include "NDeclaration.hpp"
#include "../Type/NType.hpp"
#include "NDecVar.hpp"

using std::string;

typedef std::vector<std::pair<string, std::shared_ptr<NType>>> ParamList;
class NDecFunc : public NDeclaration {
    public:
        const string id;
        const ParamList params;
        std::shared_ptr<NType> type;
        const NStatementList stmts;

        NDecFunc(const string &id, const ParamList &params, std::shared_ptr<NType> type, const NStatementList &stmts) 
            : id{id}, params{std::move(params)}, type{type}, stmts{std::move(stmts)} {}

        NDecFunc(NDecFunc &&src) = default;

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NDECFUNC_HPP */