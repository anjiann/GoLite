#ifndef NSTMTINCDEC_H
#define NSTMTINCDEC_H

#include "NStatement.hpp"

class NStmtIncDec : public NStatement {
    public:
        string id;
        bool isIncrement;

        NStmtIncDec(string id, bool isIncrement) : id{id}, isIncrement{isIncrement} {}
};

#endif /* !NSTMTINCDEC_H */