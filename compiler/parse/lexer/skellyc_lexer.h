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

#include "../skellyc_token.h"
#include "../../type/skellyc_kwlist.h"
#include "../../tools.h"
#include "../../../include/util/strtool.h"

#include <algorithm>
#include <string>
#include <ctype.h>
#include <stddef.h>

namespace skelly {
namespace compiler {
namespace lexer {

class skellyc_annons SKELLY_NO_OVERRIDE() {
private:
	explicit skellyc_annons() = delete;
	~skellyc_annons() = delete;
public:
	static std::string truncate_spaces(std::string _src) {
		return SKELLY_STRING_TRUNCATE(_src, '\t');
	}
	static std::string truncate_lines(const char* _src) {
		return SKELLY_STRING_TRUNCATE(_src, '\n');
	}
	static std::string truncate_sngl_cmts(std::string _src) {
		std::string __res;
		std::string __tmpstd = _src;
		bool comment = false;
		int i = 0;
		while (i < __tmpstd.length()) {
			if (comment || __tmpstd.substr(i, 2) == "//") {
				comment = true;
			}
			if (comment) {
				size_t nline_pos = __tmpstd.find("\n", i);
				if (nline_pos != std::string::npos) {
					comment = false;
					i = nline_pos;
				} else {
					i = __tmpstd.length();
				}
			} else {
				__res += __tmpstd[i];
				i++;
			}
		}
		return __res;
	}
	static std::string add_keyword_space(std::string _src) {
		std::string __word;
		std::string __res;
		std::string __tmpc;
		bool word = false;
		for (char& __symbol : _src) {
			if (isalpha(__symbol)) {
				if (!word) {
					word = true;
					__word = "";
				}
				__word += __symbol;
			} else {
				if (word) {
					if (SKELLY_KEYWORDS.count(__tmpc) > 0) {
						__res += __word;
					}
					word = false;
				}
			}
		}
		return __word;
	}
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
	skellyc_lexer(skellyc_lexer&) = delete;
public:
	// LEXER functions
	skelly_token next_token();

	void drop_line();

	void trim_to_left();
};

}
}
}

#endif /* COMPILER_PARSE_LEXER_SKELLYC_LEXER_H_ */
