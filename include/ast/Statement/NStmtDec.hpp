#ifndef NSTMTDEC_H
#define NSTMTDEC_H

#include "NStatement.hpp"

class NStmtDec : NStatement {
    public:
        const NDeclaration &dec;

        NStmtDec(const NDeclaration &dec) : dec{dec} {}
}

#endif /* !NSTMTDEC_H */