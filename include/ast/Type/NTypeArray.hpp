#ifndef NARRAY_HPP
#define NARRAY_HPP

#include <string>
#include <vector>
#include <memory>
#include "../../abstractDispatcher.hpp"

#include <memory>
#include "../Expression/NExpression.hpp"
#include "NType.hpp"

class NTypeArray : public NType {
    public:
        int size = 0;
        std::shared_ptr<NType> type;
        
        NTypeArray(int size, std::shared_ptr<NType> type) : size{size}, type{type} {
            id = "[" + std::to_string(size) + "]";
        }
        
        NTypeArray(const NTypeArray &src) = default;
        NTypeArray(NTypeArray &&src) = default;
        
        void accept(const AbstractDispatcher &dispatcher) const override{
            dispatcher.dispatch(*this);
        }
};

#endif /* !NARRAY_HPP */