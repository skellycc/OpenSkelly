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

#ifndef DYNAMO_H
#define DYNAMO_H

#include <stdio.h>
#include <stdlib.h>

struct dynamo {
    size_t elemsize;
    int length;
    int* buffer;
};

struct dynamo create_dynamo(size_t elemsize) {
    int* buffer = malloc(elemsize);

    struct dynamo result = {
        .elemsize = elemsize,
        .buffer = buffer,
        .length = 0,
    };
    return result;
}

void dynamo_set(struct dynamo *d, int new) {
    d->length++;
    d->buffer = realloc(d->buffer, d->length * d->elemsize);
    d->buffer[d->length-1] = new;
}
int dynamo_get(struct dynamo *d, int index) {
    return d->buffer[index];
}
//! FREE BUFFER AT THE END OF SCOPE

#endif