#ifndef ABSTRACTDISPATCHER_HPP
#define ABSTRACTDISPATCHER_HPP

#include "vector"

//forward declarations instead of includes to avoid circular dependency whilst using visitor pattern
class NProgram;

class NDeclaration;
class NDecFunc;
class NDecType;
class NDecVar;

class NStatement;
class NStmtAssign;
class NStmtBlock;
class NStmtBreakContinue;
class NStmtDec;
class NStmtEmpty;
class NStmtExp;
class NStmtFor;
class NStmtIfElse;
class NStmtIncDec;
class NStmtPrint;
class NStmtReturn;
class NStmtSwitch; 

class NExpression;
class NExpArrIdentifier;
class NExpBinary;
class NExpBuiltin;
class NExpFunc;
class NExpIdentifier;
class NExpIndexer;
class NExpLiteral;
class NExpUnary;
class NExpCaseClause;
class NExpSwitchCase;

class NType;
class NTypeArray;
class NTypeIdentifier;

typedef std::vector<NDeclaration*> NDeclarationList;
typedef std::vector<NStatement*> NStatementList;

class AbstractDispatcher {
    public:
        virtual void dispatch(const NProgram &program) const = 0;

        virtual void dispatch(const NDeclaration &dec) const = 0;
        virtual void dispatch(const NDecFunc &funcDec) const = 0;
        virtual void dispatch(const NDecType &typeDec) const = 0;
        virtual void dispatch(const NDecVar &varDec) const = 0;

        virtual void dispatch(const NStatement &stmt) const = 0;
        virtual void dispatch(const NStmtAssign &assignStmt) const = 0;
        virtual void dispatch(const NStmtBlock &blockStmt) const = 0;
        virtual void dispatch(const NStmtBreakContinue &breakContinueStmt) const = 0;
        virtual void dispatch(const NStmtDec &decStmt) const = 0;
        virtual void dispatch(const NStmtEmpty &emptyStmt) const = 0;
        virtual void dispatch(const NStmtExp &expStmt) const = 0;
        virtual void dispatch(const NStmtFor &forStmt) const = 0;
        virtual void dispatch(const NStmtIfElse &ifElseStmt) const = 0;
        virtual void dispatch(const NStmtIncDec &incDecStmt) const = 0;
        virtual void dispatch(const NStmtPrint &printStmt) const = 0;
        virtual void dispatch(const NStmtReturn &returnStmt) const = 0;
        virtual void dispatch(const NStmtSwitch &switchStmt) const = 0;

        virtual void dispatch(const NExpression &exp) const = 0;
        virtual void dispatch(const NExpArrIdentifier &arrIdExp) const = 0;
        virtual void dispatch(const NExpBinary &binaryExp) const = 0;
        virtual void dispatch(const NExpBuiltin &unaryExp) const = 0;
        virtual void dispatch(const NExpFunc &funcExp) const = 0;
        virtual void dispatch(const NExpIdentifier &idExp) const = 0;
        virtual void dispatch(const NExpIndexer &indexerExp) const = 0;
        virtual void dispatch(const NExpLiteral &literalExp) const = 0;
        virtual void dispatch(const NExpUnary &unaryExp) const = 0;
        virtual void dispatch(const NExpCaseClause &caseClauseExp) const = 0;
        virtual void dispatch(const NExpSwitchCase &switchCaseExp) const = 0;

        virtual void dispatch(const NType &type) const = 0;
        virtual void dispatch(const NTypeArray &arrayType) const = 0;
        virtual void dispatch(const NTypeIdentifier &idType) const = 0;
};


#endif