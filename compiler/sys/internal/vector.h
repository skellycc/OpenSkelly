/*******************************************************************************
*                                                                               *
*   Skelly - Open Source Programming Language                                   *
*                                                                               *
*   Copyright (C) 2023 Mustafa Malik                                            *
*                                                                               *
*   This program is free software: you can redistribute it and/or modify        *
*   it under the terms of the GNU General Public License as published by        *
*   the Free Software Foundation, either version 3 of the License, or           *
*   (at your option) any later version.                                         *
*                                                                               *
*   This program is distributed in the hope that it will be useful,             *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of              *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
*   GNU General Public License for more details.                                *
*                                                                               *
*   You should have received a copy of the GNU General Public License           *
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.       *
*                                                                               *
*******************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

struct vector {
    size_t elemsize;
    int length;
    int* buffer;
};

struct vector create_vector(size_t elemsize) {
    int* buffer = malloc(elemsize);

    struct vector result = {
        .elemsize = elemsize,
        .buffer = buffer,
        .length = 0,
    };
    return result;
}

void vector_set(struct vector *v, int new) {
    v->length++;
    v->buffer = realloc(v->buffer, v->length * v->elemsize);
    v->buffer[v->length-1] = new;
}
int vector_get(struct vector *v, int index) {
    return v->buffer[index];
}
//! FREE BUFFER AT THE END OF SCOPE

#endif