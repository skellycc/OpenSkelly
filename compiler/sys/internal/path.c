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

#include "sys/internal/path.h"

#if defined(__linux__) || defined(__APPLE__)
#   include <unistd.h>
#   include <sys/types.h>
#   include <sys/stat.h>
#elif defined(WIN32)
#   include <windows.h>
// TODO: Requires implementation
#endif

bool __skelly_has_nts(const char* str) {
    bool result = false;
    while (!result) {
        if (result)
            break;
        result = (*(str++)) == '\0';
    }
    return result;
}

struct skelly_file_path skelly_input_file_valid(const char* path) {
    struct skelly_file_path result;
    result.path = path;
    result.exists = false;

    struct stat pf;
    stat(path, &pf);

    result.exists = S_ISREG(pf.st_mode);
    result.safe = __skelly_has_nts(path);

    return result;
}
