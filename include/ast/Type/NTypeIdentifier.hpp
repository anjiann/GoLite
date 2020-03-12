#ifndef NTYPEIDENTIFIER_H
#define NTYPEIDENTIFIER_H

#include <string>
#include "NType.hpp"

using std::string;

class NTypeIdentifier : public NType {    
    public:
        string name;
        NTypeIdentifier(string name) : name{name} {}
};

#endif /* !NTYPEIDENTIFIER_H */