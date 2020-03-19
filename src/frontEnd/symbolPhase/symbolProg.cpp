#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::initPrimitives() {
    NAbstractAstNode *node = new NTypeIdentifier("int");
    currSymTable->insertSymbol("int", SymbolKind::SType, node);

    node = new NTypeIdentifier("float64");
    currSymTable->insertSymbol("float64", SymbolKind::SType, node);

    node = new NTypeIdentifier("bool");
    currSymTable->insertSymbol("bool", SymbolKind::SType, node);

    node = new NTypeIdentifier("rune");
    currSymTable->insertSymbol("rune", SymbolKind::SType, node);

    node = new NTypeIdentifier("string");
    currSymTable->insertSymbol("string", SymbolKind::SType, node);

    node = new NTypeIdentifier("true");
    currSymTable->insertSymbol("true", SymbolKind::SConstant, node);

    node = new NTypeIdentifier("false");
    currSymTable->insertSymbol("false", SymbolKind::SConstant, node);

    cout << tabs << getIdSymKindStr("int") << " = " << endl;
    cout << tabs << getIdSymKindStr("float64") << " = " << "float64" << endl;
    cout << tabs << getIdSymKindStr("bool") << " = " << "bool" << endl;
    cout << tabs << getIdSymKindStr("string") << " = " << "string" << endl;
    cout << tabs << getIdSymKindStr("true") << " = " << "bool" << endl;
    cout << tabs << getIdSymKindStr("false") << " = " << "bool" << endl;
}

void SymbolHelper::dispatch(const NProgram &program) {
    cout << tabs++ << "{" << endl; 
    initPrimitives();
    currSymTable = currSymTable->scopeSymbolTable();

    cout << tabs++ << "{" << endl;
    for(const auto &dec : program.topdecs) {
        dec->accept(*symbolDispatcher);
    }
    cout << --tabs << "}" << endl;

    cout << --tabs << "}" << endl;
}