//
//  token.h
//  OpenSkelly
//
//  Created by Mustafa Malik on 18/12/2023.
//

#ifndef __TOKEN_H__
#define __TOKEN_H__

enum skelly_token {
    // Variables
    TOK_VAR_DECL,
    TOK_VAR_REF,
    TOK_VAR_ASSIGN, // x = 1
    TOK_VAR_INC_ASSIGN, // += -= /= *= etc
    // Method
    TOK_METHOD_TYPE,
    TOK_METHOD_NAME,
    TOK_METHOD_PAREN_OPEN,
    TOK_METHOD_PAREN_CLOSE,
    TOK_METHOD_ARGS,
    TOK_METHOD_RTYPE,
    TOK_METHOD_OPEN_BLOCK,
    TOK_METHOD_CLOSE_BLOCK,
    // If statements
    TOK_COND_KW, // if, else, elseif
    TOK_COND_COMP, // comparable
    TOK_COND_OPEN, // (
    TOK_COND_CLOSE,
    TOK_COND_BEGIN, // {
    TOK_COND_END, // }
    
    // STRINGS & REGEX
    TOK_STR_SINGLE_QUOTE,
    TOK_STR_DOUBLE_QUOTE,
    TOK_REGEX_WHITESPACE,
    
    // Symbols
    TOK_SYMBOL_CHAR,
    TOK_SYMBOL_NUMERICAL,
    TOK_SYMBOL_SPECIAL,
    TOK_SYMBOL_COMMENT,
    TOK_SYMBOL_IMPORT,
    
    TOK_SYMBOL_GREATER,
    TOK_SYMBOL_LESSER,
    
    TOK_SYMBOL_UNKNOWN,
    TOK_NEXT_ONE,
    TOK_TERMINATOR
};

#endif /* __TOKEN_H__ */
