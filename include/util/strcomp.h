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

#ifndef INCLUDE_UTIL_STRCOMP_H_
#define INCLUDE_UTIL_STRCOMP_H_

#include <string>
#include <sstream>
#include <vector>

struct skelly_str_container {
	std::vector<std::string> contents;
};

typedef skelly_str_container skelly_str_splits;

#endif /* INCLUDE_UTIL_STRCOMP_H_ */
