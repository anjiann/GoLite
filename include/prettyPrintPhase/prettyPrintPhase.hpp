#ifndef PRETTYPRINTPHASE_HPP
#define PRETTYPRINTPHASE_HPP

#include <iostream>
#include "abstractDispatcher.hpp"
#include "tree.hpp"

using std::cout;
using std::endl;

class PrettyPrintPhase : public AbstractDispatcher {
    public:
        PrettyPrintPhase() {}

        virtual void dispatch(const NProgram &program) const {
            cout << "package " << program.package << endl;
            for(const auto &dec : program.topdecs) {
                dec->accept(*this);
            }
        }

        virtual void dispatch(const NDeclarationList &topDecs) const {}
        virtual void dispatch(const NStatementList &stmts) const {}

        virtual void dispatch(const NDeclaration &dec) const;
        virtual void dispatch(const NDecFunc &funcDec) const;
        virtual void dispatch(const NDecType &typeDec) const;
        virtual void dispatch(const NDecVar &varDec) const;

        virtual void dispatch(const NStatement &stmt) const;
        virtual void dispatch(const NStmtAssign &assignStmt) const;
        virtual void dispatch(const NStmtBlock &blockStmt) const;
        virtual void dispatch(const NStmtBreakContinue &breakContinueStmt) const;
        virtual void dispatch(const NStmtDec &decStmt) const;
        virtual void dispatch(const NStmtEmpty &emptyStmt) const;
        virtual void dispatch(const NStmtExp &expstmt) const;
        virtual void dispatch(const NStmtFor &forStmt) const;
        virtual void dispatch(const NStmtIfElse &ifElseStmt) const;
        virtual void dispatch(const NStmtIncDec &incDecStmt) const;
        virtual void dispatch(const NStmtPrint &printStmt) const;
        virtual void dispatch(const NStmtReturn &returnStmt) const;
        virtual void dispatch(const NStmtSwitch &switchStmt) const;

        virtual void dispatch(const NExpression &exp) const;
        virtual void dispatch(const NExpBinary &binaryExp) const;
        virtual void dispatch(const NExpBuiltin &unaryExp) const;
        virtual void dispatch(const NExpFuncCall &funcCallExp) const;
        virtual void dispatch(const NExpIdentifier &idExp) const;
        virtual void dispatch(const NExpIndexer &indexerExp) const;
        virtual void dispatch(const NExpLiteral &literalExp) const;
        virtual void dispatch(const NExpUnary &unaryExp) const;
        virtual void dispatch(const NExpCaseClause &caseClauseExp) const;
        virtual void dispatch(const NExpSwitchCase &switchCaseExp) const;

        virtual void dispatch(const NType &type) const;
        virtual void dispatch(const NTypeArray &arrayType) const;
        virtual void dispatch(const NTypeIdentifier &idType) const;
};

#endif