#include <iostream>
#include "symbolPhase/symbolPhase.hpp"

using std::cout;
using std::endl;

void initSymTable();

void SymbolPhase::dispatch(const NProgram &program) const {
    currSymTable = new SymbolTable();
    cout << "{"; numTabs++;
    initSymTable();
    for(const auto &dec : program.topdecs) {
        dec->accept(*this);
    }
    numTabs--; cout << "}" << endl;
}

//helpers
void initSymTable() {
    NAbstractAstNode *node = new NTypeIdentifier("int");
    currSymTable->hashMap["int"] = std::make_pair(SymbolKind::SLocal, node);
}