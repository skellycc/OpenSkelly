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

#ifndef INCLUDE_UTIL_IDTYPE_H_
#define INCLUDE_UTIL_IDTYPE_H_

#define SKELLY_GET_ENUM_VALUE(__enum, __x) static_cast<std::underlying_type<__enum>::type>(__x)

#endif /* INCLUDE_UTIL_IDTYPE_H_ */
