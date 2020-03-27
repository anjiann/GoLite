#ifndef NTYPE_HPP
#define NTYPE_HPP

#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

class NType : public NAbstractAstNode {
    public:
        static NType intType = NType("int");
        static NType floatType = NType("float64");
        static NType boolType = NType("bool");
        static NType runeType = NType("rune");
        static NType stringType = NType("string");
        static NType inferType = NType();

        string id;

        NType() : id{"<infer>"} {}
        NType(string id) : id{id} {} 

        bool operator==(const NType &rhs) {
            return this->id == rhs.id;
        }

        bool operator!=(const NType &rhs) {
            return this->id != rhs.id;
        }

        inline std::ostream &operator<<(std::ostream &os, const NType &type) {
            os << type.id;
        }

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};



#endif /* !NTYPE_HPP */