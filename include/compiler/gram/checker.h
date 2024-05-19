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

#ifndef CHECKER_H
#define CHECKER_H

#include "__scc.h"

#include <map>
#include <string>
#include <tuple>
#include <vector>

SCC_DECL_OPEN ( scc )

class checker SCC_FINAL
{
private:
  std::vector<std::map<char, int> > m_tokens;

public:
  explicit checker ( const std::vector<std::map<char, int> >& );
  ~checker ();

public:
  const std::tuple<bool, const char*> validate_tokens () SCC_NOEXCEPT;
  void gen_next_stage () SCC_NOEXCEPT;
};

SCC_DECL_CLOSE ()

#endif // CHECKER_H
