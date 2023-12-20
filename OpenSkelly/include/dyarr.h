//
//  dyarr.h
//  OpenSkelly
//
//  Created by Mustafa Malik on 20/12/2023.
//

#ifndef __DYARR_H__
#define __DYARR_H__

#include "decls.h"
#include <stdlib.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_CCHAR,
    TYPE_VPTR
} dy_t;

typedef struct {
    union {
        void* element;
        dy_t type;
    };
} dy_arr_t;

SK_EXPORT void* sk_init_dyarr(size_t);

SK_EXPORT void sk_add_dyarr(void*, void*, const dy_t*);

SK_EXPORT void* sk_get_dyarr(void*, unsigned int);

SK_EXPORT void sk_rm_dyarr(void*, unsigned int);

SK_EXPORT void sk_push_dyarr(void);

SK_EXPORT void sk_pop_dyarr(void);

SK_EXPORT void sk_cleanup_dyarr(void);

#endif /* __DYARR_H__ */
