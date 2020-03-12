#ifndef NASTNODE_HPP
#define NASTNODE_HPP

class NAstNode {
    virtual void accept(const PrettyPrinter &prettyPrinter) {
        prettyPrinter.visit(*this);
    }
}

#endif