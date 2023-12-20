//
//  lex.c
//  OpenSkelly
//
//  Created by Mustafa Malik on 18/12/2023.
//

#define __SKELLY_USE_IMPORTS__

#include "lex.h"
#include "keywords.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
 ______
 
 Syntax
 ______
 
 
 #import <stdout.ssk>
 #import <stdin.ssk>
 
 int main( str args ) -> void {
    ssk.println(args[0]);
 }
 
 RULES:
 
 NO GLOBAL STRINGS
 NO GLOBAL SYMBOLS
 NO GLOBAL NUMBERS
 
 */

SK_EXPORT char* sk_err_cause;

#define K(c) printf("%c\n", c)

static int sk_validate_import_fext(const char* fname) {
    const char* delim = ".";
    char* tok;
    
    int found = 0x0;
    tok = strtok((char*) fname, delim);
    
    while (tok != NULL) {
        if (strcmp(tok, "ssk") == 0) {
            found = 0x1;
            break;
        }
        tok = strtok(NULL, delim);
    }
    
    return found;
}

static sk_import_t sk_validate_import(const char* source) {
    char i_table[7];
    char f_table[1024];
    
    const int MAX_REGION = 6;
    int start = 0;
    int fstart = 0;
    
    /*
     n_table[start] = *source;
     start++;
     source++;
     */
    
    do {
        if (sk_tok(*source) != TOK_REGEX_WHITESPACE && sk_tok(*source) != TOK_SYMBOL_IMPORT) {
            i_table[start] = *source;
            start++;
        }
        source++;
    } while (start < MAX_REGION);
    
    do {
        if (sk_tok(*source) == TOK_SYMBOL_GREATER || *source == SK_EOS) {
            break;
        }
        if (sk_tok(*source) != TOK_SYMBOL_LESSER && sk_tok(*source) != TOK_SYMBOL_GREATER) {
            f_table[fstart] = *source;
            fstart++;
        }
        source++;
    } while (sk_tok(*source) != TOK_SYMBOL_GREATER || *source != SK_EOS);
    
    return (sk_import_t) {
        strcmp(i_table, "import") == 0,
        sk_validate_import_fext(f_table),
        i_table,
        f_table
    };
}

// TODO: Theory Idea
// For every whitespace put the selected characters in a buffer
// Check those characters in the buffer are a keyword or not
// Use this method to determine the entry point function

int sk_parse(const char* source) {
    int code = SK_PARSE_OK;
    
    // Start Rule Checking
    do {
        if (__SKELLY_PREPROCESS__) {
            if (sk_tok(*source) == TOK_SYMBOL_IMPORT) {
                sk_import_t import_result = sk_validate_import(source);
                if (import_result.found && import_result.fext_valid) {

                }
            }
        }
        if (sk_tok(*source) == TOK_STR_SINGLE_QUOTE) {
            code = SK_PARSE_ERR;
            SET_ERR(sk_err_cause, "Unexpected Identifier caught: '");
        }
        source++;
    } while (*source != SK_EOS && code == SK_PARSE_OK);
    
    return code;
}

int sk_tok(char ch) {
    
    if (ch == '#') {
        return TOK_SYMBOL_IMPORT;
    }
    
    if (isalpha(ch)) {
        return TOK_SYMBOL_CHAR;
    }
    
    if (isnumber(ch)) {
        return TOK_SYMBOL_NUMERICAL;
    }
    
    if (ch == '\'') {
        return TOK_STR_SINGLE_QUOTE;
    }
    
    if (ch == '"') {
        return TOK_STR_DOUBLE_QUOTE;
    }
    
    if (ch == '<') {
        return TOK_SYMBOL_LESSER;
    }
    
    if (ch == '>') {
        return TOK_SYMBOL_GREATER;
    }
    
    return TOK_SYMBOL_UNKNOWN;
}
