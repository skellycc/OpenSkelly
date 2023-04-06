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

#ifndef INCLUDE_UTIL_STRTOOL_H_
#define INCLUDE_UTIL_STRTOOL_H_

#include <tuple>
#include <algorithm>
#include "strcomp.h"

// Flush existing contents
#define SKELLY_STR_FLUSH(strbuf, count) \
	if (count > 0) { \
		strbuf.clear(); \
	}

inline skelly_str_splits str_tok_split(std::string* strin, std::string* strtok) {
	static skelly_str_splits data;
	SKELLY_STR_FLUSH(data.contents, data.contents.size())
	std::stringstream ss(*strin);
	size_t pos_start = 0, pos_end = 0, delim_len = strtok->length();
	std::string token;

	while ((pos_end = strin->find(*strtok, pos_start)) != std::string::npos) {
		token = strin->substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		data.contents.push_back(token);
	}

	data.contents.push_back(strin->substr(pos_start));
	return data;
}

inline bool str_tok_match(std::string* strin, std::string* strtarg) {
	return strcmp(strin->c_str(), strtarg->c_str());
}

inline std::tuple<std::string, std::tuple<bool, size_t>> str_tok_has(std::string* strin, std::string* strhas) {
	skelly_str_container data;
	SKELLY_STR_FLUSH(data.contents, data.contents.size())
	bool found = false;
	size_t occur = 0;
	if ((occur = strin->find(*strhas) != std::string::npos)) {
		found = true;
	}
	return std::make_tuple(*strhas, std::make_tuple(found, occur));
}

inline std::string str_fext_name(std::string* fname, std::string* strexpt) {
	if (fname->substr(fname->find_last_of(".") + 1) == (*strexpt)) {
		return *strexpt;
	}
	return "";
}

inline bool is_str_empty(const char* src) {
	return src != NULL && src[0] == '\0';
}

inline bool is_str_empty(const std::string& str) {
	return str.empty();
}

inline std::string strtrunc(std::string strin, char strtrunc) {
	strin.erase(std::remove(strin.begin(), strin.end(), strtrunc), strin.end());
	return strin;
}

inline std::string str_replace(std::string strin, std::string strrep, std::string strto) {
	return 0;
}

inline bool str_in_array(std::vector<std::string> arr, std::string strin) {
	return (!arr.empty()) && std::find(arr.begin(), arr.end(), strin) != arr.end();
}

// Split string tokens
#define SKELLY_STRING_SPLIT(_strin, _strtok) str_tok_split(&_strin, &_strtok)
#define SKELLY_STRING_MATCH(_strin, _strtarg) str_tok_match(&_strin, &_strtarg)
#define SKELLY_STRING_HAS(_strin, _strhas) str_tok_has(&_strin, &_strhas)
#define SKELLY_STRING_FEXT(_strin, _strexpt) str_fext_name(&_strin, &_strexpt)
#define SKELLY_STRING_EMPTY(_strin) is_str_empty(_strin)
#define SKELLY_STRING_TRUNCATE(_strin, _strtrunc) strtrunc(_strin, _strtrunc)
#define SKELLY_STRING_REPLACE(_strin, _strrep, _strto) str_replace(_strin, _strrep, _strto)

#define SKELLY_STRING_ARRAY_IN(_srcarr, _strin) str_in_array(_srcarr, _strin)

#endif /* INCLUDE_UTIL_STRTOOL_H_ */
