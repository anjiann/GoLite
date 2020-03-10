#ifndef NDECFUNC_HPP
#define NDECFUNC_HPP

#include <string>

using std::string;
using std::vector;

typedef vector<NExpression*> NExpressionList;
class NDecFunc : NDeclaration {
    public:
        string identifier;

}

#endif /* !NDECFUNC_HPP */