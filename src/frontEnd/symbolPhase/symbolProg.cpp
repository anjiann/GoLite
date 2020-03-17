#include <iostream>
#include "symbolPhase/symbolPhaseHelper.hpp"

using std::cout;
using std::endl;

// void SymbolPhase::initSymbolTable() {
//     NAbstractAstNode *node = new NTypeIdentifier("int");
//     currSymTable->hashMap["int"] = {SymbolKind::SType, node};

//     node = new NTypeIdentifier("float64");
//     currSymTable->hashMap["float64"] = {SymbolKind::SType, node};

//     node = new NTypeIdentifier("bool");
//     currSymTable->hashMap["bool"] = {SymbolKind::SType, node};

//     node = new NTypeIdentifier("rune");
//     currSymTable->hashMap["rune"] = {SymbolKind::SType, node};

//     node = new NTypeIdentifier("string");
//     currSymTable->hashMap["string"] = {SymbolKind::SType, node};

//     node = new NTypeIdentifier("true");
//     currSymTable->hashMap["true"] = {SymbolKind::SConstant, node};

//     node = new NTypeIdentifier("false");
//     currSymTable->hashMap["false"] = {SymbolKind::SConstant, node};

//     cout << getTabs() << "int[type] = int" << endl;
//     cout << getTabs() << "float64[type] = float64" << endl;
//     cout << getTabs() << "bool[type] = bool" << endl;
//     cout << "string[type] = string" << endl;
//     cout << "true[constant] = bool" << endl;
//     cout << "false[constant] = bool" << endl;
// }

void SymbolPhaseHelper::dispatch(const NProgram &program) {
    // cout << "{"; numTabs++;
    // initSymbolTable();
    // for(const auto &dec : program.topdecs) {
    //     dec->accept(*this);
    // }
    // numTabs--; cout << "}" << endl;
}