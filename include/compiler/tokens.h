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

#ifndef TOKENS_H
#define TOKENS_H

#include "__scc.h"

#include <map>
#include <string>
#include <vector>

#define WCHAR_BIT 0x80

SCC_DECL_OPEN ( scc )

enum class tokens
{
  TOKEN_CHARACTER,
  TOKEN_WHITESPACE,
  TOKEN_SINGLE_QUOTE,
  TOKEN_DOUBLE_QUOTE,
  TOKEN_NUMERICAL
};

class tokenizer SCC_FINAL
{
private:
  std::string m_source;
  unsigned int m_cursor;
  std::vector<std::map<char, int> > m_tokens;

public:
  explicit tokenizer ( const std::string& );
  ~tokenizer ();

public:
  void parse_tokens () SCC_NOEXCEPT;
  const std::vector<std::map<char, int> >& get_tokens () const SCC_NOEXCEPT;
  const std::string& get_source () const SCC_NOEXCEPT;
  const unsigned int& get_cursor () const SCC_NOEXCEPT;

public:
  // consider refactoring this later
  static bool is_wstring(const std::string&) SCC_NOEXCEPT;
  static bool is_wchar(const char&) SCC_NOEXCEPT;
};

SCC_DECL_CLOSE ()

#endif // TOKENS_H
