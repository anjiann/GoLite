#ifndef MAIN_H
#define MAIN_H

#include "abstractDispatcher.hpp"
#include "weederPhase/weederDispatcher.hpp"
#include "prettyPrintPhase/prettyDispatcher.hpp"
#include "symbolPhase/symbolDispatcher.hpp"
#include "typecheckPhase/typecheckDispatcher.hpp"
#include "tree.hpp"

int g_tokens;
NProgram *program;

#endif /* !MAIN_H */