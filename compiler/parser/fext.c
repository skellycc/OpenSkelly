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
#include <stdio.h>

#include "cli/output.h"
#include "parser/fext.h"
#include "parser/fprule.h"

bool skelly_check_fext_len(const char* f_extn) {
    // 0 OK
    // 1 NOT OK
    if (strlen(f_extn) > SKELLY_MAX_FEXT_NAME) {
        return true;
    }
    return false;
}

bool skelly_valid_fext(const char* f_extn) {
    enum skelly_log_code code = NORM;
    struct skelly_log_conf str_log = {0};
    
    bool safe_len = skelly_check_fext_len(f_extn);
    if (safe_len) {
        _skelly_elog(1, SKELLY_FEXT_LEN_WARN, 1);
    }

    return false;
}