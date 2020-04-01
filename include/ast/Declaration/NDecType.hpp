#ifndef NDECTYPE_HPP
#define NDECTYPE_HPP

#include <string>
#include <memory>
#include "../../abstractDispatcher.hpp"

#include "NDeclaration.hpp"
#include "../Type/NType.hpp"

using std::string;

class NDecType : public NDeclaration {
    public:
        string id;
        std::shared_ptr<NType> type;
        
        NDecType(const string &id, std::shared_ptr<NType> type) : id{id}, type{type} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NDECTYPE_HPP */