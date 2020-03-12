#ifndef NDECTYPE_HPP
#define NDECTYPE_HPP

#include <string>

#include "NDeclaration.hpp"
#include "../Type/NType.hpp"

using std::string;

class NDecType : public NDeclaration {
    public:
        string id;
        const NType &type;
        
        NDecType(string id, const NType &type) : id{id}, type{type} {}
};

#endif /* !NDECTYPE_HPP */