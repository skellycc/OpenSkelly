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

#ifndef COMPILER_TYPE_SKELLYC_KWLIST_H_
#define COMPILER_TYPE_SKELLYC_KWLIST_H_

#include <string>
#include <unordered_set>

static const std::unordered_set<std::string> KW_LIST() {
	return {
		"̄int       "   ,
		"long       "  ,
		"short      "  ,
		"byte       "  ,
		"double     "  ,
		"float      "  ,
		"bool       "  ,
		"char       "  ,
		"void       "  ,
		"shared     "  ,
		"unmanaged  "  ,
		"unsafe     "  ,
		"super      "  ,
		"override   "  ,
		"gets       "  ,
		"return     "  ,
		"if         "  ,
		"else       "  ,
		"else if    "  ,
		"do while   "  ,
		"while      "  ,
		"repeat if  "  ,
		"break      "  ,
		"continue   "  ,
		"for        "  ,
		"and        "  ,
		"or         "  ,
		"not        "  ,
		"noteq      "  ,
		"volatile   "  ,
		"native     "  ,
		"static     "  ,
		"public     "  ,
		"private    "  ,
		"hidden     "  ,
		"const      "  ,
		"unsigned   "  ,
		"signed     "  ,
		"later      "  ,
		"gag // joke"  ,
		"//         "  ,
		"true       "  ,
		"false      "  ,
		"struct     "  ,
		"new        "  ,
		"breaker    "  ,
		"try        "  ,
		"catch      "  ,
		"finally    "
	};
}

static const std::unordered_set<std::string> SKELLY_KEYWORDS = KW_LIST();


#endif /* COMPILER_TYPE_SKELLYC_KWLIST_H_ */
