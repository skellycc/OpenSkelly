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

#ifndef INCLUDE_UTIL_OS_H_
#define INCLUDE_UTIL_OS_H_

#include "strtool.h"

inline std::string __skelly_get_os() {
#if __APPLE__
	return "unix";
#elif defined(__linux) || defined(__linux__)
	return "unix";
#elif defined(_WIN32) || defined(_WIN64)
	return "nt";
#elif defined(__ANDROID__)
	return "unix";
#else
	return "other";
#endif
}

#define SKELLY_OS_TYPE() __skelly_get_os()


#endif /* INCLUDE_UTIL_OS_H_ */
