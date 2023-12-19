//
//  lex.h
//  OpenSkelly
//
//  Created by Mustafa Malik on 18/12/2023.
//

#ifndef __LEX_H__
#define __LEX_H__

#ifdef __SKELLY_USE_IMPORTS__
// disabled pre-processing
#   define __SKELLY_PREPROCESS__ 1
#else
#   define __SKELLY_PREPROCESS__ 0
#endif

#define SET_ERR(err_loc, msg) err_loc = msg

#include "decls.h"
#include "token.h"

#define SK_PARSE_OK     1
#define SK_PARSE_ERR    0
#define SK_PARSE_UN     4
#define SK_PARSE_LEX    -1

typedef struct {
    unsigned int found;
    unsigned int fext_valid;
    const char* i_statment;
    const char* fname;
} sk_import_t;

// 2 - UNKNOWN
// -1 - LEXICAL ERROR
// 0 - SYNTAX ERROR
// 1 - OK
SK_EXPORT int sk_parse(const char*);

SK_EXPORT int sk_tok(char);


#endif /* __LEX_H__ */
