#ifndef NSTATEMENT_H
#define NSTATEMENT_H

class NStatement {
    public:
        int lineno;

        NStatement(int lineno) : lineno{lineno} {}
}

#endif /* !NSTATEMENT_H */