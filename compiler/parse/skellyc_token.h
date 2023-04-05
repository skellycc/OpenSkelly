/**
 * The OpenSkelly Project
 *
 * Developed by The Skelly Compiler Collection software foundation team.
 *
 * Copyright (C) 2023 SCC. See the LICENSE for more information.
 *
 * Date Created: 03/04/2023
 * Authors:
 * 		@shabman - Mustafa Malik
 *
 * This file is part of the SCC-VM project (Skelly Compiler Collection Virtual Machines)
 *
 * Developed for the SCMLVM system. (Skelly Compiler Middle Level Virtual Machine)
 */

#ifndef COMPILER_PARSE_SKELLYC_TOKEN_H_
#define COMPILER_PARSE_SKELLYC_TOKEN_H_

enum skelly_token {
	// Token Important Compiler Notations
	TOKEN_START, // BOF (Beginning Of File)
	TOKEN_END, // EOF (End Of File)
	// Invisible gaps and spaces
	TOKEN_WHITESPACE,
	TOKEN_NEW_LINE, // Beginning Of Line
	TOKEN_END_LINE, // ; (End Of Line)
	TOKEN_STMT_BGNC, // : colon
	// Pre-compiling
	TOKEN_PRECOMPILER, // #bring <value>
	TOKEN_PRE_HASH, // #
	TOKEN_PRECOMPILER_OPENC, // <
	TOKEN_PRECOMPILER_CLOSEC, // >
	// Symbols (variables, names, etc)
	TOKEN_PRECOMPILER_SYMBOL, // #bring < SYMBOL >
	TOKEN_SYMBOL,
	// Keywords, functions, function calls, method references (::)
	TOKEN_KEYWORD,
	TOKEN_FUNCCALL,
	TOKEN_FUNCDECL,
	TOKEN_METHOD_REF,
	// Syntax openings
	TOKEN_OCURL,
	TOKEN_CCURL,
	TOKEN_OPAREN,
	TOKEN_CPAREN,
	TOKEN_OPEN_SCOPE,
	TOKEN_CLOSE_SCOPE,
	// Memory management areas
	TOKEN_MEMORY_UNSAFE,
	TOKEN_MEMORY_SAFE,
	// Statements
	TOKEN_STMT,
	TOKEN_JUMP_STMT,
	// Loops
	TOKEN_FLOOP,
	TOKEN_WLOOP,
	TOKEN_SCASE,
	TOKEN_RLOOP,
	TOKEN_DOLOOP,
	// Conditions
	TOKEN_IF_STMT,
	TOKEN_ELIF_STMT,
	TOKEN_ELSE_STMT,
	// add more
};

/*
 * #bring <sstd>
 *
 * #prec test
 *
 * int main() {
 * 	skelly::out();
 * }
 *
 */



#endif /* COMPILER_PARSE_SKELLYC_TOKEN_H_ */
