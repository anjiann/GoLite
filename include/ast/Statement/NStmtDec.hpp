#ifndef NSTMTDEC_H
#define NSTMTDEC_H

#include "NStatement.hpp"

class NStmtDec : NStatement {
    public:
        NDeclaration *dec;

        NStmtDec(NDeclaration *dec) : dec{dec} {}
}

#endif /* !NSTMTDEC_H */