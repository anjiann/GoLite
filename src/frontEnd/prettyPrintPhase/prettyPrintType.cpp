#include <iostream>
#include "prettyPrintPhase/prettyDispatcher.hpp"

using std::cout;

void PrettyDispatcher::dispatch(const NType &type) const {}
void PrettyDispatcher::dispatch(const NTypeArray &arrayType) const {}
void PrettyDispatcher::dispatch(const NTypeIdentifier &idType) const {}