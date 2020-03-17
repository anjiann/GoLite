#ifndef SYMBOLHelper_HPP
#define SYMBOLHelper_HPP

#include "../abstractDispatcher.hpp"
#include "symbolTable.hpp"
#include "symbolDefs.hpp"
#include "../tree.hpp"
#include "../ast/NAbstractAstNode.hpp"


class SymbolPhase;

using std::cout;
using std::endl;

class SymbolHelper {
    private:
        const AbstractDispatcher *const symbolDispatcher;

        SymbolTable *currSymTable = new SymbolTable();
        int numTabs = 0;
        std::vector<const NDecFunc*> funcDecs;

        // helpers
        string getTabs();
        string getIdSymKindStr(string id);
        string getSymKind(SymbolKind symbolKind);

        void initSymbolTable();

     public:
        SymbolHelper(AbstractDispatcher *symbolDispatcher) : symbolDispatcher{symbolDispatcher} {}

        void dispatch(const NProgram &program);

        void dispatch(const NDeclaration &dec);
        void dispatch(const NDecFunc &funcDec);
        void dispatch(const NDecType &typeDec);
        void dispatch(const NDecVar &varDec);

        void dispatch(const NStatement &stmt);
        void dispatch(const NStmtAssign &assignStmt);
        void dispatch(const NStmtBlock &blockStmt);
        void dispatch(const NStmtBreakContinue &breakContinueStmt);
        void dispatch(const NStmtDec &decStmt);
        void dispatch(const NStmtEmpty &emptyStmt);
        void dispatch(const NStmtExp &expstmt);
        void dispatch(const NStmtFor &forStmt);
        void dispatch(const NStmtIfElse &ifElseStmt);
        void dispatch(const NStmtIncDec &incDecStmt);
        void dispatch(const NStmtPrint &printStmt);
        void dispatch(const NStmtReturn &returnStmt);
        void dispatch(const NStmtSwitch &switchStmt);

        void dispatch(const NExpression &exp);
        void dispatch(const NExpBinary &binaryExp);
        void dispatch(const NExpBuiltin &unaryExp);
        void dispatch(const NExpFunc &funcExp);
        void dispatch(const NExpIdentifier &idExp);
        void dispatch(const NExpIndexer &indexerExp);
        void dispatch(const NExpLiteral &literalExp);
        void dispatch(const NExpUnary &unaryExp);
        void dispatch(const NExpCaseClause &caseClauseExp);
        void dispatch(const NExpSwitchCase &switchCaseExp);

        void dispatch(const NType &type);
        void dispatch(const NTypeArray &arrayType);
        void dispatch(const NTypeIdentifier &idType);
};

#endif