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

#include "compiler/gram/checker.h"

SCC_DECL_OPEN ( scc )

checker::
checker ( const std::vector<std::map<char, int> >& tokens )
{
  m_tokens = tokens;
}

checker::~checker () = default;

const std::tuple<bool, const char*>
checker::validate_tokens () SCC_NOEXCEPT
{
  return std::make_tuple ( false, "No tokens available..." );
}

void
checker::gen_next_stage () SCC_NOEXCEPT
{
}

SCC_DECL_CLOSE ()