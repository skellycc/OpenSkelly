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

#include "compiler/tokens.h"
#include "io/printer.h"
#include <iostream>

SCC_DECL_OPEN ( scc )

tokenizer::
tokenizer ( const std::string& src )
{
  m_source = src;
  m_cursor = -1;
}

tokenizer::~tokenizer () = default;

void
tokenizer::parse_tokens () SCC_NOEXCEPT
{
  // NOTE: WE haven't indexed special characters yet...
  // Let's not support wide characters for now...
  if ( is_wstring ( m_source ) )
    {
      std::cout << scc_colour_red () << "[SCC Compiler ERROR]: " << scc_colour_normal () << "scc does not support wide characters yet.\n";
      return;
    }
  const char* src = m_source.c_str ();
  while ( *src != '\0' )
    {
      char val = *src;
      if ( std::isalpha ( val ) )
        {
          m_tokens.push_back ( { { val, ENUM_TO_VALUE ( tokens::TOKEN_CHARACTER, int ) } } );
        }
      if ( std::isdigit ( val ) )
        {
          m_tokens.push_back ( { { val, ENUM_TO_VALUE ( tokens::TOKEN_NUMERICAL, int ) } } );
        }
      if ( val == '\'' )
        {
          m_tokens.push_back ( { { val, ENUM_TO_VALUE ( tokens::TOKEN_SINGLE_QUOTE, int ) } } );
        }
      if ( val == '"' )
        {
          m_tokens.push_back ( { { val, ENUM_TO_VALUE ( tokens::TOKEN_DOUBLE_QUOTE, int ) } } );
        }
      m_cursor++;
      src++;
    }
}

const std::string&
tokenizer::get_source () const SCC_NOEXCEPT
{
  return m_source;
}

const unsigned int&
tokenizer::get_cursor () const SCC_NOEXCEPT
{
  return m_cursor;
}

const std::vector<std::map<char, int> >&
tokenizer::get_tokens () const SCC_NOEXCEPT
{
  return m_tokens;
}

bool
tokenizer::is_wstring ( const std::string& str ) SCC_NOEXCEPT
{
  for ( int i = 0; i < str.length (); i++ )
    {
      if ( is_wchar ( str[ i ] ) )
        return true;
    }
  return false;
}

bool
tokenizer::is_wchar ( const char& c ) SCC_NOEXCEPT
{
  return ( c & WCHAR_BIT ) ? true : false;
}

SCC_DECL_CLOSE ()