#ifndef NEXPBINARY_H
#define NEXPBINARY_H

#include <string>
#include "NExpression.hpp"
#include "enums.hpp"

using std::string;

class NExpBinary : public NExpression {    
    public:
        const NExpression &lhs;
        const NExpression &rhs;
        NExpOp op;
        NExpBinary(const NExpression &lhs, const NExpression &rhs, NExpOp op) : lhs{lhs}, rhs{rhs}, op{op} {}
};

#endif /* !NEXPBINARY_H */