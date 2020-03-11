#ifndef NDECLARATION_H
#define NDECLARATION_H

class NDeclaration {
    public:
        int lineno;
        
        NDeclaration() {}
        NDeclaration(int lineno) : lineno{lineno} {}
}

#endif /* !NDECLARATION_H */