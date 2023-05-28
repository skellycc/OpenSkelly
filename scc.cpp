/*******************************************************************************
*                                                                               *
*   Skelly - Open Source Programming Language                                   *
*                                                                               *
*   Copyright (C) 2023 Mustafa Malik                                            *
*                                                                               *
*   This program is free software: you can redistribute it and/or modify        *
*   it under the terms of the GNU General Public License as published by        *
*   the Free Software Foundation, either version 3 of the License, or           *
*   (at your option) any later version.                                         *
*                                                                               *
*   This program is distributed in the hope that it will be useful,             *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of              *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
*   GNU General Public License for more details.                                *
*                                                                               *
*   You should have received a copy of the GNU General Public License           *
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.       *
*                                                                               *
*******************************************************************************/

#include "Platform/SkellyPlatform.hpp"
#include "Io/Stream/SkellyColourMode.hpp"
#include "Policy/SkellyMemoryPolicy.hpp"

//#include <Parser/Services/SkellyStrings.hpp>
#include "Parser/Services/SkellyStringService.hpp"

int main(int argc, char* argv[]) {

    std::cout << skellyStringCompare("text", "text") << std::endl;
    //std::cout << skellySplitString("poo.p", ".")[0] << std::endl;
   //std::cout << SKELLY_STRING_VALID_FEXT("test.penis.skl") << std::endl;

    bool known = false;
    bool file = false;
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0) {
            known = true;
            std::cout << "scc (v 0.0.1)\nSkelly Compiler (v 0.0.1)\nCPU: (" << PLATFORM_NAME << ")\n"; 
        } else {
            known = false;
        }
    }
    if (!known && argc > 1) {
        std::cout << "scc - " << colors::green << "Skelly Compiler" << "\033[0m" << ": " ;
        std::cout << colors::red << colors::bold << "error";
        std::cout << "\033[0m" << ": unrecognised flag" << std::endl;
        return 0;
    }
    if (!file && !known) {
        std::cout << "scc - " << colors::green << "Skelly Compiler" << "\033[0m" << ": " ;
        std::cout << colors::red << colors::bold << "error";
        std::cout << "\033[0m" << colors::bold << ": no input files specified" << std::endl;
        return 0;
    }
}