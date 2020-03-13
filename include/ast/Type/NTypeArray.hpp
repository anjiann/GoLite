#ifndef NARRAY_HPP
#define NARRAY_HPP

#include "../../abstractDispatcher.hpp"

#include "NType.hpp"

class NTypeArray : public NType {
    public:
        int size;
        const NType &type;
        NTypeArray(int size, const NType &type) : size{size}, type{type} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NARRAY_HPP */