#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::initPrimitives() {
    NAbstractAstNode *node = new NType("int");
    currSymTable->insertSymbol("int", SymbolKind::SType, nullptr);

    node = new NType("float64");
    currSymTable->insertSymbol("float64", SymbolKind::SType, nullptr);

    node = new NType("bool");
    currSymTable->insertSymbol("bool", SymbolKind::SType, nullptr);

    node = new NType("rune");
    currSymTable->insertSymbol("rune", SymbolKind::SType, nullptr);

    node = new NType("string");
    currSymTable->insertSymbol("string", SymbolKind::SType, nullptr);

    node = new NType("true");
    currSymTable->insertSymbol("true", SymbolKind::SConstant, nullptr);

    node = new NType("false");
    currSymTable->insertSymbol("false", SymbolKind::SConstant, nullptr);

    cout << tabs << "int" << "[" << SymbolKind::SType << "]" << " = " << "int" << endl;
    cout << tabs << "float64" << "[" << SymbolKind::SType << "]" << " = " << "float64" << endl;
    cout << tabs << "bool" << "[" << SymbolKind::SType << "]" << " = " << "bool" << endl;
    cout << tabs << "string" << "[" << SymbolKind::SType << "]" << " = " << "string" << endl;
    cout << tabs << "true" << "[" << SymbolKind::SConstant << "]" << " = " << "bool" << endl;
    cout << tabs << "false" << "[" << SymbolKind::SConstant << "]" << " = " << "bool" << endl;
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