#ifndef NEXPLITERAL_H
#define NEXPLITERAL_H

#include "NExpression.hpp"
#include "../../abstractDispatcher.hpp"

class NExpLiteral : public NExpression {    
    public:
        strin literal; //TODO have literal values be returned as string from lexer


        NExpLiteral(string literal, ExpLiteralKind kind) : literal{literal} {}

        void dispatch(const AbstractDispatcher &dispatcher) {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPLITERAL_H */