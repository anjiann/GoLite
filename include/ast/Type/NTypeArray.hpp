#ifndef NARRAY_HPP
#define NARRAY_HPP

#include <string>
#include "../../abstractDispatcher.hpp"

#include "NType.hpp"

class NTypeArray : public NType {
    public:
        int size;
        const NType &type;
        NTypeArray(int size, const NType &type) : size{size}, type{type} {}

        void accept(const AbstractDispatcher &dispatcher) const override{
            dispatcher.dispatch(*this);
        }
};

#endif /* !NARRAY_HPP */