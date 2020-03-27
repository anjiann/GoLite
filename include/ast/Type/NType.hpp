#ifndef NTYPE_HPP
#define NTYPE_HPP

#include <string>
#include "../../abstractDispatcher.hpp"

#include "../NAbstractAstNode.hpp"

using std::string;

class NType : public NAbstractAstNode {
    public:
        string id;
        static const NType intType;
        static const NType floatType;
        static const NType runeType;
        static const NType boolType;
        static const NType stringType;
        static const NType inferType;

        NType() : id{inferType.id} {}
        NType(string id) : id{id} {} 

        inline NType &operator=(const NType &rhs) {
            this->id = rhs.id;
            return *this;
        }

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

inline bool operator==(const NType &lhs, const NType &rhs) {
    return lhs.id == rhs.id;
}

inline bool operator==(const NType &lhs, NType &rhs) {
    return lhs.id == rhs.id;
}

inline bool operator==(NType &lhs, const NType &rhs) {
    return lhs.id == rhs.id;
}

inline bool operator!=(const NType &lhs, const NType &rhs) {
    return lhs.id != rhs.id;
}

inline bool operator!=(const NType &lhs, NType &rhs) {
    return lhs.id != rhs.id;
}

inline bool operator!=(NType &lhs, const NType &rhs) {
    return lhs.id != rhs.id;
}

inline std::ostream &operator<<(std::ostream &os, const NType &type) {
    os << type.id;
    return os;
}

#endif /* !NTYPE_HPP */