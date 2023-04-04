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

#ifndef INCLUDE_IOBUF_FILES_SBUFFER_H_
#define INCLUDE_IOBUF_FILES_SBUFFER_H_

namespace skelly {
namespace stream {

	enum class skelly_buffer_modes {
		READ_FILE,
		READ_BUFFER,

		WRITE_FILE,
		WRITE_BUFFER,

		RW_FILE,
		RW_BUFFER
	};

	class skelly_buffer_model {
	public:
		skelly_buffer_model() = default;
		virtual ~skelly_buffer_model() = default;

		skelly_buffer_model(skelly_buffer_model) = default;

		skelly_buffer_model operator = (skelly_buffer_model) = default;
	public:
		virtual void flush() noexcept;
		virtual void dump() noexcept;
		// quick, terminate, just dump and flush
		virtual void quick_sig_kill() noexcept;
	};
}
}

#endif /* INCLUDE_IOBUF_FILES_SBUFFER_H_ */
