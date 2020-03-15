#include <iostream>
#include "prettyPrintPhase/prettyPrintPhase.hpp"

using std::cout;

void PrettyPrintPhase::dispatch(const NType &type) const {}
void PrettyPrintPhase::dispatch(const NTypeArray &arrayType) const {}
void PrettyPrintPhase::dispatch(const NTypeIdentifier &idType) const {}