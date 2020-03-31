#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;
using std::endl;

void SymbolHelper::initPrimitives() {
    auto intSym = currSymTable->insertSymbol("int", std::shared_ptr<Symbol>(new TypeSymbol("int", NType::intType)));
    auto floatSym = currSymTable->insertSymbol("float", std::shared_ptr<Symbol>(new TypeSymbol("float", NType::floatType)));
    auto boolSym = currSymTable->insertSymbol("bool", std::shared_ptr<Symbol>(new TypeSymbol("bool", NType::boolType)));
    auto runeSym = currSymTable->insertSymbol("rune", std::shared_ptr<Symbol>(new TypeSymbol("rune", NType::runeType)));
    auto stringSym = currSymTable->insertSymbol("string", std::shared_ptr<Symbol>(new TypeSymbol("string", NType::stringType)));
    auto trueSym = currSymTable->insertSymbol("true", std::shared_ptr<Symbol>(new ConstantSymbol("true", NType::boolType)));
    auto falseSym = currSymTable->insertSymbol("false", std::shared_ptr<Symbol>(new ConstantSymbol("false", NType::boolType)));

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
    scopeSymbolTable();

    cout << tabs++ << "{" << endl;
    for(const auto &dec : program.topdecs) {
        dec->accept(*symbolDispatcher);
    }
    cout << --tabs << "}" << endl;

    unscopeSymbolTable();
    cout << --tabs << "}" << endl;
}