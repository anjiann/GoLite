#ifndef NTYPE_HPP
#define NTYPE_HPP

#include <iostream>
#include <string>
#include <regex>
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
        NType(const string &id) : id{id} {} 

        inline NType &operator=(const NType &rhs) {
            this->id = rhs.id;
            return *this;
        }

        virtual void accept(const AbstractDispatcher &dispatcher) const {
            dispatcher.dispatch(*this);
        }
};

inline string operator+(const string &lhs, const NType &rhs) {
    return lhs + rhs.id;
}

inline string operator+(const NType &lhs, const string &rhs) {
    return lhs.id + rhs;
}

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
    std::cout << "NType.hpp, lhs: " << lhs.id << ", rhs: " << rhs.id << std::endl;
    return lhs.id != rhs.id;
}

inline bool operator!=(const NType &lhs, NType &rhs) {
    std::cout << "NType.hpp, lhs: " << lhs.id << ", rhs: " << rhs.id << std::endl;
    return lhs.id != rhs.id;
}

inline bool operator!=(NType &lhs, const NType &rhs) {
    std::cout << "NType.hpp, lhs: " << lhs.id << ", rhs: " << rhs.id << std::endl;
    return lhs.id != rhs.id;
}

inline std::ostream &operator<<(std::ostream &os, const NType &type) {
    os << type.id;
    return os;
}

inline bool isInteger(const NType &type) { return type == NType::intType; }
inline bool isFloat(const NType &type) { return type == NType::floatType; }
inline bool isRune(const NType &type) { return type == NType::runeType; }
inline bool isBoolean(const NType &type) { return type == NType::boolType; }
inline bool isString(const NType &type) { return type == NType::stringType; }

inline bool isNumeric(const NType &type) { return isInteger(type) || isRune(type)|| isFloat(type); }
inline bool isOrdered(const NType &type) { return isNumeric(type) || isString(type); }
inline bool isBaseType(const NType &type) { return isNumeric(type) || isString(type) || isBoolean(type); }
inline bool isArray(const NType &type) { 
    std::regex const e("[(.*)](.+)");
    if(regex_match(type.id, e)) {
        return true;
    }
    return false;
}

#endif /* !NTYPE_HPP */