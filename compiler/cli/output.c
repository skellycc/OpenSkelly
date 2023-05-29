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
*******************************************************************************/\

#include <stdio.h>
#include "cli/output.h"
#include "cli/modes/colour.h"

#define SKELLY_OUT(__col, __msg, __n, __m) \
    printf("%s", __col); \
    if (__m >= 1) \
        printf("%s\n", "[SKELLY]: DEBUG MODE"); \
    if (__n) \
        printf("%s\n", __msg); \
    else \
        printf("%s", __msg);

void _skelly_dlog(const struct skelly_log_conf* _conf) {
    switch (*_conf->code) {
        case NORM:
            SKELLY_OUT(skelly_colour_normal(), _conf->content, _conf->end, 1);
            break;
        case WARN:
            SKELLY_OUT(skelly_colour_magenta(), _conf->content, _conf->end, 1);
            break;
        case ERR:
            SKELLY_OUT(skelly_colour_red(), _conf->content, _conf->end, 1);
            break;
        case CRIT:
            SKELLY_OUT(skelly_colour_underline(), "", 1, 0);
            SKELLY_OUT(skelly_colour_red(), _conf->content, _conf->end, 1);
            break;
    }
}

void _skelly_mlog(const struct skelly_log_conf* _conf) {
    switch (*_conf->code) {
        case NORM:
            SKELLY_OUT(skelly_colour_normal(), _conf->content, _conf->end, 0);
            break;
        case WARN:
            SKELLY_OUT(skelly_colour_magenta(), _conf->content, _conf->end, 0);
            break;
        case ERR:
            SKELLY_OUT(skelly_colour_red(), _conf->content, _conf->end, 0);
            break;
        case CRIT:
            SKELLY_OUT(skelly_colour_underline(), "", 1, 0);
            SKELLY_OUT(skelly_colour_red(), _conf->content, _conf->end, 0);
            break;
    }
}

void _skelly_elog(int colour, const char* cause, int delim) {
    switch (colour) {
        case 0:
            SKELLY_OUT(skelly_colour_red(), cause, delim, 0);
            break;
        case 1:
            SKELLY_OUT(skelly_colour_magenta(), cause, delim, 0);
            break;
        case 2:
            SKELLY_OUT(skelly_colour_normal(), cause, delim, 0);
            break;
        default:
            SKELLY_OUT(skelly_colour_normal(), cause, delim, 0);
            break;
    }
}