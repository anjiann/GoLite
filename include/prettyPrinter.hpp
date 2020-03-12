#ifndef PRETTYPRINTER_H
#define PRETTYPRINTER_H

class NProgram;

class PrettyPrinter {
    public:
        void visit(const NProgram &program);

};

#endif /* !PRETTYPRINTER_H */