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

#ifndef INCLUDE_SECURITY_COMPILER_POLICY_H_
#define INCLUDE_SECURITY_COMPILER_POLICY_H_

#include <vector>
#include <map>
#include <string>

// Setting up security policies for programs
// Requesting and checking permissions with the OS

/*
 * Security Policy Map
 *
 * - Access Control Rules
 * - Input Validation
 * - Networking Validation
 * - Sensitive Key-chain access validation
 * - File System permissions
 */

// NOTE: This service won't actually handle the policy, only validate a policy request is valid
// NOTE: The VM will handle the real implementation of the Policy Requests

namespace skelly {
namespace security {

enum skelly_compile_policy {
	ACCESS = "access",
	INPUT = "input",
	NETWORK_SOCK = "net",
	KEYS = "chains",
	FILE_SYS = "files",
	OTHER_ADMIN_CALLS = "root",
	SYSCALLS = "system"
};

class compiler_policy {
private:
	static std::map<std::string, std::string> __policy; // compiler policy request map service
private:
	explicit compiler_policy() = delete;
	~compiler_policy() = delete;
	compiler_policy operator = (compiler_policy) = delete;
private:
	static bool validate_policy(const std::string& policy_type) noexcept {
		// TODO: Validate the policy request
		return false;
	}
public:
	static void add_policy(const skelly_compile_policy& policy_info, const std::string& policy_value) noexcept {
		__policy[policy_info] = policy_value;
	}
	static bool has_policy(const skelly_compile_policy& policy_info) noexcept {
		if (__policy.find(SKELLY_SECURITY_GET_TYPE(skelly_compile_policy, policy_info))) {
			return true;
		}
		return false;
	}
	static void remove_policy(const skelly_compile_policy& policy_info) noexcept {
		if (has_policy(policy_info)) {
			__policy.erase(__policy.find(policy_info));
		}
	}
	static void write_policy_vm() noexcept {
		// TODO: Finalise and configure the policies for the VM to interpret
		// TODO: Send the policies to the VM (possibly through a memory block write)
	}
};

}
}

#endif /* INCLUDE_SECURITY_COMPILER_POLICY_H_ */
