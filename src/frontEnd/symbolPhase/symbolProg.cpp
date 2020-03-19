#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::initPrimitives() {
    NAbstractAstNode *node = new NTypeIdentifier("int");
    currSymTable->insertSymbol("int", SymbolKind::SType, node);
    cout << getTabs() << getIdSymKindStr("int") << " = " << endl;

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

    cout << getTabs() << getIdSymKindStr("float64") << " = " << "float64" << endl;
    cout << getTabs() << getIdSymKindStr("bool") << " = " << "bool" << endl;
    cout << getTabs() << getIdSymKindStr("string") << " = " << "string" << endl;
    cout << getTabs() << getIdSymKindStr("true") << " = " << "bool" << endl;
    cout << getTabs() << getIdSymKindStr("false") << " = " << "bool" << endl;
}

void SymbolHelper::dispatch(const NProgram &program) {
    cout << "{" << endl; 
    numTabs++;
    initPrimitives();
    currSymTable = currSymTable->scopeSymbolTable();

    cout << getTabs() << "{" << endl;
    numTabs++;
    for(const auto &dec : program.topdecs) {
        dec->accept(*symbolDispatcher);
    }
    numTabs--;
    cout << getTabs() << "}" << endl;

    numTabs--; 
    cout << "}" << endl;
}