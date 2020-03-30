#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::initPrimitives() {
    const Symbol *intSym = currSymTable->insertSymbol("int", new TypeSymbol("int", NType::intType));
    const Symbol *floatSym = currSymTable->insertSymbol("float", new TypeSymbol("float", NType::floatType));
    const Symbol *boolSym = currSymTable->insertSymbol("bool", new TypeSymbol("bool", NType::boolType));
    const Symbol *runeSym = currSymTable->insertSymbol("rune", new TypeSymbol("rune", NType::runeType));
    const Symbol *stringSym = currSymTable->insertSymbol("string", new TypeSymbol("string", NType::stringType));
    const Symbol *trueSym = currSymTable->insertSymbol("true", new ConstantSymbol("true", NType::boolType));
    const Symbol *falseSym = currSymTable->insertSymbol("false", new ConstantSymbol("false", NType::boolType));

    cout << tabs << *intSym << " = " << NType::intType << endl;
    cout << tabs << *floatSym << " = " << NType::floatType << endl;;
    cout << tabs << *boolSym << " = " << NType::boolType << endl;
    cout << tabs << *runeSym << " = " << NType::runeType << endl;
    cout << tabs << *stringSym << " = " << NType::stringType << endl;
    cout << tabs << *trueSym << " = " << NType::boolType << endl;
    cout << tabs << *falseSym << " = " << NType::boolType << endl;
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