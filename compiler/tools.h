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

#ifndef COMPILER_TOOLS_H_
#define COMPILER_TOOLS_H_

#include <stdlib.h>

#define SKELLY_NTHROW noexcept
#define SKELLY_MALLOC(__bytes) malloc(__bytes)
#define SKELLY_FREE(__blck) free(_blck)

#define SKELLY_NO_OVERRIDE() final


#endif /* COMPILER_TOOLS_H_ */
