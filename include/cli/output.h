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

#ifndef __INCLUDE_CLI_OUTPUT_H__
#define __INCLUDE_CLI_OUTPUT_H__

// Remove Useless Warnings
#pragma GCC diagnostic ignored "-Wundefined-inline"

#define SKELLY_COMPILER_NAME "Skelly Compiler"
#define SKELLY_COMPILER_WARNING " [WARNING]: "
#define SKELLY_COMPILER_LOG " [INFO]: "
#define SKELLY_COMPILER_ERROR " [ERROR]: "

enum skelly_log_code {
    GOOD,
    NORM,
    WARN,
    ERR,
    CRIT
};

struct skelly_log_conf {
    const char* content;
    unsigned int end;
    enum skelly_log_code* code;
};

extern void _skelly_dlog(const struct skelly_log_conf*);

extern void _skelly_mlog(const struct skelly_log_conf*);

extern void _skelly_elog(int, const char*, int);

#endif /* __INCLUDE_CLI_OUTPUT_H__ */