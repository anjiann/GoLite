#include <iostream>
#include "symbolPhase/symbolPhase.hpp"

using std::cout;

void SymbolPhase::dispatch(const NType &type) const {}
void SymbolPhase::dispatch(const NTypeArray &arrayType) const {}
void SymbolPhase::dispatch(const NTypeIdentifier &idType) const {}