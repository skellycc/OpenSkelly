//
//  dyarr.c
//  OpenSkelly
//
//  Created by Mustafa Malik on 20/12/2023.
//

#include "dyarr.h"

static void* __arr;
static void* __temp_arr;

static unsigned int __size;

static void sk_adjust_dyarr(void* arr, const dy_t* type, const size_t* bufsize) {

}

void* sk_init_dyarr(size_t buffer_size) {
    __arr = malloc(buffer_size * sizeof(dy_arr_t));
    __size = 0;
    return __arr;
}

void sk_add_dyarr(void* element, const dy_arr_t* element_type) {

}

void* sk_get_dyarr(void* arr, unsigned int index) {
    return NULL;
}

void sk_rm_dyarr(void* arr, unsigned int index) {
    
}

void sk_push_dyarr(void) {
    
}

void sk_pop_dyarr(void) {
    
}

void sk_cleanup_dyarr(void) {
    free(__arr);
}
