#ifndef NSTATEMENT_H
#define NSTATEMENT_H

#include <vector>
#include "../NAstNode.hpp"

class NStatement : public NAstNode {
    public:
        int lineno;

        NStatement() {}
        NStatement(int lineno) : lineno{lineno} {}
};

typedef std::vector<NStatement*> NStatementList;


#endif /* !NSTATEMENT_H */