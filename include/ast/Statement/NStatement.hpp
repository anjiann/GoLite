#ifndef NSTATEMENT_H
#define NSTATEMENT_H

typedef vector<NStatement*> NStatementList;

class NStatement {
    public:
        int lineno;

        NStatement(int lineno) : lineno{lineno} {}
}

#endif /* !NSTATEMENT_H */