#include "symbolPhase/symbolHelper.hpp"

bool SymbolHelper::isBaseType(string id) {
    for(const auto &baseType : baseTypes) {
        if(baseType == id) {
            return true;
        }
    }
    return false;
}

bool SymbolHelper::isBaseConstant(string id) {
    for(const auto &baseConstant : baseConstants) {
        if(baseConstant == id) {
            return true;
        }
    }
    return false;
}