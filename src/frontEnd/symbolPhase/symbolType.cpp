#include <iostream>
#include "symbolPhase/symbolHelper.hpp"

using std::cout;

void SymbolHelper::dispatch(const NType &type) {}
void SymbolHelper::dispatch(const NTypeArray &arrayType) {}
void SymbolHelper::dispatch(const NTypeIdentifier &idType) {}