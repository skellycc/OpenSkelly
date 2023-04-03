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

#include <iostream>

#include "../include/util/strtool.h"
#include "../include/iobuf/files/ext/fext.h"

int main() {
	// string testing
	std::string test = "scott>=tiger>=mushroom";
	std::string test_delim = ">=";

	skelly_str_splits test_data = SKELLY_STRING_SPLIT(test, test_delim);

	for (int i = 0; i < test_data.contents.size(); i++) {
		std::cout << test_data.contents[i] << std::endl;
	}

	std::string fn = "test.skl";
	std::string fnh = "test.sklm";

	if (SKELLY_IS_VALID_FEXT(fn)) {
		std::cout << "valid skelly file\n";
	}

	if (SKELLY_IS_VALID_FEXT(fnh)) {
		std::cout << "valid skelly module file\n";
	}
}
