#include <iostream>
#include "prettyPrintPhase/prettyPrintPhase.hpp"

using std::cout;
using std::endl;

void PrettyPrintPhase::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}
void PrettyPrintPhase::dispatch(const NDecFunc &funcDec) const {}
void PrettyPrintPhase::dispatch(const NDecType &typeDec) const {}
void PrettyPrintPhase::dispatch(const NDecVar &varDec) const {
    cout << "in var dec :)" << endl;
}