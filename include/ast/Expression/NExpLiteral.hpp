#ifndef NEXPLITERAL_H
#define NEXPLITERAL_H

#include "NExpression.hpp"

template<typename T>
class NExpLiteral : NExpression {    
    public:
        T literal;

        NExpLiteral(T literal) : literal{literal} {}
};

#endif /* !NEXPLITERAL_H */