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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cli/output.h"
#include "sys/internal/path.h"
#include "parser/fext.h"
#include "parser/fprule.h"

int main(int argc, char* argv[]) {
    enum skelly_log_code code = NORM;
    struct skelly_log_conf config = {
        .content = NULL,
        .end = 1,
        .code = &code
    };

    if (argc <= 1) {
        _skelly_elog(0, "Missing Input File(s).", 1);
        return 1;
    }

    struct skelly_file_path fp = skelly_input_file_valid(argv[argc - 1]);
    if (!fp.exists) {
        _skelly_elog(0, "Given Input File Not Found.", 1);
        return 1;
    } else if(fp.exists) {
        code = GOOD;
        config.content = "Compiling File...";
        _skelly_mlog(&config);

        skelly_valid_fext(fp.path);
    }

    printf("Testing malloc guard");
}



