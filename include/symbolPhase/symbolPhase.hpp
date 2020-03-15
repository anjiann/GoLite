#ifndef SYMBOLPHASE_HPP
#define SYMBOLPHASE_HPP

#include <vector>
#include "../abstractDispatcher.hpp"
#include "symbolTable.hpp"
#include "../tree.hpp"


class SymbolPhase : public AbstractDispatcher {
    private:
        mutable SymbolTable *currSymTable = NULL;
        mutable std::vector<const NDecFunc*> funcDecs;

    public:
        SymbolPhase() {}

        void dispatch(const NProgram &program) const override {
            currSymTable = new SymbolTable();
            for(const auto &dec : program.topdecs) {
                dec->accept(*this);
            }
        }

        void dispatch(const NDeclaration &dec) const override;
        void dispatch(const NDecFunc &funcDec) const override;
        void dispatch(const NDecType &typeDec) const override;
        void dispatch(const NDecVar &varDec) const override;

        void dispatch(const NStatement &stmt) const override;
        void dispatch(const NStmtAssign &assignStmt) const override;
        void dispatch(const NStmtBlock &blockStmt) const override;
        void dispatch(const NStmtBreakContinue &breakContinueStmt) const override;
        void dispatch(const NStmtDec &decStmt) const override;
        void dispatch(const NStmtEmpty &emptyStmt) const override;
        void dispatch(const NStmtExp &expstmt) const override;
        void dispatch(const NStmtFor &forStmt) const override;
        void dispatch(const NStmtIfElse &ifElseStmt) const override;
        void dispatch(const NStmtIncDec &incDecStmt) const override;
        void dispatch(const NStmtPrint &printStmt) const override;
        void dispatch(const NStmtReturn &returnStmt) const override;
        void dispatch(const NStmtSwitch &switchStmt) const override;

        void dispatch(const NExpression &exp) const override;
        void dispatch(const NExpBinary &binaryExp) const override;
        void dispatch(const NExpBuiltin &unaryExp) const override;
        void dispatch(const NExpFuncCall &funcCallExp) const override;
        void dispatch(const NExpIdentifier &idExp) const override;
        void dispatch(const NExpIndexer &indexerExp) const override;
        void dispatch(const NExpLiteral &literalExp) const override;
        void dispatch(const NExpUnary &unaryExp) const override;
        void dispatch(const NExpCaseClause &caseClauseExp) const override;
        void dispatch(const NExpSwitchCase &switchCaseExp) const override;

        void dispatch(const NType &type) const override;
        void dispatch(const NTypeArray &arrayType) const override;
        void dispatch(const NTypeIdentifier &idType) const override;
};


#endif