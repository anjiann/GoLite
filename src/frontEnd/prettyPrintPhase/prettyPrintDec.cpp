#include <iostream>
#include "prettyPrintPhase/prettyDispatcher.hpp"

using std::cout;
using std::endl;

void PrettyDispatcher::dispatch(const NDeclaration &dec) const {
    dec.accept(*this);
}
void PrettyDispatcher::dispatch(const NDecFunc &funcDec) const {
    cout << "func " << funcDec.id << "(" << ") ";
}
void PrettyDispatcher::dispatch(const NDecType &typeDec) const {

}
void PrettyDispatcher::dispatch(const NDecVar &varDec) const {
    cout << "in var dec :)" << endl;
}