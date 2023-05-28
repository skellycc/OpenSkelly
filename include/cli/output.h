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

enum skelly_log_code {
    NORM,
    WARN,
    ERR,
    CRIT
};

struct skelly_log_conf {
    const char* content;
    const char end;
    skelly_log_code* code;
};

void _skelly_dlog(const skelly_log_conf*);

void _skelly_mlog(const skelly_log_conf*);

#endif /* __INCLUDE_CLI_OUTPUT_H__ */