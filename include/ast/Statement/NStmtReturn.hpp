#ifndef NSTMTRETURN_H
#define NSTMTRETURN_H

#include "NExpression.hpp"

class NStmtReturn : NStatement {
    public:
        const NExpression &exp;
        NStmtReturn(const NExpression &exp) : exp{exp} {}
}

#endif /* !NSTMTRETURN_H */