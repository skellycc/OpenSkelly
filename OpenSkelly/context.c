//
//  context.c
//  OpenSkelly
//
//  Created by Mustafa Malik on 19/12/2023.
//

#include "context.h"
#include <mach-o/dyld.h>

int sk_cur_path(char* buf) {
    uint32_t size = sizeof(buf);
    if (_NSGetExecutablePath(buf, &size) == 0) {
        return 1;
    }
    return 0;
}
