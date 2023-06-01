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

#include "cli/modes/colour.h"



inline const char* skelly_colour_bold(void) {
    return "\033[1m";
}

inline const char* skelly_colour_italic(void) {
    return "\033[3m";
}

inline const char* skelly_colour_faint(void) {
    return "\033[2m";
}

inline const char* skelly_colour_underline(void) {
    return "\033[4m";
}

inline const char* skelly_colour_red(void) {
    return "\033[31m";
}

inline const char* skelly_colour_green(void) {
    return "\033[32m";
}

inline const char* skelly_colour_yellow(void) {
    return "\033[33m";
}

inline const char* skelly_colour_blue(void) {
    return "\033[34m";
}

inline const char* skelly_colour_magenta(void) {
    return "\033[35m";
}

inline const char* skelly_colour_white(void) {
    return "\033[37m";
}

inline const char* skelly_colour_normal(void) {
    return "\033[00m";
}