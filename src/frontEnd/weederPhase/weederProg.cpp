#include "weederPhase/weederDispatcher.hpp"

void WeederDispatcher::dispatch(const NProgram &program) const {
    for(const auto &dec : program.topdecs) {
        dec->accept(*this);
    }
}
