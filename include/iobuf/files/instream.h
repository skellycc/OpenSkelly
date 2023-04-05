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

#ifndef INCLUDE_IOBUF_FILES_INSTREAM_H_
#define INCLUDE_IOBUF_FILES_INSTREAM_H_

#include "../../security/os/compiler_policy.h"
#include "../../security/os/runtime_policy.h"
#include "../../util/strtool.h"
#include "sbuffer.h"
#include <signal.h>

// Read and fetching data
// From input streams, file streams, buffers, etc

// TODO: Operating System Adjustments
// TODO: Security Manager Requests

namespace skelly {
namespace stream {

template<typename BufferType>
class skelly_input_buffer : public skelly_buffer_model {
private:
	skelly_buffer_modes __mode;
	BufferType __buf_t;
public:
	skelly_input_buffer(const skelly_buffer_modes& mode, BufferType buffer) : __mode(mode), __buf_t(buffer) {
		quick_sig_kill();
	}
	~skelly_input_buffer() override {
		this->dump();
		this->flush();
	}
private:
	void quick_kill(int signum) {
		this->dump();
		this->flush();
	}
public:
	void flush() noexcept override {
		switch (this->__mode) {
		case skelly_buffer_modes::READ_FILE || skelly_buffer_modes::RW_FILE: {
			// close it
			__buf_t.close();
			break;
		}
		case skelly_buffer_modes::READ_BUFFER || skelly_buffer_modes::RW_BUFFER: {
			if (__buf_t.heap) {
				__buf_t.chunks.contents.clear();
				delete __buf_t;
			} else {
				__buf_t.chunks.contents.clear();
			}
			break;
		}
		}
	}
	void dump() noexcept override {
		// remove
	}
	std::vector<std::string> read() noexcept {

		return NULL;
	}
	void quick_sig_kill() noexcept override {
		signal(SIGABRT, quick_kill);
		signal(SIGTERM, quick_kill);
	}
};

}
}

#endif /* INCLUDE_IOBUF_FILES_INSTREAM_H_ */
