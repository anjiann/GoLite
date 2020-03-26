#ifndef SYMBOLDEFS_HPP
#define SYMBOLDEFS_HPP

#include <string>

enum class SymbolKind {
    SFunction,
    SFormal,
    SLocal,
    SType,
    SConstant
};

inline std::ostream &operator<<(std::ostream &os, const SymbolKind &kind) {
    std::string s;
    switch(kind) {
        case SymbolKind::SFunction: s = "function"; break;
        case SymbolKind::SFormal: s = "formal"; break;
        case SymbolKind::SLocal: s = "variable"; break;
        case SymbolKind::SType: s = "type"; break;
        case SymbolKind::SConstant: s = "constant"; break;
    }

    os << s;
    return os;
}

#endif