#include <iostream>
#include "prettyPrintPhase/prettyDispatcher.hpp"

using std::cout;
using std::endl;

void PrettyDispatcher::dispatch(const NProgram &program) const {
    cout << "package " << program.package << endl;
    for(const auto &dec : program.topdecs) {
        dec->accept(*this);
    }
}