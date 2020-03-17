#ifndef SYMBOLPHASE_HPP
#define SYMBOLPHASE_HPP

#include <iostream>
#include <vector>
#include "symbolPhaseHelper.hpp"


class SymbolPhase : public AbstractDispatcher {
    private:
        mutable SymbolPhaseHelper *symbolPhaseHelper = new SymbolPhaseHelper();
    public:
        SymbolPhase() {}

        virtual void dispatch(const NProgram &program) const { symbolPhaseHelper->dispatch(program); }

        virtual void dispatch(const NDeclaration &dec) const { symbolPhaseHelper->dispatch(dec); }
        virtual void dispatch(const NDecFunc &funcDec) const { symbolPhaseHelper->dispatch(funcDec); }
        virtual void dispatch(const NDecType &typeDec) const { symbolPhaseHelper->dispatch(typeDec); }
        virtual void dispatch(const NDecVar &varDec) const { symbolPhaseHelper->dispatch(varDec); }

        virtual void dispatch(const NStatement &stmt) const { symbolPhaseHelper->dispatch(stmt); }
        virtual void dispatch(const NStmtAssign &assignStmt) const { symbolPhaseHelper->dispatch(assignStmt); }
        virtual void dispatch(const NStmtBlock &blockStmt) const { symbolPhaseHelper->dispatch(blockStmt); }
        virtual void dispatch(const NStmtBreakContinue &breakContinueStmt) const { symbolPhaseHelper->dispatch(breakContinueStmt); }
        virtual void dispatch(const NStmtDec &decStmt) const { symbolPhaseHelper->dispatch(decStmt); }
        virtual void dispatch(const NStmtEmpty &emptyStmt) const { symbolPhaseHelper->dispatch(emptyStmt); }
        virtual void dispatch(const NStmtExp &expStmt) const { symbolPhaseHelper->dispatch(expStmt); }
        virtual void dispatch(const NStmtFor &forStmt) const { symbolPhaseHelper->dispatch(forStmt); }
        virtual void dispatch(const NStmtIfElse &ifElseStmt) const { symbolPhaseHelper->dispatch(ifElseStmt); }
        virtual void dispatch(const NStmtIncDec &incDecStmt) const { symbolPhaseHelper->dispatch(incDecStmt); }
        virtual void dispatch(const NStmtPrint &printStmt) const { symbolPhaseHelper->dispatch(printStmt); }
        virtual void dispatch(const NStmtReturn &returnStmt) const { symbolPhaseHelper->dispatch(returnStmt); }
        virtual void dispatch(const NStmtSwitch &switchStmt) const { symbolPhaseHelper->dispatch(switchStmt); }

        virtual void dispatch(const NExpression &exp) const { symbolPhaseHelper->dispatch(exp); }
        virtual void dispatch(const NExpBinary &binaryExp) const { symbolPhaseHelper->dispatch(binaryExp); }
        virtual void dispatch(const NExpBuiltin &unaryExp) const { symbolPhaseHelper->dispatch(unaryExp); }
        virtual void dispatch(const NExpFuncCall &funcCallExp) const { symbolPhaseHelper->dispatch(funcCallExp); }
        virtual void dispatch(const NExpIdentifier &idExp) const { symbolPhaseHelper->dispatch(idExp); }
        virtual void dispatch(const NExpIndexer &indexerExp) const { symbolPhaseHelper->dispatch(indexerExp); }
        virtual void dispatch(const NExpLiteral &literalExp) const { symbolPhaseHelper->dispatch(literalExp); }
        virtual void dispatch(const NExpUnary &unaryExp) const { symbolPhaseHelper->dispatch(unaryExp); }
        virtual void dispatch(const NExpCaseClause &caseClauseExp) const { symbolPhaseHelper->dispatch(caseClauseExp); }
        virtual void dispatch(const NExpSwitchCase &switchCaseExp) const { symbolPhaseHelper->dispatch(switchCaseExp); }

        virtual void dispatch(const NType &type) const { symbolPhaseHelper->dispatch(type); }
        virtual void dispatch(const NTypeArray &arrayType) const { symbolPhaseHelper->dispatch(arrayType); }
        virtual void dispatch(const NTypeIdentifier &idType) const { symbolPhaseHelper->dispatch(idType); }
};


#endif