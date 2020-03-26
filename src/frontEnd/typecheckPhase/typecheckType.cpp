#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;

void TypecheckDispatcher::dispatch(const NType &type) const {}
void TypecheckDispatcher::dispatch(const NTypeArray &arrayType) const {}

void TypecheckDispatcher::dispatch(const NTypeIdentifier &idType) const {}