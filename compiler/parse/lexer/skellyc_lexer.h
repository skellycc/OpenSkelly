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

#ifndef COMPILER_PARSE_LEXER_SKELLYC_LEXER_H_
#define COMPILER_PARSE_LEXER_SKELLYC_LEXER_H_

#include "../../skellyc_token.h"
#include "../../../tools.h"
#include <stddef.h>

namespace skelly {
namespace compiler {
namespace lexer {

class skellyc_annons SKELLY_NO_OVERRIDE() {
public:
	static const char* __skelly_source = "sample.skl";
private:
	explicit skellyc_annons() = delete;
	~skellyc_annons() = delete;
public:
	static void truncate_spaces(const char* _src = __skelly_source);
};

class skellyc_lexer SKELLY_NO_OVERRIDE() {
private:
	const char* __skelly_fsource;
	size_t __skelly_byte_stream;
	// Counter
	unsigned int __bol;
	unsigned int __cur;
	unsigned int __eol;
	//
	bool eof = false;
	bool fail = false;
	bool parsing_state = false;
private:
	// quick, does not require forward declaration
	inline void __free_buffers(void* _blck) SKELLY_NTHROW {
		SKELLY_FREE(_blck);
	}
	// memory allocations
	template<typename BufferDataType>
	inline BufferDataType* __make_buffer(const size_t& size = sizeof(BufferDataType), const bool& man = false) const SKELLY_NTHROW {
		if (man) {
			return (BufferDataType*) malloc(size);
		}
		return new BufferDataType;
	}
public:
	explicit skellyc_lexer(const char* _src);
	~skellyc_lexer() = default;

	// Please do not use copy constructors or move semantics on the LEXER!
	skellyc_lexer(skellyc_lexer) = delete;
public:
	// LEXER functions
};

}
}
}

#endif /* COMPILER_PARSE_LEXER_SKELLYC_LEXER_H_ */
