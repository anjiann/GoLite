#ifndef SYMBOLHELPER_HPP
#define SYMBOLHELPER_HPP

#include <ostream>
#include <string>
#include <vector>

#include "../abstractDispatcher.hpp"
#include "symbolTable.hpp"
#include "symbols/constantSymbol.hpp"
#include "symbols/funcSymbol.hpp"
#include "symbols/localSymbol.hpp"
#include "symbols/symbol.hpp"
#include "symbols/typeSymbol.hpp"

#include "symbolDefs.hpp"
#include "../tree.hpp"
#include "../ast/NAbstractAstNode.hpp"
#include "../tabs.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class SymbolHelper {
    private:
        const AbstractDispatcher *const symbolDispatcher;

        SymbolTable *currSymTable = new SymbolTable();
        std::vector<const NDecFunc*> funcDecs;
        Tabs tabs;

        vector<string> baseTypes { "int", "float64", "bool", "rune", "string", };
        vector<string> baseConstants { "true", "false" };

        void initPrimitives();

     public:
        SymbolHelper(AbstractDispatcher *symbolDispatcher) : symbolDispatcher{symbolDispatcher} {}
        ~SymbolHelper() {
            // delete symbolDispatcher;
            // delete currSymTable;
        }

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
        void dispatch(const NExpArrIdentifier &arrIdExp);
        void dispatch(const NExpBinary &binaryexp);
        void dispatch(const NExpBuiltin &unaryexp);
        void dispatch(const NExpFunc &funcexp);
        void dispatch(const NExpIdentifier &idexp);
        void dispatch(const NExpIndexer &indexerexp);
        void dispatch(const NExpLiteral &literalexp);
        void dispatch(const NExpUnary &unaryexp);
        void dispatch(const NExpCaseClause &caseClauseexp);
        void dispatch(const NExpSwitchCase &switchCaseexp);

        void dispatch(const NType &type);
        void dispatch(const NTypeArray &arrayType);
        void dispatch(const NTypeIdentifier &idType);
};

#endif