#ifndef NEXPLITERAL_H
#define NEXPLITERAL_H
#include "../../abstractDispatcher.hpp"

#include "NExpression.hpp"
#include "enums.hpp"

class NExpLiteral : public NExpression {    
    public:
        string literal; //TODO have literal values be returned as string from lexer
        NExpLiteralKind kind;

        NExpLiteral(string literal, NExpLiteralKind kind) : literal{literal}, kind{kind} {}

        void accept(const AbstractDispatcher &dispatcher) const override {
            dispatcher.dispatch(*this);
        }
};

#endif /* !NEXPLITERAL_H */