#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "main.h"

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
        // PrettyPrinter *prettyPrinter = new PrettyPrinter();
        // e.accept(prettyPrinter);
        return 0;
    }
}

// cat programs/1-scan+parse/valid/7-1-basic.go | build/bin/golite
// cat programs/1-scan+parse/valid/8-2-blockstmts.go | build/bin/golite
// cat programs/1-scan+parse/valid/1-scanner/interstringlit.go | build/bin/golite tokens