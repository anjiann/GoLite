#ifndef NSTMTINCDEC_H
#define NSTMTINCDEC_H

class NStmtIncDec {
    public:
        string id;
        bool isIncrement;

        NStmtIncDec(string id, bool isIncrement) : id{id}, isIncrement{isIncrement} {}
}

#endif /* !NSTMTINCDEC_H */