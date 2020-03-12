#ifndef NARRAY_HPP
#define NARRAY_HPP

#include "NType.hpp"

class NTypeArray : public NType {
    public:
        int size;
        const NType &type;
        NTypeArray(int size, const NType &type) : size{size}, type{type} {}
};

#endif /* !NARRAY_HPP */