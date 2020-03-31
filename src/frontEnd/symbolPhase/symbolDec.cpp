#include <iostream>
#include <string>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;
using std::cerr;
using std::string;

void SymbolHelper::dispatch(const NDeclaration &dec) {
    dec.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NDecFunc &funcDec) {
    funcDecs.push_back(&funcDec);
    std::shared_ptr<Symbol> funcSym { new FuncSymbol(funcDec.id, funcDec) };
    currSymTable->insertSymbol(funcDec.id, funcSym);

    //func definition
    cout << tabs << *funcSym << " = (";
    string separator = "";
    for(const auto &param : funcDec.params) {
        cout << separator;

        param->type.accept(*symbolDispatcher);
        separator = ", ";
    }
    cout << ") -> ";
    if(funcDec.type.id == NType::inferType) {
        cout << "void";
    }
    else {
        funcDec.type.accept(*symbolDispatcher);
    }
    cout << endl;

    //func body
    cout << tabs++ << "{" << endl;
    scopeSymbolTable();
    for(const auto &param : funcDec.params) {
        param->accept(*symbolDispatcher);
    }
    for(const auto &stmt : funcDec.stmts) {
        stmt->accept(*symbolDispatcher);
    }
    unscopeSymbolTable();
    cout << --tabs << "}" << endl;
}

// type t1 t2
void SymbolHelper::dispatch(const NDecType &typeDec) {    
    std::shared_ptr<Symbol> typeSym { new TypeSymbol(typeDec.id, typeDec.type) };
    currSymTable->insertSymbol(typeDec.id, typeSym);

    //print to console 
    cout << tabs << *typeSym << " = ";
    cout << typeDec.id << " -> ";

    typeDec.type.accept(*symbolDispatcher);
    cout << endl;
}

void SymbolHelper::dispatch(const NDecVar &varDec) {
    for(const auto &expId : varDec.lhs) {
        std::shared_ptr<Symbol> localSym { new LocalSymbol(expId->name, *expId) };
        currSymTable->insertSymbol(expId->name, localSym);
        expId->symbol = localSym;

        //print to console
        cout << tabs << *localSym << " = " << expId->type;
        expId->accept(*symbolDispatcher);
        cout << endl;
    }
}