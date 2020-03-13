#ifndef NARRAY_HPP
#define NARRAY_HPP

#include "../../abstractDispatcher.hpp"

#include "NType.hpp"

class NTypeArray : public NType {
    public:
        const NExpLiteral &intLiteral;
        const NType &type;
        NTypeArray(const NExpLiteral &intLiteral, const NType &type) : intLiteral{intLiteral}, type{type} {}

        void accept(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NARRAY_HPP */