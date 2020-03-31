#ifndef SYMBOLPHASE_HPP
#define SYMBOLPHASE_HPP

#include "symbolHelper.hpp"
#include "memory"

class SymbolDispatcher : public AbstractDispatcher {
    private:
        std::unique_ptr<SymbolHelper> const symbolHelper { new SymbolHelper(this) };

    public:
        SymbolDispatcher() {}

        virtual void dispatch(const NProgram &program) const { symbolHelper->dispatch(program); }

        virtual void dispatch(const NDeclaration &dec) const { symbolHelper->dispatch(dec); }
        virtual void dispatch(const NDecFunc &funcDec) const { symbolHelper->dispatch(funcDec); }
        virtual void dispatch(const NDecType &typeDec) const { symbolHelper->dispatch(typeDec); }
        virtual void dispatch(const NDecVar &varDec) const { symbolHelper->dispatch(varDec); }

        virtual void dispatch(const NStatement &stmt) const { symbolHelper->dispatch(stmt); }
        virtual void dispatch(const NStmtAssign &assignStmt) const { symbolHelper->dispatch(assignStmt); }
        virtual void dispatch(const NStmtBlock &blockStmt) const { symbolHelper->dispatch(blockStmt); }
        virtual void dispatch(const NStmtBreakContinue &breakContinueStmt) const { symbolHelper->dispatch(breakContinueStmt); }
        virtual void dispatch(const NStmtDec &decStmt) const { symbolHelper->dispatch(decStmt); }
        virtual void dispatch(const NStmtEmpty &emptyStmt) const { symbolHelper->dispatch(emptyStmt); }
        virtual void dispatch(const NStmtExp &expStmt) const { symbolHelper->dispatch(expStmt); }
        virtual void dispatch(const NStmtFor &forStmt) const { symbolHelper->dispatch(forStmt); }
        virtual void dispatch(const NStmtIfElse &ifElseStmt) const { symbolHelper->dispatch(ifElseStmt); }
        virtual void dispatch(const NStmtIncDec &incDecStmt) const { symbolHelper->dispatch(incDecStmt); }
        virtual void dispatch(const NStmtPrint &printStmt) const { symbolHelper->dispatch(printStmt); }
        virtual void dispatch(const NStmtReturn &returnStmt) const { symbolHelper->dispatch(returnStmt); }
        virtual void dispatch(const NStmtSwitch &switchStmt) const { symbolHelper->dispatch(switchStmt); }

        virtual void dispatch(const NExpression &exp) const { symbolHelper->dispatch(exp); }
        virtual void dispatch(const NExpArrIdentifier &arrIdExp) const { symbolHelper->dispatch(arrIdExp); }
        virtual void dispatch(const NExpBinary &binaryExp) const { symbolHelper->dispatch(binaryExp); }
        virtual void dispatch(const NExpBuiltin &unaryExp) const { symbolHelper->dispatch(unaryExp); }
        virtual void dispatch(const NExpFunc &funcExp) const { symbolHelper->dispatch(funcExp); }
        virtual void dispatch(const NExpIdentifier &idExp) const { symbolHelper->dispatch(idExp); }
        virtual void dispatch(const NExpIndexer &indexerExp) const { symbolHelper->dispatch(indexerExp); }
        virtual void dispatch(const NExpLiteral &literalExp) const { symbolHelper->dispatch(literalExp); }
        virtual void dispatch(const NExpUnary &unaryExp) const { symbolHelper->dispatch(unaryExp); }
        virtual void dispatch(const NExpCaseClause &caseClauseExp) const { symbolHelper->dispatch(caseClauseExp); }
        virtual void dispatch(const NExpSwitchCase &switchCaseExp) const { symbolHelper->dispatch(switchCaseExp); }

        virtual void dispatch(const NType &type) const { symbolHelper->dispatch(type); }
        virtual void dispatch(const NTypeArray &arrayType) const { symbolHelper->dispatch(arrayType); }
        virtual void dispatch(const NTypeIdentifier &idType) const { symbolHelper->dispatch(idType); }
};


#endif