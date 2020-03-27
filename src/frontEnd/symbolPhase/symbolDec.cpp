#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;
using std::cerr;

void SymbolHelper::dispatch(const NDeclaration &dec) {
    dec.accept(*symbolDispatcher);
}

void SymbolHelper::dispatch(const NDecFunc &funcDec) {
    funcDecs.push_back(&funcDec);
    currSymTable->insertSymbol(funcDec.id, SymbolKind::SFunction, &funcDec);

    Symbol *sym = currSymTable->getSymbol(funcDec.id);

    //func definition
    cout << tabs << sym->name << " [" << sym->kind << "]" << " = (";
    string separator = "";
    for(const auto &param : funcDec.params) {
        cout << separator;

        param->type.accept(*symbolDispatcher);
        separator = ", ";
    }
    cout << ") -> ";
    funcDec.type.accept(*symbolDispatcher);
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
    currSymTable->insertSymbol(typeDec.id, SymbolKind::SType, &typeDec.type);

    //print to console 
    Symbol *sym = currSymTable->getSymbol(typeDec.id);
    cout << tabs << sym->name << " [" << sym->kind << "]" << " = ";
    cout << sym->name << " -> ";

    sym->defNode->accept(*symbolDispatcher);
    cout << endl;
}

void SymbolHelper::dispatch(const NDecVar &varDec) {
    for(const auto &expId : varDec.lhs) {
        currSymTable->insertSymbol(expId->name, SymbolKind::SLocal, &varDec.type);
    }

    //print to console
    for(const auto &expId : varDec.lhs) {
        Symbol *sym = currSymTable->getSymbol(expId->name);
        cout << tabs << sym->name << " [" << sym->kind << "]" << " = ";
        sym->defNode->accept(*symbolDispatcher);
        cout << endl;
    }
}