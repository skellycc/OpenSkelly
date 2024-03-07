//
//  main.c
//  OpenSkelly
//
//  Created by Mustafa Malik on 17/12/2023.
//

#include <stdlib.h>

/*
 ______
 
 Syntax
 ______
 
 
 #import <stdout.ssk>
 #import <stdin.ssk>
 
 int main( str args ) -> void {
    ssk.println(args[0]);
 }
 
 */

#include <stdio.h>
#include "lex.h"

const char* sk_err_cause;

int main(void) {
    
    const char* source_code = 
        "#import <stdlib.ssk>"
        "#hello test"
    ;

    if (sk_parse(source_code) == SK_PARSE_ERR) {
        printf("Failed to parse: %s\n", sk_err_cause);
    }
    
    return EXIT_SUCCESS;
}
