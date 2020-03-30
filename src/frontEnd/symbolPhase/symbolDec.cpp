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
    const Symbol *funcSym = currSymTable->insertSymbol(funcDec.id, new FuncSymbol(funcDec.id, funcDec));

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
    currSymTable = currSymTable->scopeSymbolTable();
    for(const auto &param : funcDec.params) {
        param->accept(*symbolDispatcher);
    }
    for(const auto &stmt : funcDec.stmts) {
        stmt->accept(*symbolDispatcher);
    }
    cout << --tabs << "}" << endl;

    currSymTable = currSymTable->parent;
}

// type t1 t2
void SymbolHelper::dispatch(const NDecType &typeDec) {    
    const Symbol *typeSym = currSymTable->insertSymbol(typeDec.id, new TypeSymbol(typeDec.id, typeDec.type));

    //print to console 
    cout << tabs << *typeSym << " = ";
    cout << typeDec.id << " -> ";

    typeDec.type.accept(*symbolDispatcher);
    cout << endl;
}

void SymbolHelper::dispatch(const NDecVar &varDec) {
    for(const auto &expId : varDec.lhs) {
        const Symbol *localSym = currSymTable->insertSymbol(expId->name, new LocalSymbol(expId->name, *expId));
        expId->symbol = localSym;

        //print to console
        cout << tabs << *localSym << " = " << expId->type;
        expId->accept(*symbolDispatcher);
        cout << endl;
    }
}