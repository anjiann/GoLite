#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;

void TypecheckDispatcher::dispatch(const NProgram &program) const {
    for(const auto &dec : program.topdecs) {
        dec->accept(*this);
    }
}