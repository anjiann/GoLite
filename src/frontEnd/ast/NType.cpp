#include "ast/Type/NType.hpp"

const NType NType::intType = NType("int");
const NType NType::floatType = NType("float64");
const NType NType::runeType = NType("rune");
const NType NType::boolType = NType("bool");
const NType NType::stringType = NType("string");
const NType NType::inferType = NType("<infer>");