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

#ifndef INCLUDE_IOBUF_FILES_EXT_FEXT_H_
#define INCLUDE_IOBUF_FILES_EXT_FEXT_H_

#include "../../../util/strtool.h"

#define SKELLY_HEADER_EXT "sklm"
#define SKELLY_SOURCE_EXT "skl"

inline bool __skelly_get_fext(std::string* fn) noexcept {
	std::string h = SKELLY_HEADER_EXT;
	std::string s = SKELLY_SOURCE_EXT;

	std::string strh = SKELLY_STRING_FEXT(*fn, h);
	std::string strs = SKELLY_STRING_FEXT(*fn, s);

	if (strh != "" || strs != "") {
		return true;
	}
	return false;
}

#define SKELLY_IS_VALID_FEXT(name) __skelly_get_fext(&name)

#endif /* INCLUDE_IOBUF_FILES_EXT_FEXT_H_ */
