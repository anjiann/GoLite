#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "main.hpp"

void yyparse();
int yylex();

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "You need to supply one argument to this program.";
        return -1;
    }

    g_tokens = 0;
    if(!strcmp(argv[1], "scan")) {
        while(yylex());
        printf("OK\n");
        return 0;
    }
    else if(!strcmp(argv[1], "tokens")) {
        g_tokens = 1;   
        while(yylex());
        return 0;
    }
    else if(!strcmp(argv[1], "parse")) {
        yyparse();

        AbstractDispatcher *weederDispatcher = new WeederDispatcher();
        program->accept(*weederDispatcher);
        delete weederDispatcher;

        printf("OK\n");
        return 0;
    }
    else if(!strcmp(argv[1], "pretty")) {
        yyparse();
        
        AbstractDispatcher *prettyDispatcher = new PrettyDispatcher();
        program->accept(*prettyDispatcher);
        delete prettyDispatcher;
        return 0;
    }
    else if(!strcmp(argv[1], "symbol")) {
        yyparse();

        AbstractDispatcher *symbolDispatcher = new SymbolDispatcher(true);
        program->accept(*symbolDispatcher);
        delete symbolDispatcher;
        return 0;
    }
    else if(!strcmp(argv[1], "typecheck")) {
        yyparse();

        AbstractDispatcher *symbolDispatcher = new SymbolDispatcher(false);
        program->accept(*symbolDispatcher);
        delete symbolDispatcher;

        AbstractDispatcher *typecheckDispatcher = new TypecheckDispatcher();
        program->accept(*typecheckDispatcher);
        delete typecheckDispatcher;
        printf("OK\n");
        return 0;
    }
}

// ./run.sh symbol programs/2-typecheck/valid/symbol/func_dec.go 
// ./run.sh typecheck programs/2-typecheck/invalid/3-exp/3-1-binary_exp/binaryexp1.go