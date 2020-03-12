#ifndef PRETTYPRINTER_H
#define PRETTYPRINTER_H

#include "ast/NProgram.hpp"

class PrettyPrinter {
    public:
        void visit(const NProgram &program);

};

#endif /* !PRETTYPRINTER_H */