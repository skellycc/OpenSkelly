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

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "parser/fprule.h"

bool __skelly_is_type(const char* _src, int (*_input)(int)) {
    bool acceptable = true;
    int i = 0;
    while (*++_src != '\0') {
        if (_input(_src[i])) {
            acceptable = false;
            break;
        }
        i++;
    }
    return acceptable;
}

bool skelly_string_contains(const char* _src) {
    return false;
}

char* skelly_string_split(const char* _src, const char* _delim) {
    return "";
}

bool skelly_string_cmp(const char* _src1, const char* _src2) {
    return strcmp(_src1, _src2);
}

bool skelly_is_all_str(const char* _src) {
    return __skelly_is_type(_src, isdigit);
}

bool skelly_is_all_num(const char* _src) {
    return __skelly_is_type(_src, isalpha);
}