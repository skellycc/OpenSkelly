/*******************************************************************************
 *                                                                               *
 *   Skelly - Open Source Programming Language                                   *
 *                                                                               *
 *   Copyright (C) 2024 Mustafa Malik                                            *
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

#ifndef __SCC_H
#define __SCC_H

#if __cplusplus < 201103
#error "The C standard is too old to use, please set it to C11"
#else
#define SCC_DECL_OPEN(name) namespace name {
#define SCC_DECL_CLOSE() }
#define SCC_NOEXCEPT noexcept
#define SCC_THROWS noexcept(false)
#define SCC_FINAL final
#define ENUM_TO_VALUE(e, v) static_cast<v>(e)
#endif

#endif //__SCC_H
