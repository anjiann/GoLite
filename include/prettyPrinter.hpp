#ifndef PRETTYPRINTER_H
#define PRETTYPRINTER_H

#include "abstractDispatcher.hpp"

class NProgram;

class PrettyPrinter : public AbstractDispatcher {
    public:
        void visit(const NProgram &program);

};

#endif /* !PRETTYPRINTER_H */