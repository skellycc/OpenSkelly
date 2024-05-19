#include "compiler/gram/checker.h"
#include "compiler/tokens.h"
#include "io/printer.h"
#include <iostream>

int
main ()
{

  std::cout << scc_colour_magenta () << "[SCC Compiler]: " << scc_colour_normal () << "generating sources...\n";

  const std::string source = "hello 'Lol'! and then \"ok\"";
  scc::tokenizer token_a ( source );
  token_a.parse_tokens ();

  auto gen_tokens = token_a.get_tokens ();
  scc::checker gram_checker ( gen_tokens );
  auto gram_result = gram_checker.validate_tokens ();

  if ( !std::get<0> ( gram_result ) )
    {
      std::cout << scc_colour_red () << "[SCC Compiler ERROR]: " << scc_colour_normal () << std::get<1> ( gram_result ) << std::endl;
      return -1;
    }
  gram_checker.gen_next_stage ();

  for ( const auto& arr : gen_tokens )
    {
      for ( const auto& keys : arr )
        {
          if ( keys.second == ENUM_TO_VALUE ( scc::tokens::TOKEN_CHARACTER, int ) )
            {
              std::cout << "TOKEN CHARACTER: " << keys.first << std::endl;
            }
          if ( keys.second == ENUM_TO_VALUE ( scc::tokens::TOKEN_NUMERICAL, int ) )
            {
              std::cout << "TOKEN NUMERICAL: " << keys.first << std::endl;
            }
          if ( keys.second == ENUM_TO_VALUE ( scc::tokens::TOKEN_SINGLE_QUOTE, int ) )
            {
              std::cout << "TOKEN SINGLE QUOTE: " << keys.first << std::endl;
            }
          if ( keys.second == ENUM_TO_VALUE ( scc::tokens::TOKEN_DOUBLE_QUOTE, int ) )
            {
              std::cout << "TOKEN DOUBLE QUOTE: " << keys.first << std::endl;
            }
        }
    }

  return 0;
}
