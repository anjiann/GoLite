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
        printf("OK\n");
        return 0;
    }
    else if(!strcmp(argv[1], "pretty")) {
        yyparse();
        
        AbstractDispatcher *prettyDispatcher = new PrettyDispatcher();
        program->accept(*prettyDispatcher);
        return 0;
    }
    else if(!strcmp(argv[1], "symbol")) {
        yyparse();

        AbstractDispatcher *symbolDispatcher = new SymbolDispatcher();
        program->accept(*symbolDispatcher);
        return 0;
    }
    else if(!strcmp(argv[1], "typecheck")) {
        return 0;
    }
}

// ./run.sh symbol programs/2-symbol/valid/func_dec.go
