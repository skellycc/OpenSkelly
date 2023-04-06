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

#ifndef TESTS_COMPILER_SKELLYC_ANNONS_TEST_H_
#define TESTS_COMPILER_SKELLYC_ANNONS_TEST_H_

#include "../../compiler/parse/lexer/skellyc_lexer.h"
#include <iostream>

struct skellyc_annons_test {
	std::string __src_code = R"code(	
		// test code
		#bring <   test_sample.sklm   >

		int   main  (  ) {
			out("hello");
		}

	)code";

	void remove_spaces() {
		std::string result = skelly::compiler::lexer::skellyc_annons::truncate_spaces(__src_code);
		std::cout << result << std::endl;
	}
};


#endif /* TESTS_COMPILER_SKELLYC_ANNONS_TEST_H_ */
